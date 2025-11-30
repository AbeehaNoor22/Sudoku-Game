#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//FUNCTION PROTOTYPES
bool is_valid(int, int, int, int[][9]);
void remove_cells(int[][9]);
void sudoku(int&);
void print_initial_board(int[][9]);
void input(int, int, int, int[][9], int[][9], int& lives);
bool hint(int, int, int[][9], int[][9]);
void checker(int[][9], int[][9]);
void solver(int[][9], int[][9]);
bool win(int[][9], int[][9]);

//MAIN
int main() {
    int lives = 5;
    sudoku(lives);
    system("pause");
}

//FUNCTION DEFINITIONS

//main sudoku game function
void sudoku(int& lives) {
    int array1[9][9], array[9][9], row, col, numb, num, attempts, hints = 3, roww, coll;
    char flow;
    srand(time(0));
    cout << "====== WELCOME TO SUDOKU GAME ======\n\n";

    // initialize with zeros
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            array1[i][j] = 0;

    // fill board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            attempts = 0;
            num;

            while (true) {
                num = rand() % 9 + 1;
                attempts++;
                // if too many failed attempts reset row
                if (attempts > 10) {
                    for (int c = 0; c < 9; c++)
                        array1[i][c] = 0;
                    j = -1;   // restart row (loop will ++j = 0)
                    break;
                }

                if (is_valid(i, j, num, array1)) {
                    array1[i][j] = num;
                    break;
                }
            }
        }
    }
    //storing the original array
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            array[i][j] = array1[i][j];
        }
    }
    remove_cells(array);
    print_initial_board(array);
    //taking input for input funtion
    while (lives > 0) {
        cout << "Lives remaining = " << lives << endl;
        cout << "Hints remaining = " << hints << endl;
        cout << "Enter \n-->'m' to make the next move\n-->'h' to get hint\n-->'c' to check whether the current elements match the original solution\n-->'s' for complete solution\n";
        cin >> flow;
        if (flow == 'm') {
            cout << "Enter the row, column and number\n";
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
            cout << "Number: ";
            cin >> numb;
            input(row - 1, col - 1, numb, array, array1, lives);
            //check win
            if (win(array, array1)) {
                print_initial_board(array);
                cout << "\nYou won! You did the correct solution!\n";
                break;
            }
            print_initial_board(array);
        }

        else if (flow == 'h') {
            if (hints > 0) {
                cout << "Enter the row, column where the hint is required\n";
                cout << "Row: ";
                cin >> roww;
                cout << "Column: ";
                cin >> coll;
                bool used = hint(roww - 1, coll - 1, array, array1);
                if (used == 1) {
                    hints--;
                }
            }
            else {
                cout << "No hints left!\n";
            }
            //check win
            if (win(array, array1)) {
                print_initial_board(array);
                cout << "\nYou won! You did the correct solution!\n";
                break;
            }
            print_initial_board(array);
        }
        else if (flow == 'c') {
            checker(array, array1);
            print_initial_board(array);
        }
        else if (flow == 's') {
            solver(array, array1);
            print_initial_board(array);
            break;
        }
    }
        //if lives end
        if (lives == 0) {
            cout << "\nYou lost!The solution of this board was:\n\n";
            print_initial_board(array1);
        }
    
}

//function that initially removes cells for board generation
void remove_cells(int array[][9]) {
    int choice, target, removed = 0;
    cout << "Choose the difficulty level:\n\n1--> Easy\n2--> Medium\n3--> Hard\n";
    cin >> choice;
    switch (choice) {
    case 1:
        target = 40;
        break;
    case 2:
        target = 50;
        break;
    case 3:
        target = 60;
        break;
    default:
        cout << "Invalid choice, defaulting to Easy.\n";
        target = 40;
    }
    while (removed <= target) {
        int k = rand() % 9;
        int l = rand() % 9;
        if (array[l][k] != 0) {
            array[l][k] = 0;
            removed++;
        }
    }
}

//function to check whether the element is valid acc to sudoku rules or not
bool is_valid(int i, int j, int num, int array[][9]) {

    // check row
    for (int k = 0; k < 9; k++) {
        if (array[i][k] == num) return false;
    }

    // check column
    for (int k = 0; k < 9; k++) {
        if (array[k][j] == num) return false;
    }

    // check subgrid
    int startrow = i - (i % 3);
    int startcol = j - (j % 3);

    for (int r = startrow; r < startrow + 3; r++) {
        for (int c = startcol; c < startcol + 3; c++) {
            if (array[r][c] == num) return false;
        }
    }
    return true;
}

//printing board function
void print_initial_board(int array[][9]) {
    cout << "* == == ==  * == == ==  * == == ==  *\n";
    for (int i = 0; i < 9; i++) {
        cout << "| ";
        for (int j = 0; j < 9; j++) {
            if (array[i][j] == 0) {
                cout << "   ";
            }
            else {
                cout << " " << array[i][j] << " ";
            }
            if ((j + 1) % 3 == 0) cout << "|| ";

        }
        cout << "\n";
        if ((i + 1) % 3 == 0)
            cout << "* == == ==  * == == ==  * == == ==  *\n";
    }
}

//input function
void input(int row, int col, int num, int array[9][9], int array1[][9], int& lives) {
    if (row >= 0 && row < 9 && col >= 0 && col < 9 && num <= 9 && num >= 1) {
        if (num != 0) {
            bool check = is_valid(row, col, num, array);
            //added input validation for already filled cells
            if (array[row][col] != 0) {
                cout << "You cannot change original fixed numbers!\n";
                return; // exits function immediately
            }
            else {
                array[row][col] = num;
            }

            if (!check) {
                cout << "The number is not valid here.\n";
                cout << "Enter row, column,0 to undo your current move.\n";
                lives--;
                cout << "The board after this move is:\n";
            }
            else if (check && num != array1[row][col]) {
                cout << "The number is valid here\nBut it does not match the given board's solution!\n";
                lives--;
                cout << "Enter row, column,0 to undo your current move.\n";
                cout << "The board after this move is:\n";
            }
            else if (check && num == array1[row][col]) {
                cout << "Correct move!!\n";
                cout << "The board after this move is:\n";
            }
        }
        else if (num == 0) {
            array[row][col] = 0;
        }
    }
    else {
        cout << "Invalid number entered!\n";
        cout << "The board without changes is:\n";
    }
}

//hint function
bool hint(int row, int col, int array[][9], int array1[][9]) {
    if (row >= 0 && row < 9 && col >= 0 && col < 9) {
        if (array[row][col] == 0) {
            cout << "Hint: The correct number at (" << row + 1 << "," << col + 1 << ") is "
                << array1[row][col] << endl;
            array[row][col] = array1[row][col];
            return true;
        }
        else {
            cout << "This cell already has a number. You can only get hints on empty cells.\n";
            return false;
        }
    }
    else {
        cout << "Invalid row or column!\n";
        return false;
    }
}

//checker function
void checker(int array[][9], int array1[][9]) {
    int wrong = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (array[i][j] != 0) {
                if (array[i][j] != array1[i][j]) {
                    cout << "Entered element at (row: " << i + 1 << ",column: " << j + 1 << ") is incorrect\n";
                    ++wrong;
                }
            }
        }
    }
    if (wrong == 0) { cout << "Your board is checked. \nAll elements are in the right place!"; }
}

//solver function
void solver(int array[][9], int array1[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            array[i][j] = array1[i][j];

        }
    }
}
bool win(int array[][9], int array1[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (array[i][j] != array1[i][j]) {
                return false;
            }
        }
    }
        return true;
    }
