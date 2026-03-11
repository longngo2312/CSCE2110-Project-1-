# CSCE 2110 - Project 1

## Team Members
|  Name  | GitHub Username |
|--------|-----------------|
|Jack Ngo|                 |
|Taha Hak|                 |
|Ryan Bro|                 |
|Ryan Ols|                 |

---

## Project Structure

```
CSCE2110-Project-1-/
├── src/            # Source files (.cpp)
├── include/        # Header files (.h / .hpp)
├── tests/          # Test files
├── data/           # Input/output data files
├── docs/           # Project documentation, assignment specs
├── Makefile        # Build instructions
├── .gitignore      # Files Git should ignore
└── README.md       # This file
```

---

## Getting Started

### Prerequisites
- **Git** installed ([Download Git](https://git-scm.com/downloads))
- **g++** compiler (Linux/Mac) or **MinGW/MSYS2** (Windows)
- A terminal (Git Bash on Windows works great)

### 1. Clone the Repository

This downloads the project to your computer for the first time:

```bash
git clone https://github.com/YOUR-USERNAME/CSCE2110-Project-1-.git
cd CSCE2110-Project-1-
```

> Replace `YOUR-USERNAME` with the actual GitHub username of the repo owner.

---

## Git Workflow Guide

### The Basics You Need to Know

#### Check the status of your files
```bash
git status
```
This shows you what files have been changed, added, or are untracked.

#### Pull the latest changes (DO THIS BEFORE YOU START WORKING)
```bash
git pull origin main
```
**Always pull before you start coding.** This grabs the latest code from GitHub so you don't run into conflicts.

#### Stage your changes
```bash
# Add a specific file
git add src/main.cpp

# Add all changed files
git add .
```

#### Commit your changes
```bash
git commit -m "Short description of what you changed"
```
Write meaningful commit messages. Examples:
- `"Add linked list insert function"`
- `"Fix segfault in delete operation"`
- `"Add input parsing from file"`

Bad examples:
- `"stuff"`
- `"fixed it"`
- `"asdfgh"`

#### Push your changes to GitHub
```bash
git push origin main
```

---

### Branching (Recommended Workflow)

Branches let you work on features without breaking the main code.

#### Create a new branch
```bash
git checkout -b your-branch-name
```
Name it something descriptive like `feature/linked-list` or `fix/memory-leak`.

#### Switch between branches
```bash
# Switch to an existing branch
git checkout main
git checkout your-branch-name
```

#### Push your branch to GitHub
```bash
git push origin your-branch-name
```

#### Merge your branch into main
First, switch to main and pull the latest:
```bash
git checkout main
git pull origin main
```
Then merge your branch:
```bash
git merge your-branch-name
```
Then push:
```bash
git push origin main
```

#### Delete a branch after merging
```bash
# Delete locally
git branch -d your-branch-name

# Delete on GitHub
git push origin --delete your-branch-name
```

---

### Pull Requests (PR) - The Safest Way to Merge

Instead of merging directly, use Pull Requests on GitHub. This lets the team review code before it goes into main.

**Steps:**
1. Push your branch to GitHub: `git push origin your-branch-name`
2. Go to the repo on GitHub
3. Click **"Compare & pull request"** (GitHub usually shows a banner)
4. Write a title and description of what you changed
5. Assign a teammate to review
6. Once approved, click **"Merge pull request"**

---

### Handling Merge Conflicts

If two people edit the same lines, Git will flag a conflict. You'll see something like:

```
<<<<<<< HEAD
your code
=======
their code
>>>>>>> branch-name
```

**To resolve:**
1. Open the file and decide which code to keep (or combine both)
2. Remove the `<<<<<<<`, `=======`, and `>>>>>>>` markers
3. Stage and commit the resolved file:
   ```bash
   git add the-conflicted-file.cpp
   git commit -m "Resolve merge conflict in the-conflicted-file.cpp"
   ```

---

## Building the Project

### Using g++ directly
```bash
g++ -std=c++17 -Wall -Iinclude src/*.cpp -o main
```

### Using Make (once Makefile is set up)
```bash
make          # Build the project
make clean    # Remove compiled files
make run      # Build and run (if configured)
```

### Running the program
```bash
./main
# or with input file:
./main < data/input.txt
```

---

## Quick Reference Cheat Sheet

| Command | What it does |
|---------|-------------|
| `git clone <url>` | Download the repo for the first time |
| `git status` | See what files changed |
| `git pull origin main` | Get latest changes from GitHub |
| `git add .` | Stage all changes |
| `git add <file>` | Stage a specific file |
| `git commit -m "msg"` | Save changes with a message |
| `git push origin main` | Upload commits to GitHub |
| `git checkout -b <name>` | Create and switch to a new branch |
| `git checkout <name>` | Switch to an existing branch |
| `git merge <branch>` | Merge a branch into current branch |
| `git log --oneline` | See commit history (compact) |
| `git diff` | See unstaged changes |
| `git stash` | Temporarily save uncommitted changes |
| `git stash pop` | Restore stashed changes |

---

## Team Rules (Fill these in together)
- [ ] How often do we push/pull? (e.g., at least once a day)
- [ ] Do we use branches or push straight to main?
- [ ] Who reviews pull requests?
- [ ] How do we split up the work?

---

## Notes
- **Never** push `.exe`, `.o`, or other compiled files (`.gitignore` handles this)
- **Always** pull before you start working
- **Communicate** if you're working on the same file as someone else
- When in doubt, make a branch
