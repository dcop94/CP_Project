#include <iostream>
#include <iomanip>


using namespace std;

void sqnum_menu();
void start_SQ();
void isMake_Square();

int** sqnum = 0;
int input_num = 0;


int main()
{
	int menuChoice;
	bool exitGame = false;

	while (!exitGame)
	{
		sqnum_menu();
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			start_SQ();
			isMake_Square();
			break;

		case 2:
			cout << setw(70) << " 게임을 종료 합니다. " << endl;
			exitGame = true;
			break;

		default:
			cout << setw(70) << " 다시 선택 해주세요 " << endl;
			break;
		}
	}

	if (sqnum != 0)
	{
		for (int i = 0; i < input_num; i++)
		{
			delete[] sqnum[i];
		}
		delete[] sqnum;
	}

	return 0;
}


void sqnum_menu()
{
	cout << setw(77) << " 쇼미더 마방진에 오신걸 환영합니다. " << endl;
	cout << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      게 임 메 뉴     " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "    1. 만  들  기     " << endl;
	cout << setw(70) << "    2. 게 임 종 료    " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      메 뉴 선 택     ";

}

void start_SQ()
{
	
	while (true)
	{
		cout << setw(70) << " 마방진의 크기를 입력하세요 : ";
		cin >> input_num;

		if (input_num % 2 == 0)
		{
			cout << setw(70) << " 크기는 홀수만 가능 합니다. 다시 입력하세요 \n\n";
		}
		else
		{
			break;
		}
	}

	sqnum = new int* [input_num];
	for (int i = 0; i < input_num; i++)
	{
		sqnum[i] = new int[input_num];

		for (int j = 0; j < input_num; j++)
		{
			sqnum[i][j] = 0;
		}
	}
}

void isMake_Square()
{
	int row = 0, col = input_num / 2;
	int first_num;

	for (first_num = 1; first_num <= input_num * input_num; first_num++)
	{
		sqnum[row][col] = first_num;
		
		int new_row = (row - 1 + input_num) % input_num;
		int new_col = (col + 1) % input_num;

		if (sqnum[new_row][new_col] != 0)
		{
			row = (row + 1) % input_num;
		}
		else
		{
			row = new_row;
			col = new_col;
		}
	}

	int padding = (110 - (input_num * 4)) / 2;
	for (int i = 0; i < input_num; i++)
	{
		cout << setw(padding) << "";
		for (int j = 0; j < input_num; j++)
		{
			cout << setw(4) << sqnum[i][j];
		}

		cout << endl;
	}
}