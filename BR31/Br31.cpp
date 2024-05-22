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
			cout << " 게임을 다시 시작합니다 " << endl;
			brPlay();
			break;

		case 3:
			cout << " 게임을 종료 합니다. " << endl;
			exitGame = true;
			break;

		default:
			cout << " 다시 선택 해주세요 " << endl;
			break;
		}
	}

	return 0;
}

void gameMenu()
{
	cout << setw(75) << " BR 31 게임에 오신걸 환영 합니다 " << endl;
	cout << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      게 임 메 뉴     " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "    1. 게 임 시 작    " << endl;
	cout << setw(70) << "    2. 다 시 하 기    " << endl;
	cout << setw(70) << "    3. 게 임 종 료    " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      메 뉴 선 택     ";
	cout << endl;
}

void brPlay()
{
	int firstPlayChoice;
	int inputNum;
	int saveNum = 0;

	srand(time(0));

	cout << " 먼저 시작 할 플레이어를 고르세요 ( 1: 유저, 2: 컴퓨터 ) : ";
	cout << endl;
	cin >> firstPlayChoice;

	while (saveNum < 31)
	{
		if (firstPlayChoice == 1)
		{
			cout << endl;
			cout << " ▶ 유저의 차례 입니다. 1 ~ 3 중 숫자를 입력하세요 : ";
			cin >> inputNum;

			if (inputNum < 1 || inputNum > 3)
			{
				cout << " " << " ▒▒▒ 숫자를 잘못 입력했습니다. 다시 입력하세요 ▒▒▒  " << endl;
				continue;
			}

			for (int i = saveNum + 1; i <= saveNum + inputNum; i++)
			{
				cout << " " << i << " ";

				if (i == 31)
				{
					cout << " " << " < 유저의 패배 입니다 > " << endl;
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
			cout << " ▷ B파고의 차례 입니다. 삐리리리~ : " << inputNum << endl;

			for (int i = saveNum + 1; i <= saveNum + inputNum; i++)
			{
				cout << " " << i << " ";

				if (i == 31)
				{
					cout << endl;
					cout << endl;
					cout << "  < B파고의 패배 입니다 > " << endl;
					return;
				}
			}
			cout << endl;

			saveNum += inputNum;
			firstPlayChoice = 1;

		}
		else
		{
			cout << " " << " ▒▒▒ 잘못 입력했습니다. 다시 입력하세요 ▒▒▒ " << endl;

		}

	}

}

