#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;





void remove_cells(int array[][9]) {
    int choice, target, removed = 0;
    cout << "Choose the difficulty level\n1.Easy\n2.Medium\n3.Hard\n";
    cin >> choice;
    switch (choice) {
    case 1:
        target = 30;
        break;
    case 2:
        target = 40;
        break;
    case 3:
        target = 50;
        break;
    default:
        cout << "Invalid choice, defaulting to Easy.\n";
        target = 30;
    }
    while (removed < target) {
        int k = rand() % 9;
        int l = rand() % 9;
       if (array[l][k] !=0) {
            array[l][k] =0;
            removed++;
        }
    }
}




bool is_valid(int array[][9], int i, int j, int num) {

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

void board_generator() {
    int array[9][9];
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

                if (is_valid(array, i, j, num)) {
                    array[i][j] = num;
                    break;
                }
            }

        }
    }
    remove_cells(array);

    // print board
    cout << "====== WELCOME TO SUDOKU GAME ======\n\n\n";
    cout << "* _______  * _______  * ________ *\n";
    for (int i = 0; i < 9; i++) {
        cout << "| ";
        for (int j = 0; j < 9; j++) {
            if (array[i][j] == 0) {
                cout << " " << " " << " ";
            }
            else {
                cout << " " << array[i][j] << " ";
            }
                if ((j + 1) % 3 == 0) cout << "| ";
            
        }
            cout << "\n";
        if ((i + 1) % 3 == 0)
            cout << "* _______  * _______  * ________ *\n\n";
    }
}

int main() {
    board_generator();
    system("pause");
}