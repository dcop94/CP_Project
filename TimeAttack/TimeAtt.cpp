#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void Count_Menu();
void TimeAtt_Menu();
void TimeAtt_Game(int time_Choice);
bool Word_Check(string input_word, const string& last_word, const vector<string>& temp_word);



int main()
{
	int menuChoice;
	bool exitGame = false;


	while (!exitGame)
	{
		TimeAtt_Menu();
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			Count_Menu();
			break;

		case 2:
			cout << setw(70) << " 게임을 다시 시작합니다 " << endl;
			Count_Menu();
			break;

		case 3:
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


void Count_Menu()
{
	int time_Choice;
	cout << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "      제한시간 선택     " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "       1. [10초]        " << endl;
	cout << setw(70) << "       1. [15초]        " << endl;
	cout << setw(70) << "       1. [20초]        " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "       메 뉴 선 택      ";
	cout << endl;
	cin >> time_Choice;

	switch (time_Choice)
	{
	case 1:
		TimeAtt_Game(10);
		break;

	case 2:
		TimeAtt_Game(15);
		break;

	case 3:
		TimeAtt_Game(20);
		break;

	default:
		cout << endl;
		cout << " 잘못 입력 했습니다 " << endl;

	}
}

void TimeAtt_Menu()
{
	cout << setw(83) << "  타임어택 끝말잇기 게임에 오신걸 환영 합니다 " << endl;
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

void TimeAtt_Game(int time_Choice)
{
	vector<string> temp_word;
	string last_word;
	int count_word = 0;



	int start_Num;
	cout << setw(87) << " --------------------------------------------------- " << endl;
	cout << setw(87) << " 타임어택 끝말잇기를 시작 하시려면 '1' 을 입력하세요 " << endl;
	cout << setw(87) << " --------------------------------------------------- " << endl;
	cout << setw(80) << "                       게임 시작 :                   " << " ";
	cin >> start_Num;

	clock_t startTime = clock();
	clock_t endTime = clock() + time_Choice * CLOCKS_PER_SEC;

	while (start_Num == 1 && clock() < endTime)
	{
		string input_word;
		cout << endl;
		cout << setw(70) << " 단어를 입력 해주세요 : " << " ";
		cin >> setw(70) >> input_word;

		if (clock() >= endTime)
		{
			cout <<  setw(70) << " 제한시간이 종료 되었습니다 ! " << endl;
			break;
		}

		bool temp_check = Word_Check(input_word, last_word, temp_word);

		if (!temp_check)
		{
			continue;
		}

		last_word = input_word;
		temp_word.push_back(input_word);
		count_word++;

		for (const auto& word : temp_word)
		{
			cout << word << " > "; 
		}
		
		cout  << " 입니다 " << endl;

	}

	cout << setw(70) << " 총 입력한 단어의 개수는 " << count_word << " 개 입니다. " << endl;
}

bool Word_Check(string input_word, const string &last_word, const vector<string> &temp_word )
{
	
	if (!last_word.empty() && last_word.back() != input_word.front())
	{
		cout << setw(70) << " 잘못입력했습니다. 이전 단어는 " << last_word << " 이기에 " << last_word.back() << " 로 시작하는 단어를 입력하세요 " << endl;
		return false;
	}
	
	if (last_word == input_word)
	{
		cout << setw(70) << " 이미 입력한 단어 입니다. 다시 입력해주세요 " << endl;
		return false;
	}
	
	return true;
	
}


