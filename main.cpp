#include <iostream>
#include <windows.h>

void PrintScript(const char text[], int TimeToSleep = 50) 
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		printf("%c", text[i]);
		Sleep(TimeToSleep);
	}
}


void main() 
{
	system("chcp 1251");

	PrintScript("Иди нахуй сука\n");
	PrintScript("Вы точно хотите съесть бананы?\n", 180);

	system("pause > null");
}