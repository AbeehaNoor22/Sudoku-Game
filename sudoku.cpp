#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//FUNCTION PROTOTYPES
bool is_valid(int, int, int, int[][9]);
void remove_cells(int[][9]);
void sudoku();
void print_initial_board(int[][9]);
void input(int, int, int, int[][9]);

//MAIN
int main() {
    sudoku();
    system("pause");
}

//FUNCTION DEFINITIONS
void sudoku() {
    cout << "====== WELCOME TO SUDOKU GAME ======\n\n";
    int array[9][9], row, col, num;
    srand(time(0));

    // initialize
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            array[i][j] = 0;

    // fill board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            int attempts = 0;
            int num;

            while (true) {
                num = rand() % 9 + 1;
                attempts++;
                // if too many failed attempts reset row
                if (attempts > 10) {
                    for (int c = 0; c < 9; c++)
                        array[i][c] = 0;
                    j = -1;   // restart row (loop will ++j = 0)
                    break;
                }

                if (is_valid(i, j, num, array)) {
                    array[i][j] = num;
                    break;
                }
            }
        }
    }
    remove_cells(array);
    print_initial_board(array);
    while (true) {
        cout << "Enter the row, column and number\n";
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Number: ";
        cin >> num;
        input(row, col, num, array);

        cout << "The board after this move is:\n";
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
void input(int row, int col, int num, int array[9][9]) {
    if (array[row][col] == 0) {
        array[row][col] = num;
    }
    if (!is_valid(row, col, num, array)) {
        cout << "The number is not valid here.\n";
    }
}