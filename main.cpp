#include <iostream>
#include <windows.h>

void PrintScript(const char text[]) {

	for (int i = 0; text[i] != '\0'; i++)
	{
		printf("%c", text[i]);
		Sleep(100);
	}

}


void main() 
{
	system("chcp 1251");


	PrintScript("Иди нахуй сука\n");

	system("pause > null");
}