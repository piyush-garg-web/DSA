
const fs = require('fs');
const path = require('path');

function processReadme(filePath) {
  try {
    const content = fs.readFileSync(filePath, 'utf8');
    const lines = content.split(/\r?\n/);

    let problemName = null;
    let problemLink = null;
    let problemStatement = [];
    let inProblemStatement = false;

    // Find problem name (first line starting with #)
    for (const line of lines) {
      const trimmed = line.trim();
      if (trimmed.startsWith('# ')) {
        problemName = trimmed.slice(2).trim();
        break;
      }
    }

    // Find problem link
    for (const line of lines) {
      const trimmed = line.trim();
      if (trimmed.startsWith('Problem Link:')) {
        problemLink = trimmed.slice('Problem Link:'.length).trim();
        break;
      }
    }

    // Find problem statement
    for (const line of lines) {
      const trimmed = line.trim();
      if (trimmed === '## Problem Statement') {
        inProblemStatement = true;
        continue;
      }
      if (inProblemStatement) {
        if (trimmed.startsWith('## ') || trimmed === '---') {
          break;
        }
        problemStatement.push(line);
      }
    }

    // Clean up problem statement
    const cleanProblemStatement = problemStatement.join('\n').trim();

    if (!problemName || !cleanProblemStatement || !problemLink) {
      console.warn(`Warning: Missing sections in ${filePath}`);
      return false;
    }

    // Create new content
    const newContent = `# ${problemName}

## Problem Statement

${cleanProblemStatement}

## Problem Link
${problemLink}
`;

    // Check if already correct
    if (content.trim() === newContent.trim()) {
      return false;
    }

    // Write back
    fs.writeFileSync(filePath, newContent, 'utf8');
    return true;
  } catch (err) {
    console.error(`Error processing ${filePath}:`, err);
    return false;
  }
}

function main() {
  const repoRoot = path.dirname(path.dirname(__filename));
  let totalScanned = 0;
  let totalModified = 0;
  let totalSkipped = 0;

  function walkDirectory(dir) {
    const files = fs.readdirSync(dir);
    for (const file of files) {
      const filePath = path.join(dir, file);
      const stat = fs.statSync(filePath);
      if (stat.isDirectory()) {
        walkDirectory(filePath);
      } else if (file === 'README.md') {
        if (filePath === path.join(repoRoot, 'README.md')) {
          // Skip root README.md
          totalSkipped++;
          totalScanned++;
          continue;
        }
        totalScanned++;
        const modified = processReadme(filePath);
        if (modified) {
          totalModified++;
        } else {
          totalSkipped++;
        }
      }
    }
  }

  walkDirectory(repoRoot);

  console.log(`Total README files scanned: ${totalScanned}`);
  console.log(`Total README files modified: ${totalModified}`);
  console.log(`Total README files skipped: ${totalSkipped}`);
}

main();
