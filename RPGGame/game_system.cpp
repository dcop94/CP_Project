#include "Game_system.h"
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

Game::Game() {}

// 초기화면 출력 및 선택
void Game::start()
{
	int choice;
	cout << setw(80) << " ========================================== " << endl;
	cout << setw(80) << "            킹 갓 제 너 럴 게 임            " << endl;
	cout << setw(80) << " ========================================== " << endl;
	cout << setw(80) << " ========================================== " << endl;
	cout << setw(80) << "             1. 캐릭터 불러오기             " << endl;
	cout << setw(80) << "             2. 캐릭터 생성하기             " << endl;
	cout << setw(80) << " ========================================== " << endl;
	cout << setw(80) << " ========================================== " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		loadGame();
		showMenu();
		break;

	case 2:
		createCharacter();
		explainGame();
		showMenu();
		break;

	default:
		break;
	}

}


// 신규 플레이어 튜토리얼
void Game::explainGame()
{
	cout <<  " 안녕하세요 ! 킹갓제너럴 게임에 오신것을 환영합니다. " << endl;
	cout << endl;
	cout <<  " 게임 설명을 드리겠습니다. " << endl;
	cout << endl;
	cout <<  " ▶  이 게임은 [ 무기 ] 를 장착해야만 [ 몬스터 ] 와 전투가 가능합니다. " << endl;
	cout <<  " ▶  플레이어님이 무기를 장착했는지 확인하고 싶으시면 [ 게임메뉴 ] 에서 [ 캐릭터 정보 ] 를 확인 해주세요 " << endl;
	cout << endl;
	cout <<  " ▶  [ 게임메뉴 ] 에는 다양한 메뉴가 있습니다. " << endl;
	cout <<  " ▶  [ 캐릭터 정보 ] 는 현재 플레이어님의 정보를 확인 할 수 있습니다. " << endl;
	cout <<  " ▶  [ 몬스터 사냥 ] 은 몬스터와 전투를 하여 성장 할 수 있습니다. " << endl;
	cout <<  " ▶  [ 전투 ] 를 할 시에는 [ 무기 착용 ] 을 해야하고, [ 무기 사용 횟수 ]가 0이 되면 더이상 공격이 불가 합니다." << endl;
	cout << endl;
	cout <<  " ▶  [ 가방열기 ] 는 플레이어님이 습득 한 재화나 무기가 보관되어 있습니다. " << endl;
	cout <<  " ▶  이곳에서 무기를 교체 할 수 있습니다. " << endl;
	cout << " ▶  [ 저장하기 ] [ 불러오기 ] 는 현재 캐릭터를 저장 혹은 다른 캐릭터를 불러오기를 할 수 있습니다." << endl;
	cout << endl;
	cout <<  " ▶  게임에 대한 설명이 끝났습니다. 이제 사용 할 무기를 골라봅시다 " << endl;

	cout << " 1. 초보자 목검 " << "공격력 : " << Sword().getWeaponDamage() <<"" << "공격 횟수 : " << Sword().getWeaponUseNum() << endl;
	cout <<  " 2. 초보자 권총 " << "공격력 : " << Gun().getWeaponDamage() << "" << "공격 횟수 : " << Gun().getWeaponUseNum() << endl; // 초보자 권총 정보 출력

	cout << " 사용하고 싶은 무기를 선택하세요 : ";

	int choice;
	cin >> choice;



	switch (choice)
	{
	case 1:
		weapons.push_back(new Sword());
		cout << " [ 초보자 목검 ] 획득 하였습니다. " << endl;
		player.pickWeapon(weapons.back());
		cout << " [ 초보자 목검 ] 을 [ 가방 ] 에 넣었습니다. " << endl;
		cout << " [ 가방 ] 에서 [ 초보자 목검] 을 장착 해 보세요 " << endl;
		break;

	case 2:
		weapons.push_back(new Gun());
		cout << " [ 초보자 권총 ] 획득 하였습니다. " << endl;
		player.pickWeapon(weapons.back());
		cout << " [ 초보자 권총 ] 을 [ 가방 ] 에 넣었습니다. " << endl;
		cout << " [ 가방 ] 에서 [ 초보자 권총] 을 장착 해 보세요 " << endl;
		break;
	default:
		cout << " 잘못 입력했습니다. 다시 입력하세요 " << endl;
		return;
	}
}

// 플레이어 생성
void Game::createCharacter()
{
	string name;
	cout << " 캐릭터 이름을 입력하세요 : ";
	cin >> name;
	player.setName(name);

	cout << " 캐릭터를 성공적으로 생성하였습니다 ! " << endl;
}

// 스테이터스 출력
void Game::infoCharacter()
{
	cout << "--------------------------------" << endl;
	cout << "         캐 릭 터 정 보         " << endl;
	cout << "--------------------------------" << endl;
	cout << "  이    름 :  " << player.getName()<<endl;
	cout << "  체    력 :  " << player.getHp()<<endl;
	cout << "  경 험 치 :  " << player.getExp()<<endl;
	cout << "  착용무기 :  " << player.getEquipWeapon()<<endl;
	cout << "------------------------------" << endl;
}

// 게임 기본 메뉴
void Game::showMenu()
{
	int choice;

	do
	{
		cout << "------------------------------" << endl;
		cout << "   게임 메뉴를 선택해주세요   " << endl;
		cout << "------------------------------" << endl;
		cout << "        1. 캐릭터 정보        " << endl;
		cout << "        2. 몬스터 사냥        " << endl;
		cout << "        3. 가 방 열 기        " << endl;
		cout << "        4. 저 장 하 기        " << endl;
		cout << "        5. 불 러 오 기        " << endl;
		cout << "        0. 게 임 종 료        " << endl;
		cout << "------------------------------" << endl;
		cout << " 어떤것을 하실건가요? : ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << " 게임을 종료합니다 " << endl;
			break;

		case 1:
			infoCharacter();
			break;

		case 2:
			huntMonster();
			break;

		case 3:
			showInventory();
			break;

		case 4:
			saveGame();
			break;

		case 5:
			loadGame();
			break;

		default:
			cout << " 다시 입력하세요 " << endl;
		}

	} while (choice != 0);
}

// 몬스터 전투
void Game::huntMonster()
{
	vector<Monster*> monsters = { new Slime(), new Skeleton() };

	int choice;

	cout << "------------------------------" << endl;
	cout << "      몬스터를 선택하세요     " << endl;
	cout << "------------------------------" << endl;
	
	for (int i = 0; i < monsters.size(); i++)
	{
		cout << i + 1 << ". " << monsters[i]->getType() 
			<< " (체력 : " << monsters[i]->getHp() 
			<< ", 경험치 :" << monsters[i]->getExp() << ")" << endl;
	}

	cout << "          0. 돌아가기         " << endl;
	cout << "------------------------------" << endl;
	cout << "             선택 :           ";
	cin >> choice;

	if (choice > 0 && choice <= monsters.size())
	{
		Monster* target = monsters[choice - 1];
		cout << target->getType() << " 와 전투를 시작 합니다! " << endl;

		while (player.getHp() > 0 && target->getHp() > 0)
		{
			player.attack(*target, 0);

			if (target->getHp() > 0)
			{
				player.takeDamage(target->getMonsterDamage());
			}
		}

		if (player.getHp() > 0)
		{
			cout << " [ 승리 ! ] " << endl;
			player.addExp(target->getExp());
			player.levelUp();
		}
		else
		{
			cout << " [ 패배 ! ] " << endl;
		}
	}

	for (Monster* monster : monsters)
	{
		delete monster;
	}
	
}

// 인벤토리 출력 및 아이템 장착
void Game::showInventory()
{
	cout << "------------------------------" << endl;
	cout << "         플레이어 가방        " << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < weapons.size(); i++)
	{
		cout << i + 1 << ". " << weapons[i]->getWeaponName();
	}
	cout << " 장착 할 아이템을 골라주세요  " << endl;
	cout << "------------------------------" << endl;

	int choice;
	cin >> choice;

	if (choice > 0 && choice <= weapons.size())
	{
		player.equipWeapon(weapons[choice - 1]);
		cout << weapons[choice - 1]->getWeaponName() << " 을(를) 장착했습니다. " << endl;
	}
}

// 게임 저장
void Game::saveGame()
{
	ofstream saveFile("savegame.txt");

	if (saveFile.is_open())
	{
		saveFile << player.getName() << endl;
		saveFile << player.getHp() << endl;
		saveFile << player.getExp() << endl;
		saveFile << player.getEquipWeapon() << endl;

		saveFile.close();
		cout << " [ 게임 저장 완료 ] " << endl;
	}
	else
	{
		cout << " [ 게임 저장 실패 ] " << endl;
	}
}

// 게임 불러오기
void Game::loadGame()
{
	ifstream loadFile("savegame.txt");

	if (loadFile.is_open())
	{
		string name;
		int hp, exp;
		string weaponName;

		getline(loadFile, name);
		loadFile >> hp >> exp;
		loadFile.ignore();
		getline(loadFile, weaponName);

		player.setName(name);
		player.setHp(hp);
		player.addExp(exp);

		loadFile.close();
		cout << " [ 게임 불러오기 완료 ] " << endl;
	}
}