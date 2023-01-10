#include <iostream>
#include<Windows.h>

using namespace std;

const int row = 3;
const int col = 4;
int arr[row][col];
int arr2[row][col]
{
 {4, 5, 6, 7},
 {1, 2, 4, 1},
 {4, 5, 6, 9}
};
int n;
int step;
int m;

//Задание 1
void arrx2();

//Задание 2
void arrx1();

//Задание 3
void showArr2();
void stepArrRight(int arr2[][4], int row, int col, int step);
void stepArrLeft(int arr2[][4], int row, int col, int step);
void stepArrDown(int arr[][4], int row, int col, int step);
void stepArrUp(int arr[][4], int row, int col, int step);
void showArr();

int main()
{
	setlocale(LC_ALL, "");
	//arrx2();//1
	//arrx1();//2
	//showArr();//3
}
void arrx2() {
	cin >> n;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = n;
			n *= 2;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void arrx1() {
	cin >> n;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = n++;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void showArr2() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
}
void stepArrRight(int arr2[][4], int row, int col, int step) {
	if (step > 0) {
		for (int i = 0; i < row; i++) {
			int temp = arr2[i][col - 1];
			for (int j = col - 1; j > 0; j--) {
				arr2[i][j] = arr2[i][j - 1];
			}
			arr2[i][0] = temp;
		}
		stepArrRight(arr2, row, col, --step);
	}
}
void stepArrLeft(int arr2[][4], int row, int col, int step) {
	if (step > 0) {
		for (int i = 0; i < row; i++) {
			int temp = arr2[i][0];
			for (int j = 0; j <col; j++) {
				arr2[i][j] = arr2[i][j+1];
			}
			arr2[i][col-1]= temp;
		}
		stepArrLeft(arr2, row, col, --step);
	}
}
void stepArrDown(int arr[][4], int row, int col, int step) {
	if (step > 0) {
		for (int j = 0; j < col; j++) {
			int temp = arr[row - 1][j];
			for (int i = row - 1; i > 0; i--) {
				arr[i][j] = arr[i - 1][j];
			}
			arr[0][j] = temp;
		}
		stepArrDown(arr, row, col, --step);
	}
}
void stepArrUp(int arr[][4], int row, int col, int step) {
	if (step > 0) {
		for (int j = 0; j < col; j++) {
			int temp = arr[0][j];
			for (int i = 0; i < row-1; i++) {
				arr[i][j] = arr[i + 1][j];
			}
			arr[row - 1][j] = temp;
		}
		stepArrUp(arr, row, col, --step);
	}
}
void showArr() {
	showArr2();
	cout << endl;
	cout << "Выберите кол-во сдвигов\n";
	cin >> step;
	cout << "Выберите куда сдвинуть\n";
	cout << "1-Right\n";
	cout << "2-Left\n";
	cout << "3-Up\n";
	cout << "4-Down\n";
	cin >> m;
	switch (m) {
	case 1:
		stepArrRight(arr2, row, col, step);
		break;
	case 2:
		stepArrLeft(arr2, row, col, step);
		break;
	case 3:
		stepArrUp(arr2, row, col, step);
		break;
	case 4:
		stepArrDown(arr2, row, col, step);
		break;
	default:
		cout << "Eror\n";
		break;
	}
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
}

