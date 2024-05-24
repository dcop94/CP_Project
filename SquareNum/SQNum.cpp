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
			cout << setw(70) << " ������ ���� �մϴ�. " << endl;
			exitGame = true;
			break;

		default:
			cout << setw(70) << " �ٽ� ���� ���ּ��� " << endl;
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
	cout << setw(77) << " ��̴� �������� ���Ű� ȯ���մϴ�. " << endl;
	cout << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      �� �� �� ��     " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "    1. ��  ��  ��     " << endl;
	cout << setw(70) << "    2. �� �� �� ��    " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      �� �� �� ��     ";

}

void start_SQ()
{
	
	while (true)
	{
		cout << setw(70) << " �������� ũ�⸦ �Է��ϼ��� : ";
		cin >> input_num;

		if (input_num % 2 == 0)
		{
			cout << setw(70) << " ũ��� Ȧ���� ���� �մϴ�. �ٽ� �Է��ϼ��� \n\n";
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