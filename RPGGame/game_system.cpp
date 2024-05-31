#include "Game_system.h"
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

Game::Game() {}

// �ʱ�ȭ�� ��� �� ����
void Game::start()
{
	int choice;
	cout << setw(80) << " ========================================== " << endl;
	cout << setw(80) << "            ŷ �� �� �� �� �� ��            " << endl;
	cout << setw(80) << " ========================================== " << endl;
	cout << setw(80) << " ========================================== " << endl;
	cout << setw(80) << "             1. ĳ���� �ҷ�����             " << endl;
	cout << setw(80) << "             2. ĳ���� �����ϱ�             " << endl;
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


// �ű� �÷��̾� Ʃ�丮��
void Game::explainGame()
{
	cout <<  " �ȳ��ϼ��� ! ŷ�����ʷ� ���ӿ� ���Ű��� ȯ���մϴ�. " << endl;
	cout << endl;
	cout <<  " ���� ������ �帮�ڽ��ϴ�. " << endl;
	cout << endl;
	cout <<  " ��  �� ������ [ ���� ] �� �����ؾ߸� [ ���� ] �� ������ �����մϴ�. " << endl;
	cout <<  " ��  �÷��̾���� ���⸦ �����ߴ��� Ȯ���ϰ� �����ø� [ ���Ӹ޴� ] ���� [ ĳ���� ���� ] �� Ȯ�� ���ּ��� " << endl;
	cout << endl;
	cout <<  " ��  [ ���Ӹ޴� ] ���� �پ��� �޴��� �ֽ��ϴ�. " << endl;
	cout <<  " ��  [ ĳ���� ���� ] �� ���� �÷��̾���� ������ Ȯ�� �� �� �ֽ��ϴ�. " << endl;
	cout <<  " ��  [ ���� ��� ] �� ���Ϳ� ������ �Ͽ� ���� �� �� �ֽ��ϴ�. " << endl;
	cout <<  " ��  [ ���� ] �� �� �ÿ��� [ ���� ���� ] �� �ؾ��ϰ�, [ ���� ��� Ƚ�� ]�� 0�� �Ǹ� ���̻� ������ �Ұ� �մϴ�." << endl;
	cout << endl;
	cout <<  " ��  [ ���濭�� ] �� �÷��̾���� ���� �� ��ȭ�� ���Ⱑ �����Ǿ� �ֽ��ϴ�. " << endl;
	cout <<  " ��  �̰����� ���⸦ ��ü �� �� �ֽ��ϴ�. " << endl;
	cout << " ��  [ �����ϱ� ] [ �ҷ����� ] �� ���� ĳ���͸� ���� Ȥ�� �ٸ� ĳ���͸� �ҷ����⸦ �� �� �ֽ��ϴ�." << endl;
	cout << endl;
	cout <<  " ��  ���ӿ� ���� ������ �������ϴ�. ���� ��� �� ���⸦ ��󺾽ô� " << endl;

	cout << " 1. �ʺ��� ��� " << "���ݷ� : " << Sword().getWeaponDamage() <<"" << "���� Ƚ�� : " << Sword().getWeaponUseNum() << endl;
	cout <<  " 2. �ʺ��� ���� " << "���ݷ� : " << Gun().getWeaponDamage() << "" << "���� Ƚ�� : " << Gun().getWeaponUseNum() << endl; // �ʺ��� ���� ���� ���

	cout << " ����ϰ� ���� ���⸦ �����ϼ��� : ";

	int choice;
	cin >> choice;



	switch (choice)
	{
	case 1:
		weapons.push_back(new Sword());
		cout << " [ �ʺ��� ��� ] ȹ�� �Ͽ����ϴ�. " << endl;
		player.pickWeapon(weapons.back());
		cout << " [ �ʺ��� ��� ] �� [ ���� ] �� �־����ϴ�. " << endl;
		cout << " [ ���� ] ���� [ �ʺ��� ���] �� ���� �� ������ " << endl;
		break;

	case 2:
		weapons.push_back(new Gun());
		cout << " [ �ʺ��� ���� ] ȹ�� �Ͽ����ϴ�. " << endl;
		player.pickWeapon(weapons.back());
		cout << " [ �ʺ��� ���� ] �� [ ���� ] �� �־����ϴ�. " << endl;
		cout << " [ ���� ] ���� [ �ʺ��� ����] �� ���� �� ������ " << endl;
		break;
	default:
		cout << " �߸� �Է��߽��ϴ�. �ٽ� �Է��ϼ��� " << endl;
		return;
	}
}

// �÷��̾� ����
void Game::createCharacter()
{
	string name;
	cout << " ĳ���� �̸��� �Է��ϼ��� : ";
	cin >> name;
	player.setName(name);

	cout << " ĳ���͸� ���������� �����Ͽ����ϴ� ! " << endl;
}

// �������ͽ� ���
void Game::infoCharacter()
{
	cout << "--------------------------------" << endl;
	cout << "         ĳ �� �� �� ��         " << endl;
	cout << "--------------------------------" << endl;
	cout << "  ��    �� :  " << player.getName()<<endl;
	cout << "  ü    �� :  " << player.getHp()<<endl;
	cout << "  �� �� ġ :  " << player.getExp()<<endl;
	cout << "  ���빫�� :  " << player.getEquipWeapon()<<endl;
	cout << "------------------------------" << endl;
}

// ���� �⺻ �޴�
void Game::showMenu()
{
	int choice;

	do
	{
		cout << "------------------------------" << endl;
		cout << "   ���� �޴��� �������ּ���   " << endl;
		cout << "------------------------------" << endl;
		cout << "        1. ĳ���� ����        " << endl;
		cout << "        2. ���� ���        " << endl;
		cout << "        3. �� �� �� ��        " << endl;
		cout << "        4. �� �� �� ��        " << endl;
		cout << "        5. �� �� �� ��        " << endl;
		cout << "        0. �� �� �� ��        " << endl;
		cout << "------------------------------" << endl;
		cout << " ����� �Ͻǰǰ���? : ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << " ������ �����մϴ� " << endl;
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
			cout << " �ٽ� �Է��ϼ��� " << endl;
		}

	} while (choice != 0);
}

// ���� ����
void Game::huntMonster()
{
	vector<Monster*> monsters = { new Slime(), new Skeleton() };

	int choice;

	cout << "------------------------------" << endl;
	cout << "      ���͸� �����ϼ���     " << endl;
	cout << "------------------------------" << endl;
	
	for (int i = 0; i < monsters.size(); i++)
	{
		cout << i + 1 << ". " << monsters[i]->getType() 
			<< " (ü�� : " << monsters[i]->getHp() 
			<< ", ����ġ :" << monsters[i]->getExp() << ")" << endl;
	}

	cout << "          0. ���ư���         " << endl;
	cout << "------------------------------" << endl;
	cout << "             ���� :           ";
	cin >> choice;

	if (choice > 0 && choice <= monsters.size())
	{
		Monster* target = monsters[choice - 1];
		cout << target->getType() << " �� ������ ���� �մϴ�! " << endl;

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
			cout << " [ �¸� ! ] " << endl;
			player.addExp(target->getExp());
			player.levelUp();
		}
		else
		{
			cout << " [ �й� ! ] " << endl;
		}
	}

	for (Monster* monster : monsters)
	{
		delete monster;
	}
	
}

// �κ��丮 ��� �� ������ ����
void Game::showInventory()
{
	cout << "------------------------------" << endl;
	cout << "         �÷��̾� ����        " << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < weapons.size(); i++)
	{
		cout << i + 1 << ". " << weapons[i]->getWeaponName();
	}
	cout << " ���� �� �������� ����ּ���  " << endl;
	cout << "------------------------------" << endl;

	int choice;
	cin >> choice;

	if (choice > 0 && choice <= weapons.size())
	{
		player.equipWeapon(weapons[choice - 1]);
		cout << weapons[choice - 1]->getWeaponName() << " ��(��) �����߽��ϴ�. " << endl;
	}
}

// ���� ����
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
		cout << " [ ���� ���� �Ϸ� ] " << endl;
	}
	else
	{
		cout << " [ ���� ���� ���� ] " << endl;
	}
}

// ���� �ҷ�����
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
		cout << " [ ���� �ҷ����� �Ϸ� ] " << endl;
	}
}