#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int com[3];
int strike = 0;
int ball = 0;

void com_turn();
void user_turn();

int main()
{
	com_turn();
	user_turn();

	return 0;
}

void com_turn()
{
	srand(time(0));

	for (int i = 0; i < 3; i++)
	{
		bool duplicate;
		do
		{
			duplicate = false;
			com[i] = rand() % 9 + 1;

			for (int j = 0; j < i; j++)
			{
				if (com[i] == com[j])
				{
					duplicate = true;
					break;
				}
			}
		} while (duplicate);
	}
}

void user_turn()
{


	int count = 0;

	while (strike < 3)
	{
		int strike = 0;
		int ball = 0;

		cout << " 1 ~ 9 ������ ���� 3���� �Է��ϼ��� (�̿� ���� : ����)" << endl;
		int use[3];

		for (int i = 0; i < 3; i++)
		{
			cin >> use[i];

			if (use[i] < 1 || use[i] > 9)
			{
				cout << " ���� ���� ! " << endl;
				return;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (use[i] == com[i])
			{
				strike++;
			}
			else if (use[i] == com[(i+1) % 3] || use[i] == com[(i+2) % 3])
			{
				ball++;
			}
			
		}
		count++;
		cout << "Strike : " << strike << " " << "Ball : " << ball << endl;
		
		if (strike == 3)
		{
			cout << " 3 Strike !! ���ڸ� ���߾����ϴ� " << " �õ�Ƚ�� : " << count << endl;
			return;
		}
	}
	
}