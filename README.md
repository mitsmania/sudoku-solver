# Killer Sudoku Solver (C + Raylib)

## Overview

This project is a Killer Sudoku solver implemented in C with two interfaces:

* **GUI Mode** using Raylib for interactive puzzle creation and solving
* **Terminal Mode** for file-based input and step-by-step solving with debug logs

Both modes share a common backend solver based on backtracking with cage constraints.

---

## Features

* Create custom Killer Sudoku puzzles using GUI
* Solve puzzles instantly or step-by-step (terminal debug mode)
* Support for cage constraints (sum-based regions)
* Clean modular structure with reusable solver logic
* Multiple execution modes via a launcher

---

## Project Structure

```
sudoku-solver/
│
├── launcher.c          # Entry point (mode selection)
├── Makefile            # Build automation
├── .gitignore
│
└── source_code/
    ├── gui.c           # GUI implementation (Raylib)
    ├── grid.c          # Grid initialization and display
    ├── f_all.c         # Terminal solver
    ├── solver.c        # Backtracking solver
    ├── validator.c     # Sudoku constraints
    ├── cage.c          # Cage structures
    ├── cage_rules.c    # Cage validation logic
    ├── parser.c        # File input parser
    └── headers (.h)
```

---

## Build Instructions

### Prerequisites

Before building, make sure you have the following installed:

* **GCC** (C compiler)
* **Raylib** — required for GUI mode
  * Windows: Download from [https://www.raylib.com](https://www.raylib.com) and follow setup instructions
  * Linux: `sudo apt install libraylib-dev`
  * Mac: `brew install raylib`

### Using Makefile (recommended)

```
make
```

### Manual compilation (optional)

GUI:

```
gcc source_code/gui.c source_code/grid.c source_code/solver.c source_code/validator.c source_code/cage.c source_code/cage_rules.c -o gui_app -lraylib -lopengl32 -lgdi32 -lwinmm
```

Terminal:

```
gcc source_code/f_all.c source_code/grid.c source_code/solver.c source_code/validator.c source_code/cage.c source_code/cage_rules.c source_code/parser.c -o terminal_app
```

Launcher:

```
gcc launcher.c -o launcher
```

---

## Running the Project

Run the launcher:

```
./launcher
```

Choose mode:

* `1` → Terminal Mode
* `2` → GUI Mode

---

## Terminal Mode

* Supports manual or file input
* Displays solving steps (debug mode enabled)
* Example input file path:

```
source_code/input.txt
```

---

## GUI Mode

* Draw cages interactively
* Assign sums
* Press `S` to solve
* Displays solution visually on grid

---

## Debug Mode

* Enabled in terminal mode
* User Controlled:

```
prompted to choose:
    -> 1 for enabling debug control
    -> 0 for disabling debug control
```

* GUI runs with debug disabled for clean output

---

## Technologies Used

* C (core logic)
* Raylib (GUI rendering)
* Makefile (build system)

---

## Future Improvements

* Puzzle generator
* Difficulty levels
* Save/load puzzles from GUI
* Animated solving visualization

---

## Authors

| Name | Roll No. | Contribution |
|------|----------|--------------|
| Busa Srinivas | B25EE1010 | Cage structures (cage.c), terminal input handling (f_all.c) |
| Sourav Mallick | B25ME1079 | Parser (parser.c), backtracking solver (solver.c) |
| S Mithush Kumar | B25PH1012 | Launcher, Makefile, cage_rules.c, conflict resolution & integration |
| Mohammad Zeba | B25CS1041 | GUI interface (gui.c), grid initialization (grid.c), debugging |
| Varri Sushmitha | B25ME1087 | Sudoku rule validation, terminal input conditions (f_all.c) |
| Sweccha Eldhas | B25EE1014 | Step-by-step solve printing, number validation (validator.c) |

---
