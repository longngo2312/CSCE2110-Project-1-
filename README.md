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
git clone https://github.com/longngo2312/CSCE2110-Project-1-.git
cd CSCE2110-Project-1-
```

> Replace `YOUR-USERNAME` with the actual GitHub username of the repo owner.

---

## Git Workflow (Required)

> **Rule: Nobody pushes directly to `main`.** All changes go through a Pull Request.

### Step-by-Step Workflow

#### 1. Pull the latest `main` before starting work
```bash
git checkout main
git pull origin main
```

#### 2. Create a feature branch
```bash
git checkout -b your-branch-name
```
**Branch naming convention:**
| Prefix | Use for | Example |
|--------|---------|---------|
| `feature/` | New functionality | `feature/linked-list` |
| `fix/` | Bug fixes | `fix/memory-leak` |
| `test/` | Adding tests | `test/insert-tests` |
| `docs/` | Documentation | `docs/update-readme` |

#### 3. Do your work — stage and commit often
```bash
git status                  # See what changed
git add src/main.cpp        # Stage specific files (preferred)
git commit -m "Add linked list insert function"
```
Write meaningful commit messages:
- Good: `"Add linked list insert function"`, `"Fix segfault in delete operation"`
- Bad: `"stuff"`, `"fixed it"`, `"asdfgh"`

#### 4. Push your branch to GitHub
```bash
git push -u origin your-branch-name
```
The `-u` flag links your local branch to the remote so future pushes only need `git push`.

#### 5. Open a Pull Request on GitHub
1. Go to the repo: https://github.com/longngo2312/CSCE2110-Project-1-
2. Click **"Compare & pull request"** (GitHub shows a banner after you push)
3. Write a clear title and description of what you changed
4. Request at least **1 teammate** as a reviewer
5. Wait for approval, then click **"Merge pull request"**
6. Delete the remote branch when prompted

#### 6. Clean up after merge
```bash
git checkout main
git pull origin main
git branch -d your-branch-name          # Delete local branch
```

---

### Keeping Your Branch Up to Date

If `main` has been updated while you're working on your branch:
```bash
git checkout your-branch-name
git pull origin main
```
Resolve any conflicts, then commit and push.

---

### Handling Merge Conflicts

If two people edit the same lines, Git will flag a conflict:
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
| `git add <file>` | Stage a specific file |
| `git commit -m "msg"` | Save changes with a message |
| `git checkout -b <name>` | Create a new branch and switch to it |
| `git checkout <name>` | Switch to an existing branch |
| `git push -u origin <branch>` | Push your branch to GitHub |
| `git pull origin main` | Update your branch with latest main |
| `git branch -d <name>` | Delete a local branch after merge |
| `git log --oneline` | See commit history (compact) |
| `git diff` | See unstaged changes |
| `git stash` / `git stash pop` | Temporarily save/restore uncommitted work |

---

## Team Rules
- **Always** work on a branch — never commit directly to `main`
- **Always** pull `main` before creating a new branch
- **Always** open a Pull Request to merge into `main`
- **At least 1 reviewer** must approve before merging
- **Never** push `.exe`, `.o`, or other compiled files (`.gitignore` handles this)
- **Communicate** if you're working on the same file as someone else

---

## Setting Up Branch Protection (Repo Owner)

To enforce this workflow, the repo owner should enable branch protection on GitHub:

1. Go to **Settings → Branches** in the GitHub repo
2. Click **Add branch ruleset** (or "Add rule" for classic protection)
3. Set **Branch name pattern** to `main`
4. Enable these settings:
   - **Require a pull request before merging**
   - **Require approvals** (set to 1)
   - **Do not allow bypassing the above settings** (optional but recommended)
5. Click **Create** / **Save changes**

This prevents anyone (including the owner) from pushing directly to `main`.
