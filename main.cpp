#include <iostream>
#include <windows.h>
#include <ctime>


#pragma region Funcs
struct Player
{
	int hp = 5;
	int moral = 5;
	int bananas = 0;
}player;

void PrintScript(const char text[], int TimeToSleep = 10) 
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == '%') { 
			system("pause > null"); 
			continue;
		}
		printf("%c", text[i]);
		Sleep(TimeToSleep);
	}
}

void Choice(int &choice) 
{
	do
	{
		printf("\n�...   ");
		scanf_s("%i", &choice);
	} while (choice != 1 && choice != 2);
}

void Check_Banana()
{
	printf("\n\n\t===> � ���� ������ �������: %i <===\n", player.bananas);
}

void Check_Hp()
{
	printf("\n\n\t===> � ���� ������ ��������: %i <===\n", player.hp);
}
#pragma endregion



#pragma region Act3

void Act_3__GoneEnd()
{
	PrintScript("\n\n\t������ ��� ��������� ����������� �������� �����. %� ��� ������, \n��� ��� ���������� ����... ���������� ����,  � ����� ��� �������. %");
	player.hp -= 1;
	player.moral -= 1;
	Check_Hp();
}

void Act_3__WinBOMG() 
{
	PrintScript("\n\n\t������� �������� ������ ������ �� ��������� ����� ����� ���� ������� ��������� ���������. %\n�� �������� �� �����, ������� ��������� �������� �������. %");
	PrintScript("\n������ ���� ����� ������ ������, �� ��� ������, ��� ������ ������� �. %\n��������� �������, � ����� ������ ���� ����, �� ������ ���������. %");
	PrintScript("\n��� ������� ��� �� ���� ��� �������... %����� ���������� �����-��, \n�� ����� ����� ������������ �� ������������� ��������� �����. %");
	PrintScript("\n������� ��� ������� ��� �������� �� � ���, �� ����������, �� ��������� �� �����. %\n���������� �������� �������, � ������� � ������, � ������ �����... %");
	Act_3__GoneEnd();
}

void Act_3__LoseBOMG()
{
	player.moral -= 1;
	PrintScript("\n\n\t������� �������� ������ ������ �� ��������� ����� ����� ���� ������� ��������� ���������. %\n�� �������� �� �����, ������� ��������� �������� �������. %");
	PrintScript("\n������ ���� ����� ������ ������, �� ��� ������, ��� ������ ������� ��� ������. %\n���� ������ �� ���� �������, ������ �������������. %");
	PrintScript("\n�� �������� ������ ��������, � � ������ ������� ����� � ������� ����. %");
	Act_3__GoneEnd();
}

void Act_3__Go_to_park()
{
	PrintScript("\n\n\t���� �������� � ����� ���������� ��� ��������. %\n� ������ ������� �� ���������� ����� � ������ ������ ��������� �����. %");
	PrintScript("\n� ����� ��������� ������������. ������ �� ��������, %\n� �������, ��� ����� �� ���� ��������� ������������ ������ �������� (����). %");
	PrintScript("\n���� ������� ����� ������ ��������������� ����� �����. %\n� ������ ����� ������������� ���������� ��������� ��������� �������� � �������� ���� ��������. %");
	PrintScript("\n� �����, ��� ��� ����� ������ � ������ �� ����!! %\n������� ��������� ����������, � ���������������, ����� �� �� ���������� �������. %");
	PrintScript("\n� ����� �� ��� �������� �� ����� �������, � ������� ������ �����. %\n� ��� ������ �������� ����� ���������. %");
	PrintScript("\n���������� ������ ��������� � ����, � ����� �������� � ������. %");
	
	int fight = rand()%(2-1+1)+1;
	
	if (fight == 1)
	{
		Act_3__WinBOMG();
	}
	else
	{
		Act_3__LoseBOMG();
	}
}

void Act_3__Go_to_monastery()
{
	PrintScript("\n\n\t�� ���� �������� ��������. %� ����� ����� ��������� �������������� ��������� � �������. %");
	PrintScript("\n��� ����������� ���� �������� ������� ������ ����� �� ��� �����. %\n�� � ����� ������� ���� ����� ������, � ����� ��� ���� �������� ������ ���������.... %");
	PrintScript("\n������� ������� ��� � ���� �������������� ������, � ������� ��� ����� � ��� ������ ��������� ������ ������. %");
	PrintScript("\n�� �������� � ������� ������ ��� �������� �������, ������������ � ���������� \n��� ���������� ��� � �����, � ������� ������ ��� ����� ����������. %");
	PrintScript("\n����� ��� ��������, ��� �� ��������� ������ ����� ������ ���� � ������ ����� �������, ��� �� �� ������. %");
}

void Act_3__Gone()
{
	
	int choice;
	
	Choice(choice);

	switch (choice)
	{
	case 1:
		Act_3__Go_to_park();
		break;
	case 2:
		Act_3__Gone_to_monastery();
		break;
	}
}

void Minesweeper()
{

}

void Act_3__SweeperWin()
{
	PrintScript("\n\n\t� ������� � �����, ��� �������� ��� ����� ���. %������ ���� � ��������� � ����� ����� �� ������. %");
	PrintScript("\n��� ���� ������������� ���� �������. %� ��� ������ ��������� ������ ������. %\n� ���� ��� ��� ������ �������� ��������� ������� �������������.");
	Act_3__Gone();
}

void Act_3__SweeperLose()
{
	PrintScript("� ������� � ������� �������� �����. %\"������, ��� � �������� �� �������� ?\" - ����������� �. %\n�� ����� ����� ����������� ����, � ����� �����������. %");
	Act_3__Gone();
}

void Act_3__Stay()
{
	PrintScript("\n\n\t��� �� ����������� �� ���� �� ���� ����� � �, ��� ���������� �������, ����� �������� �� �����. \n��������� �� ��������, �, ��������-��������� ���������� � ������ �������� �������. %");
	PrintScript("\n\n\t..... %", 5);
	PrintScript("\n���� � ������� ���� �� �������� ����, ��� ����������� ����������� �������. %\n� ���� ��������. %������ �� ���� ����� ��� ������ ������� ������. %");
	PrintScript("\n�� ���� ����� � ������� �����, � ��� ���� �������� ������. %\n��� ��� ����������, 1988 ���. %");
	PrintScript("\n\"������!!!\" - ����� ��������� ������. � ��������� ����������. %\n�� ������ ��� ��������� �� �������� �������� �������: %\n\"������� ������� ��������... ����, �� ������, ��� ����� ���� ��������� � �� ��������� �����...\". %");
	PrintScript("\n��� ����� ���� ����� ������������ �������, ������� �. %�������� ����� �� ������ � �����������. %\n���-�� � ��� ����� ������� ��������... ����� � ��������, ��� ������ ����� �������� ��� ���������� �� �������. %");
	PrintScript("\n��� ���� ������ ����. %� ���������� ������� ������, ������� ��� �� ����� � ����� � ������� ��������. %\n��������� ����� ������ �������� ��������� � ���� ������, ��� ���� ���������� \"��������!\". %");
	PrintScript("\n������ ���� ���� �������. %��� �������� �������������. %\n��� ������������� ������ ����. %� ��������� � ��� ��������������. %");
	
	Minesweeper();
	bool MinesweeperIsWin = true;
	
	if (MinesweeperIsWin) Act_3__SweeperWin();
	else {player.moral -= 1; Act_3__SweeperLose();}
}

#pragma endregion

#pragma region Act2

void Act_2__End()
{
	PrintScript("\n\n\t�� ������ ������, ��� ��� ����� ������ ������. � �������� ���� ������: %");

	int choice;
	
		printf("\n\n\t1 --- ����� ������ ���� ---");
		printf("\n\t2 --- �������� �� ����� ---\n");
	if (player.moral >= 6) 
	{
		printf("\t3 --- ���� ������ ---\n");
		do
		{
			printf("\n�...   ");
			scanf_s("%i", &choice);
		} while (choice != 1 && choice != 2 && choice != 3);
	}
	else Choice(choice);

	switch (choice) 
	{
	case 1:
		PrintScript("\n\n\t��� �� ����������� ���� ����� � � ����� �������� ����. %������� ����� ����, � ��������� ���� ��������� ���. %");
		Act_3__Gone();
		break;
	case 2:
		Act_3__Stay();
		break;
	case 3:

		break;
	}

}

void KNB()
{

}

void Act_2__Begin()
{
	PrintScript("\n\n\t����� ��������� ����� � ��������� �������� ������. %\n�� ���� � ���� ��� � �������� �� ����� ���� ����������� ������. %");
	PrintScript("\n� ������ �������, ��� ������ ��� ����� ������ � ����� �������� ������. %\n� ���� � ���� �������� �, �������� ���, �������� ������������ � ������� ��� ��� ������ �� ��. %");
	PrintScript("\n������ ��� ��� �������, ������� ���� � ����� �������� �� ��������� ���������. %\n��� ����� ������������ �� ����� ����, � ����� ������������� ������� � ����� ������, \n� ����� ������� �� ��������� � ����������� ������� ��� ���������. %");
	PrintScript("\n��� � ������� �������� ����� ������. %���� �� ��� ��� �������� ����������. %\n������ �������� ����� ����������, ������� �. %");
	PrintScript("\n�� �������� � ���� �����, �� ������ ��� �������� ��� � �� �����. %\n�� ������ ������� � ����� �������� ����, ������� � ������� ����� �����. %");
	KNB();
	Act_2__End();
}

#pragma endregion

#pragma region Act1

void Act1__End()
{
	PrintScript("\n\n\t� ����� ������� � �������� � ������ ������� ���� � �������� �� ������ ����. %\n����� � ����������, � ������ ����� ������ ���������� ��������� �����. %");
	Act_2__Begin();
}

void Act1__DontHelp()
{
	PrintScript("\n\t� ������, ��� ������� � ���� � ����� � ����� �� �������� � ���� ���������. %\n� ��������� ���� ���� � ������ �����������. %");
	Act1__End();
}

void Act1__Help()
{
	PrintScript("\n\t� �� ���� ������� � ������� ����� �� ��� ��� ������. %\n�� ������ � �������� ����������� ���. %");
	PrintScript("\n����������� ��������, �������� ��������... %\n����� ����� ������������� ���� � �������� �� ������������. %");
	PrintScript("\n������� ���������, � ���������� �� ������� ����� � ������ �������. %");
	Check_Hp();
	Act1__End();
}

void Act_1__Go_to_para()
{
	PrintScript("\n\n\t������ ������������ � �������� ���� ���� � �������� �� ����. %");
	player.bananas += 1;
	Check_Banana();
	PrintScript("\n�� ���� � ���� ���������� ���, � ������� ������� ������� ���, \n������� ������� ������� �� ����� �� ����� ������. %");
	PrintScript("\n\n\t� ����...");
	printf("\n\n\t1 --- ������ ������ ---");
	printf("\n\t2 --- ������� � ����������� ---\n");
	int choice;
	Choice(choice);

	switch (choice)
	{
	case 1:
		player.moral += 1;
		player.hp -= 1;
		Act1__Help();
		break;
	case 2:
		player.moral -= 1;
		Act1__DontHelp();
		break;
	}
}

void Act_1__Dont_take_Banana()
{
	PrintScript("\n\t������� ���������� �� ��� ����� � � �������� �� ������ �����. %\n������ ���������� �� ����, � ��������� ���� ������. %");
	Act_1__Go_to_para();
}

void Act_1__Take_Banana()
{
	PrintScript("\n\t� ������� � ������������ �������. ������ �� ��� ����������� ������ � ������ �������, � �����, ��� ��� �������. %");
	PrintScript("\n������ ���� ��� ���������, ����� � ��������� ������ ����� ������� 2 ������. %");
	player.bananas += 2;
	Check_Banana();
	Act_1__Dont_take_Banana();
}

void Act_1__Go_to_walk()
{
	PrintScript("\t\n� ������ ���� �����, ������� � ����� ����������� �� ������� ����. %\n�� ������� �������, ��� ����� ����� �����������. %");
	PrintScript("\n����� ������ �������������� �� ��������, � ��� � �����, ��� ��� �� ���������� ���������� \n� ���� �� ����� � ���������� ������ �������, ���������� ������� �������� �������. %");

	PrintScript("\n\n\t��� �� ��� �����?... %");
	int choice;

	printf("\n\n\t1 --- ����� ���������� ������� ---");
	printf("\n\t2 --- �������� ������������ ��� ��� ������������ ---\n");

	Choice(choice);

	switch (choice)
	{
	case 1:
		Act_1__Take_Banana();
		break;
	case 2:
		player.hp += 1;
		Check_Hp();
		Act_1__Dont_take_Banana();
		break;
	}
}

void Act_1__Begin() {
	
	PrintScript("\t����������� ������� ������ ���� ������� ��������� �������, \n� ����� ��� ��� �������� ��������� � ���� ������, \n��������� ���� ��������� � ���� ��������������� �������������. %", 60);
	PrintScript("\n��� ��������� ��������� ���� ��������� �� ��� ������� ��-����� (������� �����). %", 40);
	PrintScript("\n�������, �������� �������� ������ ������������ ������� ������� ������������ ���. %");
	PrintScript("\n� ��� � ����� - � ������ ���� �� �����������. %\n�������� �� ���� ���������, ��� ����� ������� ��������� ����, \n��� ������ ������� ���� ������ - ����� (����� ������� - ��������� �������). %");

	PrintScript("\n\n\t��������� �� ����� � ������� ��� ���������, � �����... %");
	int choice;

	printf("\n\n\t1 --- ����� �� �������� � ��� ---");
	printf("\n\t2 --- ����� �� ���� � ��� ---\n");

	Choice(choice);

	switch (choice)
	{
	case 1:
		Act_1__Go_to_walk();
		break;
	case 2:
		Act_1__Go_to_para();
		break;
	}
}

#pragma endregion

int main() 
{
	system("chcp 1251");
	system("mode 100, 80");
	int seed = time(NULL);
	srand(seed);
	
	Act_1__Begin();
	
	return 0;
}