#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
void gameMenu();
void brPlay();



int main()
{
	int menuChoice;
	bool exitGame = false;

	while (!exitGame)
	{
		gameMenu();
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			brPlay();
			break;

		case 2:
			cout << " ������ �ٽ� �����մϴ� " << endl;
			brPlay();
			break;

		case 3:
			cout << " ������ ���� �մϴ�. " << endl;
			exitGame = true;
			break;

		default:
			cout << " �ٽ� ���� ���ּ��� " << endl;
			break;
		}
	}

	return 0;
}

void gameMenu()
{
	cout << setw(75) << " BR 31 ���ӿ� ���Ű� ȯ�� �մϴ� " << endl;
	cout << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      �� �� �� ��     " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "    1. �� �� �� ��    " << endl;
	cout << setw(70) << "    2. �� �� �� ��    " << endl;
	cout << setw(70) << "    3. �� �� �� ��    " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      �� �� �� ��     ";
	cout << endl;
}

void brPlay()
{
	int firstPlayChoice;
	int inputNum;
	int saveNum = 0;

	srand(time(0));

	cout << " ���� ���� �� �÷��̾ ������ ( 1: ����, 2: ��ǻ�� ) : ";
	cout << endl;
	cin >> firstPlayChoice;

	while (saveNum < 31)
	{
		if (firstPlayChoice == 1)
		{
			cout << endl;
			cout << " �� ������ ���� �Դϴ�. 1 ~ 3 �� ���ڸ� �Է��ϼ��� : ";
			cin >> inputNum;

			if (inputNum < 1 || inputNum > 3)
			{
				cout << " " << " �ƢƢ� ���ڸ� �߸� �Է��߽��ϴ�. �ٽ� �Է��ϼ��� �ƢƢ�  " << endl;
				continue;
			}

			for (int i = saveNum + 1; i <= saveNum + inputNum; i++)
			{
				cout << " " << i << " ";

				if (i == 31)
				{
					cout << " " << " < ������ �й� �Դϴ� > " << endl;
					return;
				}

			}

			cout << endl;

			saveNum += inputNum;
			firstPlayChoice = 2;
		}

		else if (firstPlayChoice == 2)
		{
			inputNum = rand() % 3 + 1;
			cout << endl;
			cout << " �� B�İ��� ���� �Դϴ�. �߸�����~ : " << inputNum << endl;

			for (int i = saveNum + 1; i <= saveNum + inputNum; i++)
			{
				cout << " " << i << " ";

				if (i == 31)
				{
					cout << endl;
					cout << endl;
					cout << "  < B�İ��� �й� �Դϴ� > " << endl;
					return;
				}
			}
			cout << endl;

			saveNum += inputNum;
			firstPlayChoice = 1;

		}
		else
		{
			cout << " " << " �ƢƢ� �߸� �Է��߽��ϴ�. �ٽ� �Է��ϼ��� �ƢƢ� " << endl;

		}

	}

}

