#include <iostream>
#include <windows.h>

struct Player
{
	int hp = 5;
	int moral = 5;
	int bananas = 0;
}player;

void PrintScript(const char text[], int TimeToSleep = 20) 
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
	printf("\n\t===> � ���� ������ �������: %i <===\n", player.bananas);
}

void Check_Hp()
{
	printf("\n\t===> � ���� ������ ��������: %i <===\n", player.hp);
}

void Act_1__Go_to_para()
{
	PrintScript("\n\n\t������ ������������ � �������� ���� ���� � �������� �� ����. %");
	player.bananas += 1;
	Check_Banana();
	PrintScript("\n�� ���� � ���� ���������� ���, � ������� ������� ������� ���, ������� ������� ������� �� ����� �� ����� ������. %");
}

void Act_1__Dont_take_Banana()
{
	PrintScript("\n\t������� ���������� �� ��� ����� � � �������� �� ������ �����. %\n������ ���������� �� ����, � ��������� ���� ������. %");
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
	PrintScript("\n� ��� � ����� - � ������ ���� �� �����������. %\n�������� �� ���� ���������, ��� ����� ������� ��������� ����, \n��� ������ ������� ���� ������ - �����(����� ������� - ��������� �������). %");

	PrintScript("\n\n\t��������� �� ����� � ������� ��������� ��������, � �����... %");
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

int main() 
{
	system("chcp 1251");
	system("mode 100, 80");
	
	Act_1__Begin();
	
	return 0;
}