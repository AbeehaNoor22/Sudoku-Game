#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

/*void is_valid(int array[][9]) {
	bool check = false;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (array[i][j] == array[i][k]) {
					check = true;
				}
			}
			if (check == true) { array[i][j] = rand() % 9 + 1; }
		}
	}
}*/
void game_setup() {
	srand(time(0));
	int grid[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = rand() % 9 + 1;
		}
	}
	//is_valid(grid);
	cout << "====== WELCOME TO SUDOKU GAME ======\n\n\n";
	cout << "* _______  * _______  * ________ *\n\n";
	for (int i = 0; i < 9; i++) {
		cout << "| ";
		for (int j = 0; j < 9; j++) {
			cout << " "<<grid[i][j]<<" ";
			if ((j+1) % 3 == 0) { cout << "| "; }
		}
		cout << "\n";
		if ((i+1) % 3 == 0)cout << "* _______  * _______  * ________ *\n\n";
	}
}
int main() {
	game_setup();

	system("pause");
	return 0;
}