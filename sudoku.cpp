#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//FUNCTION PROTOTYPES
bool is_valid(int, int, int, int[][9]);
void remove_cells(int[][9]);
void sudoku();
void print_initial_board(int[][9]);
void input(int, int, int, int[][9], int[][9]);
bool hint(int row, int col, int array[][9], int array1[][9]);


//MAIN
int main() {
    sudoku();
    system("pause");
}

//FUNCTION DEFINITIONS
void sudoku() {
    cout << "====== WELCOME TO SUDOKU GAME ======\n\n";
    int array1[9][9], array[9][9], row, col, numb, num, attempts, hints = 3;
    srand(time(0));

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
    while (true) {
        cout << "Enter the row, column and number (Enter -1 as number to get hint)\n";
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Number: ";
        cin >> numb;
        if (numb == -1) {
            if (hints > 0) {
                bool used = hint(row - 1, col - 1, array, array1);
                if (used == 1) {
                    hints--;
                }
                    cout << "Hints left: " << hints << endl;
            }
            else {
                cout << "No hints left!\n";
            }
        }
        else {
            input(row - 1, col - 1, numb, array, array1);
        }
        print_initial_board(array);
    }

}

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
void input(int row, int col, int num, int array[9][9], int array1[][9]) {
    if (row >= 0 && row < 9 && col >= 0 && col < 9 && num <= 9 && num >= 1) {
        if (num != 0) {
            bool check = is_valid(row, col, num, array);
            if (array[row][col] == 0) {
                array[row][col] = num;
            }
            if (!check) {
                cout << "The number is not valid here.\n";
                cout << "Enter row, column,0 to undo your current move.\n";
                cout << "The board after this move is:\n";
            }
            else if (check && num != array1[row][col]) {
                cout << "The number is valid here\nBut it does not match the given board's solution!\n";
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
