
const fs = require('fs');
const path = require('path');

function decodeHtmlEntities(text) {
    return text
        .replace(/&nbsp;/g, ' ')
        .replace(/&lt;/g, '<')
        .replace(/&gt;/g, '>')
        .replace(/&quot;/g, '"')
        .replace(/&amp;/g, '&')
        .replace(/&#39;/g, "'")
        .replace(/&#x27;/g, "'");
}

function extractFromLeetCodeReadme(htmlContent) {
    // Extract problem name and link
    const nameLinkMatch = htmlContent.match(/<h2><a href="([^"]+)">([^<]+)<\/a><\/h2>/);
    const problemLink = nameLinkMatch ? nameLinkMatch[1] : null;
    let problemName = nameLinkMatch ? nameLinkMatch[2].trim() : "Unknown Problem";
    problemName = problemName.replace(/^\d+\.\s*/, '');
    
    // Extract problem statement (everything after the <hr> tag)
    const hrIndex = htmlContent.indexOf('<hr>');
    let problemStatement = '';
    if (hrIndex !== -1) {
        problemStatement = htmlContent.slice(hrIndex + 4);
        
        // Now strip HTML tags and decode entities from the statement
        problemStatement = problemStatement
            .replace(/<[^>]+>/g, '')
            .trim();
        
        problemStatement = decodeHtmlEntities(problemStatement);
    }
    
    return { problemName, problemLink, problemStatement };
}

function extractFromGfgReadme(content, directoryName) {
    // Infer problem name from directory name
    const problemName = directoryName
        .split('-')
        .map(word => word.charAt(0).toUpperCase() + word.slice(1))
        .join(' ');
    
    const problemLink = null; // GFG links usually not in readmes
    
    // Clean up the problem statement by removing the first line if it's a difficulty
    const lines = content.trim().split('\n');
    let problemStatement = content.trim();
    if (lines.length > 0 && ['basic', 'easy', 'medium', 'hard'].includes(lines[0].trim().toLowerCase())) {
        problemStatement = lines.slice(1).join('\n').trim();
    }
    
    return { problemName, problemLink, problemStatement };
}

function analyzeCppSolution(cppPath) {
    let content;
    try {
        content = fs.readFileSync(cppPath, 'utf-8');
    } catch {
        return { timeComplexity: "O(n)", spaceComplexity: "O(1)", topics: [] };
    }
    
    const topics = [];
    let timeComplexity = "O(n)";
    let spaceComplexity = "O(1)";
    
    // Define more specific checks for each topic
    const topicChecks = [
        { 
            topic: 'Array', 
            check: () => /\b(vector|array)\b/.test(content) 
        },
        { 
            topic: 'String', 
            check: () => /\b(string|std::string)\b/.test(content) 
        },
        { 
            topic: 'Hash Map', 
            check: () => /\b(unordered_map|unordered_set|map|set)\b/.test(content) 
        },
        { 
            topic: 'Binary Search', 
            check: () => /\b(binary|search|mid\s*=|low|high)\b/.test(content) 
        },
        { 
            topic: 'Two Pointers', 
            check: () => /\b(two\s*pointer|left|right)\b/.test(content) 
        },
        { 
            topic: 'Sliding Window', 
            check: () => /\b(sliding\s*window)\b/.test(content) 
        },
        { 
            topic: 'Stack', 
            check: () => /\b(stack|std::stack)\b/.test(content) 
        },
        { 
            topic: 'Queue', 
            check: () => /\b(queue|std::queue|deque|std::deque)\b/.test(content) 
        },
        { 
            topic: 'Linked List', 
            check: () => /\b(LinkedList|ListNode)\b/.test(content) 
        },
        { 
            topic: 'Tree', 
            check: () => /\b(TreeNode|BinaryTree)\b/.test(content) 
        },
        { 
            topic: 'BST', 
            check: () => /\b(BST)\b/.test(content) 
        },
        { 
            topic: 'Heap', 
            check: () => /\b(priority_queue|heap)\b/.test(content) 
        },
        { 
            topic: 'Graph', 
            check: () => /\b(graph|adj)\b/.test(content) 
        },
        { 
            topic: 'DFS', 
            check: () => /\b(dfs|DFS)\b/.test(content) 
        },
        { 
            topic: 'BFS', 
            check: () => /\b(bfs|BFS)\b/.test(content) 
        },
        { 
            topic: 'Dynamic Programming', 
            check: () => /\b(dp|DP|dynamic|programming)\b/.test(content) 
        },
        { 
            topic: 'Greedy', 
            check: () => /\b(greedy)\b/.test(content) 
        },
        { 
            topic: 'Backtracking', 
            check: () => /\b(backtrack|Backtrack)\b/.test(content) 
        },
        { 
            topic: 'Recursion', 
            check: () => /\b(recursive|Recursive)\b/.test(content) 
        },
        { 
            topic: 'Trie', 
            check: () => /\b(Trie)\b/.test(content) 
        },
        { 
            topic: 'Prefix Sum', 
            check: () => /\b(prefix\s*sum)\b/i.test(content) 
        },
        { 
            topic: 'Math', 
            check: () => /\b(math|Math|sqrt|pow)\b/.test(content) 
        }
    ];
    
    topicChecks.forEach(({ topic, check }) => {
        if (check()) {
            topics.push(topic);
        }
    });
    
    return { timeComplexity, spaceComplexity, topics };
}

function processDirectory(directory) {
    const readmePath = path.join(directory, 'README.md');
    const files = fs.readdirSync(directory);
    const cppFiles = files.filter(f => f.endsWith('.cpp'));
    const directoryName = path.basename(directory);
    
    if (!fs.existsSync(readmePath) || cppFiles.length === 0) {
        return false;
    }
    
    const cppPath = path.join(directory, cppFiles[0]);
    
    const readmeContent = fs.readFileSync(readmePath, 'utf-8');
    const isLeetCode = directory.toLowerCase().includes('leetcode');
    
    let extracted;
    if (isLeetCode) {
        extracted = extractFromLeetCodeReadme(readmeContent);
    } else {
        extracted = extractFromGfgReadme(readmeContent, directoryName);
    }
    
    const { timeComplexity, spaceComplexity, topics } = analyzeCppSolution(cppPath);
    
    const readmeParts = [`# ${extracted.problemName}\n`];
    if (extracted.problemLink) {
        readmeParts.push(`\nProblem Link: ${extracted.problemLink}\n`);
    }
    readmeParts.push('\n---\n');
    readmeParts.push('\n## Problem Statement\n');
    readmeParts.push(`\n${extracted.problemStatement}\n`);
    readmeParts.push('\n---\n');
    readmeParts.push('\n## Complexity Analysis\n');
    readmeParts.push(`\n**Time Complexity:** ${timeComplexity}\n`);
    readmeParts.push(`**Space Complexity:** ${spaceComplexity}\n`);
    readmeParts.push('\n---\n');
    readmeParts.push('\n## Topics\n');
    topics.forEach(topic => {
        readmeParts.push(`- ${topic}\n`);
    });
    
    fs.writeFileSync(readmePath, readmeParts.join(''), 'utf-8');
    return true;
}

function main() {
    const root = path.resolve(__dirname);
    const leetcodeDir = path.join(root, 'LeetCode');
    const gfgDir = path.join(root, 'GFG');
    
    let count = 0;
    
    // Process LeetCode
    ['Easy', 'Medium', 'Hard'].forEach(difficulty => {
        const difficultyDir = path.join(leetcodeDir, difficulty);
        if (fs.existsSync(difficultyDir)) {
            fs.readdirSync(difficultyDir).forEach(problemDir => {
                const fullPath = path.join(difficultyDir, problemDir);
                if (fs.statSync(fullPath).isDirectory()) {
                    if (processDirectory(fullPath)) {
                        count++;
                    }
                }
            });
        }
    });
    
    // Process GFG
    ['Basic', 'Easy', 'Medium', 'Hard'].forEach(difficulty => {
        const difficultyDir = path.join(gfgDir, difficulty);
        if (fs.existsSync(difficultyDir)) {
            fs.readdirSync(difficultyDir).forEach(problemDir => {
                const fullPath = path.join(difficultyDir, problemDir);
                if (fs.statSync(fullPath).isDirectory()) {
                    if (processDirectory(fullPath)) {
                        count++;
                    }
                }
            });
        }
    });
    
    console.log(`Successfully processed ${count} README.md files!`);
}

main();
