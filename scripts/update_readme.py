from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
README = ROOT / "README.md"

LC_DIR = ROOT / "LeetCode"
GFG_DIR = ROOT / "GFG"


def count_problem_folders(path: Path) -> int:
    """Count only directories (each directory = one problem)."""
    if not path.exists():
        return 0
    return sum(1 for item in path.iterdir() if item.is_dir())


# ---------- LeetCode ----------
lc_easy = count_problem_folders(LC_DIR / "Easy")
lc_medium = count_problem_folders(LC_DIR / "Medium")
lc_hard = count_problem_folders(LC_DIR / "Hard")

lc_total = lc_easy + lc_medium + lc_hard

# ---------- GeeksforGeeks ----------
gfg_basic = count_problem_folders(GFG_DIR / "Basic")
gfg_easy = count_problem_folders(GFG_DIR / "Easy")
gfg_medium = count_problem_folders(GFG_DIR / "Medium")
gfg_hard = count_problem_folders(GFG_DIR / "Hard")

gfg_total = gfg_basic + gfg_easy + gfg_medium + gfg_hard

# ---------- Overall ----------
overall = lc_total + gfg_total
overall_easy = lc_easy + gfg_easy
overall_medium = lc_medium + gfg_medium
overall_hard = lc_hard + gfg_hard

# ---------- Badges ----------
badges = f"""![C++](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![LeetCode](https://img.shields.io/badge/LeetCode-{lc_total}%20Solved-orange?style=for-the-badge&logo=leetcode)
![GeeksforGeeks](https://img.shields.io/badge/GeeksforGeeks-{gfg_total}%20Solved-darkgreen?style=for-the-badge&logo=geeksforgeeks)
![Total Problems](https://img.shields.io/badge/Total-{overall}%20Problems-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)
"""

# ---------- Statistics Table ----------
table = f"""| Platform | Total | Basic | Easy | Medium | Hard |
|:---------|------:|------:|-----:|-------:|-----:|
| **LeetCode** | **{lc_total}** | — | **{lc_easy}** | **{lc_medium}** | **{lc_hard}** |
| **GeeksforGeeks** | **{gfg_total}** | **{gfg_basic}** | **{gfg_easy}** | **{gfg_medium}** | **{gfg_hard}** |
| **Overall** | **{overall}** | **{gfg_basic}** | **{overall_easy}** | **{overall_medium}** | **{overall_hard}** |
"""

content = README.read_text(encoding="utf-8")

content = re.sub(
    r"<!-- BADGES_START -->.*?<!-- BADGES_END -->",
    f"<!-- BADGES_START -->\n{badges}\n<!-- BADGES_END -->",
    content,
    flags=re.DOTALL,
)

content = re.sub(
    r"<!-- STATS_START -->.*?<!-- STATS_END -->",
    f"<!-- STATS_START -->\n{table}\n<!-- STATS_END -->",
    content,
    flags=re.DOTALL,
)

# ---------- Highlights Total ----------
highlights_total = f"• 📚 **{overall}** curated Data Structures & Algorithms solutions."

content = re.sub(
    r"<!-- HIGHLIGHTS_TOTAL_START -->.*?<!-- HIGHLIGHTS_TOTAL_END -->",
    f"<!-- HIGHLIGHTS_TOTAL_START -->\n{highlights_total}\n<!-- HIGHLIGHTS_TOTAL_END -->",
    content,
    flags=re.DOTALL,
)

README.write_text(content, encoding="utf-8")

print("README statistics updated successfully.")