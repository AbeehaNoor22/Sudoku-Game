#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void is_valid(int array[][9]) {
	bool check;
	bool used;
	int newNum;
	//cheking repeatition in rows
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			check = false;
			for (int k = 0; k < 9; k++) {
				if (k == j) continue; //skip checking itself
				else if (array[i][j] == array[i][k]) {
					check = true;
					break;
				}
			}
			if (check) {
				do {
					newNum = rand() % 9 + 1;
					used = false;
					for (int k = 0; k < 9; k++) {
						if (array[i][k] == newNum) { used = true; break; }
					}
				} while (used);
				array[i][j] = newNum;
			}
		}
	}
	//cheking repeatition in columns
	/*bool checkk, usedd;
	int newNumb;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			checkk = false;
			for (int k = 0; k < 9; k++) {
				if (j == k)continue;
				else if (array[i][j] == array[k][j]) {
					checkk = true;
					break;
				}
			}
			if (checkk) {
				do {
					newNumb = rand() % 9 + 1;
					usedd = false;
					for (int k = 0; k < 9; k++) {
						if (newNumb == array[k][j]) {
							usedd = true;
							break;
						}
					}
				} while (usedd);
				array[i][j] = newNumb;
			}
		}
	}*/
}
void game_setup() {
	srand(time(0));
	int grid[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = rand() % 9 + 1;
		}
	}
	is_valid(grid);
	cout << "====== WELCOME TO SUDOKU GAME ======\n\n\n";
	cout << "* _______  * _______  * ________ *\n\n";
	for (int i = 0; i < 9; i++) {
		cout << "| ";
		for (int j = 0; j < 9; j++) {
			cout << " " << grid[i][j] << " ";
			if ((j + 1) % 3 == 0) { cout << "| "; }
		}
		cout << "\n";
		if ((i + 1) % 3 == 0)cout << "* _______  * _______  * ________ *\n\n";
	}
}
int main() {
	game_setup();

	system("pause");
	return 0;
}