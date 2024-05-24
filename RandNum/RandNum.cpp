#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


#define use_num 6
#define lotto_num 6

void use_input(int use[]);
bool isDuplicate(int use[], int input_num);
void print_match(int use[], int com[]);
void com_input(int com[], int use[]);
void Rand_menu();
void Choice_Menu(int use[], int com[]);
void print_use_num(int use[]);



int main()
{
	int menuChoice;
	bool exitGame = false;
	int use[use_num];
	int com[lotto_num];

	while (!exitGame)
	{
		Rand_menu();
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			use_input(use);
			Choice_Menu(use, com);
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

	return 0;

}

void Rand_menu()
{
	cout << setw(77) << " ����� �������� ���Ű� ȯ���մϴ�. " << endl;
	cout << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      �� �� �� ��     " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "    1. �� �� �� ��    " << endl;
	cout << setw(70) << "    2. �� �� �� ��    " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      �� �� �� ��     ";
	cout << endl;
}

void Choice_Menu(int use[], int com[])
{
	int final_Choice;
	cout << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "      ������  �� ��     " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "     1. �� �� �� ��     " << endl;
	cout << setw(70) << "     2. �� �� �� ��     " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "       �� �� �� ��      ";
	cout << endl;
	cin >> final_Choice;

	switch (final_Choice)
	{
	case 1:
		for (int i = 0; i < use_num; i++)
		{
			use[i] = 0;
		}
		use_input(use);
		Choice_Menu(use, com);
		break;

	case 2:
		com_input(com, use);
		break;

	default:
		cout << endl;
		cout << " �߸� �Է� �߽��ϴ� " << endl;

	}
}


bool isDuplicate(int use[], int input_num)
{
	if (input_num < 1 || input_num > 25)
	{
		cout << " 1 ~ 25������ ���ڸ� �Է� �ϼ��� \n \n";
		return true;
	}
	for (int i = 0; i < use_num; i++)
	{
		if (use[i] == input_num)
		{
			cout << " �ߺ��Դϴ� �ٽ� �Է����ּ��� \n \n";
			return true;
		}
	}
	return false;
}

void use_input(int use[])
{
	int size = 0;
	int input_num;

	while (size < use_num)
	{
		cout << size + 1 << " ��° ���ڸ� �Է��ϼ��� : ";
		cin >> input_num;

		if (!isDuplicate(use,input_num))
		{
			use[size++] = input_num;

		}
		
		
	}
}

void com_input(int com[], int use[])
{
	
	cout << " ��÷��ȣ�� ����ǰ� �ֽ��ϴ�. ��ø� ��ٷ��ּ��� \n\n";

	srand((unsigned)time(0));


	for (int i = 0; i < lotto_num; i++)
	{
		bool duplicate;
		do
		{
			duplicate = false;
			com[i] = rand() % 25 + 1;

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
	cout << " �� ÷ �� ȣ �� : ";
	for (int i = 0; i < lotto_num; i++)
	{
		cout << com[i] << " ";
	}
	cout << endl;

	print_use_num(use);
	print_match(use, com);
}


void print_use_num(int use[])
{
	cout << " ���� �Է� �� ��ȣ : ";
	for (int i = 0; i < use_num; i++)
	{
		cout << use[i] << " ";
	}
	cout << endl;
}

void print_match(int use[], int com[])
{
	int match_test = 0;

	for (int i = 0; i < use_num; i++)
	{
		for (int j = 0; j < lotto_num; j++)
		{
			if (use[i] == com[j])
			{
				match_test++;
			}
		}
	}

	switch (match_test)
	{
	case 1:
		cout << " 6� ��÷�Ǿ����ϴ� ! \n\n";
		break;

	case 2:
		cout << " 5� ��÷�Ǿ����ϴ� ! \n\n";
		break;

	case 3:
		cout << " 4� ��÷�Ǿ����ϴ� ! \n\n";
		break;

	case 4:
		cout << " 3� ��÷�Ǿ����ϴ� ! \n\n";
		break;

	case 5:
		cout << " 2� ��÷�Ǿ����ϴ� ! \n\n";
		break;

	case 6:
		cout << " 1� ��÷�Ǿ����ϴ� ! \n\n";
		break;

	default:
		cout << " �ƽ����� ��÷�Ǿ����ϴ�. \n\n";
		break;
	}


}





// ����ڰ� �Է��ϴ� ���ڰ� �ߺ�
// �Է��� ���������� �˻縦 �ؾ� �Ѵ� ?



// �ζǹ�ȣ ���� �Լ�
// ����� �Է� �Լ�
// �� �迭 üũ �Լ�


// �޴� (1. ���� �Է��ϱ�, 2. ���α׷� ����) > 6��°���� �Է� ������ > ������ ���� ( 1. �������, 2. �ٽ� �Է��ϱ� ) > 1. ������� > ��÷��ȣ�� ~ 1 / 2/ 3/ 4/ 5/ 6 �Դϴ�. > �����մϴ�. ����Դϴ�. / �ƽ����ϴ�. ��÷�Դϴ�. > ���θ޴� ���