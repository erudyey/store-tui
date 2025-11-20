# Alfamart Store TUI

This is a C++ Terminal User Interface (TUI) app that mimics an Alfamart store.

I know we haven't covered everything in this code during our lessons yet. You'll see things like `std::vector` and Classes here. I used them because they make the code a lot cleaner and easier to manage than using standard fixed-size arrays. It's good practice for what we'll see in the real world, too.

If you're wondering why I did things this way, check out the **[Design Document](design_doc.md)**.

## Project Overview

The goal is to build a simulation where a user can:
- **Browse** a list of real-world items (Coke, Piattos, Cornetto).
- **Navigate** using WASD keys.
- **Add to Cart** and manage quantities.
- **Checkout** with a detailed receipt including VAT.
- **Admin Mode**: Update stock levels (Press SPACE at the start screen).

## Building and Running
Please refer to **[SETUP.md](SETUP.md)** for detailed instructions on how to set up your environment and build the project on Windows, macOS, and Linux.

**Quick Start (Windows):**
```powershell
.\build.ps1
```

## Documentation & Learning Resources
I wrote detailed guides to help you understand the code:

- **[Design Document](design_doc.md)**: Explains the architecture (The "Brain", "Face", and "Controller") and why I made certain design choices.
- **[Concepts Guide](CONCEPTS.md)**: Explains the new C++ concepts I used (Vectors, Struct vs Class, Header files) in simple, beginner-friendly terms.

## Concepts Overview
Here is a quick list of what I used. Check [CONCEPTS.md](CONCEPTS.md) for the full explanation!
- **`std::vector`**: A dynamic array that can grow.
- **`struct` vs `class`**: Grouping data vs Grouping data + behavior.
- **`<conio.h>`**: For instant keyboard input (WASD controls).
- **`iomanip`**: For formatting the receipt (currency, decimals).

## Git Collaboration Guide

### 1. Getting Started
Clone the repository:
```bash
git clone https://github.com/erudyey/store-tui.git
cd store-tui
```

### 2. Working on a New Feature
Never work directly on the `master` branch. Always create a new branch for your changes:
```bash
# Create and switch to a new branch
git checkout -b my-new-feature
```
*Example branch names: `add-product-class`, `fix-login-bug`, `update-readme`*

### 3. Saving Your Changes
Once you have made edits:
```bash
# See which files changed
git status

# Stage the files you want to save
git add <filename>
# OR stage all changes (use carefully)
git add .

# Commit the changes with a message
git commit -m "Added Product class header and implementation"
```

### 4. Sharing Your Changes
Push your branch to GitHub:
```bash
git push origin my-new-feature
```

### 5. Merging to Master
Go to the GitHub repository page. You should see a prompt to "Compare & pull request".
- Click "Create Pull Request".
- Describe what you did.
- Ask a team member to review your code.
- Once approved, merge it into `master`.

### 6. Keeping Up to Date
Before starting new work, always get the latest changes from others:
```bash
git checkout master
git pull origin master
```
