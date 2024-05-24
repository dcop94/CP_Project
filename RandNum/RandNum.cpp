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
			cout << setw(70) << " 게임을 종료 합니다. " << endl;
			exitGame = true;
			break;

		default:
			cout << setw(70) << " 다시 선택 해주세요 " << endl;
			break;
		}
	}

	return 0;

}

void Rand_menu()
{
	cout << setw(77) << " 맞춰라 랜덤숫자 오신걸 환영합니다. " << endl;
	cout << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      게 임 메 뉴     " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "    1. 숫 자 입 력    " << endl;
	cout << setw(70) << "    2. 게 임 종 료    " << endl;
	cout << setw(70) << " -------------------- " << endl;
	cout << setw(70) << "      메 뉴 선 택     ";
	cout << endl;
}

void Choice_Menu(int use[], int com[])
{
	int final_Choice;
	cout << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "      최후의  선 택     " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "     1. 다 시 입 력     " << endl;
	cout << setw(70) << "     2. 결 과 보 기     " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "       메 뉴 선 택      ";
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
		cout << " 잘못 입력 했습니다 " << endl;

	}
}


bool isDuplicate(int use[], int input_num)
{
	if (input_num < 1 || input_num > 25)
	{
		cout << " 1 ~ 25까지의 숫자만 입력 하세요 \n \n";
		return true;
	}
	for (int i = 0; i < use_num; i++)
	{
		if (use[i] == input_num)
		{
			cout << " 중복입니다 다시 입력해주세요 \n \n";
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
		cout << size + 1 << " 번째 숫자를 입력하세요 : ";
		cin >> input_num;

		if (!isDuplicate(use,input_num))
		{
			use[size++] = input_num;

		}
		
		
	}
}

void com_input(int com[], int use[])
{
	
	cout << " 당첨번호가 집계되고 있습니다. 잠시만 기다려주세요 \n\n";

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
	cout << " 당 첨 번 호 는 : ";
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
	cout << " 내가 입력 한 번호 : ";
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
		cout << " 6등에 당첨되었습니다 ! \n\n";
		break;

	case 2:
		cout << " 5등에 당첨되었습니다 ! \n\n";
		break;

	case 3:
		cout << " 4등에 당첨되었습니다 ! \n\n";
		break;

	case 4:
		cout << " 3등에 당첨되었습니다 ! \n\n";
		break;

	case 5:
		cout << " 2등에 당첨되었습니다 ! \n\n";
		break;

	case 6:
		cout << " 1등에 당첨되었습니다 ! \n\n";
		break;

	default:
		cout << " 아쉽지만 낙첨되었습니다. \n\n";
		break;
	}


}





// 사용자가 입력하는 숫자가 중복
// 입력을 받을때마다 검사를 해야 한다 ?



// 로또번호 생성 함수
// 사용자 입력 함수
// 각 배열 체크 함수


// 메뉴 (1. 숫자 입력하기, 2. 프로그램 종료) > 6번째까지 입력 받으면 > 최후의 선택 ( 1. 결과보기, 2. 다시 입력하기 ) > 1. 결과보기 > 당첨번호는 ~ 1 / 2/ 3/ 4/ 5/ 6 입니다. > 축하합니다. 몇등입니다. / 아쉽습니다. 낙첨입니다. > 메인메뉴 출력