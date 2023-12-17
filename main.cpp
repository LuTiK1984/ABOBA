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

void Choice2(int &choice) 
{
	do
	{
		printf("\n�...   ");
		scanf_s("%i", &choice);
	} while (choice != 1 && choice != 2);
}

void Check_Banana()
{
	printf("===> � ���� ������ �������: %i <===", player.bananas);
}

void Act_1__Begin() {
	PrintScript("\t����������� ������� ������ ���� ������� ��������� �������, \n� ����� ��� ��� �������� ��������� � ���� ������, \n��������� ���� ��������� � ���� ��������������� �������������. %", 60);
	PrintScript("\n��� ��������� ��������� ���� ��������� �� ��� ������� ��-����� (������� �����). %", 40);
	PrintScript("\n�������, �������� �������� ������ ������������ ������� ������� ������������ ���. %");
	PrintScript("\n� ��� � ����� - � ������ ���� �� �����������. %\n�������� �� ���� ���������, ��� ����� ������� ��������� ����, \n��� ������ ������� ���� ������ - �����(����� ������� - ��������� �������). %");

	PrintScript("\n\n\t��������� �� ����� � ������� ��������� ��������, � �����... %");
	int choice;

	printf("\n\n\t1 --- ����� �� �������� � ��� ---");
	printf("\n\t2 --- ����� �� ���� ---\n");

	Choice2(choice);

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

void Act_1__Go_to_walk()
{
	PrintScript("\t\n� ������ ���� �����, ������� � ����� ����������� �� ������� ����. %\n�� ������� �������, ��� ����� ����� �����������. %");
	PrintScript("\n����� ������ �������������� �� ��������, � ��� � �����, ��� ��� �� ���������� ���������� \n� ���� �� ����� � ���������� ������ �������, ���������� ������� �������� �������. %");

	PrintScript("\n\n\t��� �� ��� �����?... %");
	int choice;

	printf("\n\n\t1 --- ������� ���������� ������� ---");
	printf("\n\t2 --- ���������� ������������ ��� ��� ������������ ---\n");

	Choice2(choice);

	switch (choice)
	{
	case 1:
		Act_1__Take_Banana();
		break;
	case 2:
		player.hp += 1;
		Act_1__Dont_take_Banana();
		break;
	}
}

void Act_1__Take_Banana()
{
	PrintScript("\n\t� ������� � ������������ �������. ������ �� ��� ����������� ������ � ������ �������, � �����, ��� ��� �������. %");
	PrintScript("\n������ ���� ��� ���������, ����� � ��������� ������ ����� ������� 2 ������. %");
	player.bananas += 2;
	Check_Banana();
	Act_1__Dont_take_Banana();
}

void Act_1__Dont_take_Banana()
{
	PrintScript("\n\t������� ���������� �� ��� ����� � � �������� �� ������ �����. %\n������ ���������� �� ����, � ��������� ���� ������. %");
}
void Act_1__Go_to_para()
{
	
}
void main() 
{
	system("chcp 1251");
	system("mode 100, 80");
	
	Act_1__Begin();
	
}