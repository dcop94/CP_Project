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
			cout << setw(70) << " ������ �ٽ� �����մϴ� " << endl;
			Count_Menu();
			break;

		case 3:
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


void Count_Menu()
{
	int time_Choice;
	cout << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "      ���ѽð� ����     " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "       1. [10��]        " << endl;
	cout << setw(70) << "       1. [15��]        " << endl;
	cout << setw(70) << "       1. [20��]        " << endl;
	cout << setw(70) << " ---------------------- " << endl;
	cout << setw(70) << "       �� �� �� ��      ";
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
		cout << " �߸� �Է� �߽��ϴ� " << endl;

	}
}

void TimeAtt_Menu()
{
	cout << setw(83) << "  Ÿ�Ӿ��� �����ձ� ���ӿ� ���Ű� ȯ�� �մϴ� " << endl;
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

void TimeAtt_Game(int time_Choice)
{
	vector<string> temp_word;
	string last_word;
	int count_word = 0;



	int start_Num;
	cout << setw(87) << " --------------------------------------------------- " << endl;
	cout << setw(87) << " Ÿ�Ӿ��� �����ձ⸦ ���� �Ͻ÷��� '1' �� �Է��ϼ��� " << endl;
	cout << setw(87) << " --------------------------------------------------- " << endl;
	cout << setw(80) << "                       ���� ���� :                   " << " ";
	cin >> start_Num;

	clock_t startTime = clock();
	clock_t endTime = clock() + time_Choice * CLOCKS_PER_SEC;

	while (start_Num == 1 && clock() < endTime)
	{
		string input_word;
		cout << endl;
		cout << setw(70) << " �ܾ �Է� ���ּ��� : " << " ";
		cin >> setw(70) >> input_word;

		if (clock() >= endTime)
		{
			cout <<  setw(70) << " ���ѽð��� ���� �Ǿ����ϴ� ! " << endl;
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
		
		cout  << " �Դϴ� " << endl;

	}

	cout << setw(70) << " �� �Է��� �ܾ��� ������ " << count_word << " �� �Դϴ�. " << endl;
}

bool Word_Check(string input_word, const string &last_word, const vector<string> &temp_word )
{
	
	if (!last_word.empty() && last_word.back() != input_word.front())
	{
		cout << setw(70) << " �߸��Է��߽��ϴ�. ���� �ܾ�� " << last_word << " �̱⿡ " << last_word.back() << " �� �����ϴ� �ܾ �Է��ϼ��� " << endl;
		return false;
	}
	
	if (last_word == input_word)
	{
		cout << setw(70) << " �̹� �Է��� �ܾ� �Դϴ�. �ٽ� �Է����ּ��� " << endl;
		return false;
	}
	
	return true;
	
}


