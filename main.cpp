#include <iostream>
#include <windows.h>

void PrintScript(const char text[],int TimeToSleep) {

	for (int i = 0; text[i] != '\0'; i++)
	{
		printf("%c", text[i]);
		Sleep(TimeToSleep);
	}

}


void main() 
{
	system("chcp 1251");


	PrintScript("��� ����� ����\n",10);
	PrintScript("��� ����� ����\n", 50);
	PrintScript("��� ����� ����\n", 100);

	system("pause > null");
}