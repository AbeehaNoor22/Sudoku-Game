# Sudoku-Game 
C++ code for sudoku interactive console based puzzle game.
## Team Information
**Team Members:**
- **Abeeha Noor** – Programmer 1; Made base code, added different functions, made README, did part of formatting.
- **Aliza Batool** – Programmer 2; Made modifications, added different functions, did part of formatting and documentation.
- **Fatima Zahra Mustapha** – --

## Problem Description
Sudoku Game is an interactive, console-based number puzzle where you must complete a 9×9 Sudoku grid using logic, hints, and careful moves. Each game generates a new randomized board with adjustable difficulty levels.
Your objective is to fill all empty cells correctly before you run out of lives.

## How to Play
1. Compile and run the program using any C++ compiler.
2. The game starts with a welcome message.
3. Choose your difficulty:
* Press 1 → *Easy*
* Press 2 → *Medium*
* Press 3 → *Hard*
4. A partially filled Sudoku grid will be displayed.
5. During gameplay, use the following commands:
* m → Make a move
* h → Use a hint (maximum 3)
* c → Check your current entries against the solution
* s → Reveal the complete solution and end the game
6. When making a move:
* Enter row, column, and number
* Enter 0 as the number to undo a previous move
7. The game ends when:
* You completely solve the grid (Win)
* You reveal the entire solution
* Your lives drop to 0 (Lose)

## Lives / Hint System
#### Starting Lives
* You begin the game with 5 lives
#### Hints
* Total hints available: 3
* Hints can only be used on empty cells
#### Life Rules
* Invalid move → Lose 1 life
* Correct move → No life penalty
* Original fixed cells cannot be changed

## Features
* Randomly generated Sudoku boards
* Multiple difficulty levels: Easy, Medium, Hard
* Move validation
* Undo move option
* Automatic checking against the correct solution
* Hint system
* Full board solver
* Win detection
* Modular and structured code design

## Modular Programming Structure
The program is organized into the following major functions:
#### Board Generation
* <is_valid()> — Checks if a number respects Sudoku rules
* <remove_cells()> — Removes cells based on chosen difficulty
* <sudoku()> — Main game controller
#### Gameplay Functions
* <print_initial_board()> — Displays the Sudoku grid
* <input()> — Handles move input and validity checks
* <hint()> — Gives the correct value for one selected cell
* <checker()> — Verifies user inputs against the solution
* <solver()> — Shows the complete solved board
* <win()> — Confirms if the current board matches the solution

## AI tool reflection
### AI Tools Used:
ChatGPT
### Tasks Assisted:
- Provided error-handling ideas for invalid input (cin.fail() concept).
- Suggested better documentation format.
- Guidance on flow of program
### Reflection:
- Learned about input validation and error handling.
- Learned how to implement better programming practices.

## Future improvements
The code can be enhanced by including a GUI which will make the user interaction more captivating and will make the game more lively to play.