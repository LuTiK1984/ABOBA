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
		printf("\nЯ...   ");
		scanf_s("%i", &choice);
	} while (choice != 1 && choice != 2);
}

void Check_Banana()
{
	printf("===> У меня теперь бананов: %i <===", player.bananas);
}

void Act_1__Begin() {
	PrintScript("\tПопытавшись сделать первый вдох свежего утреннего воздуха, \nя понял что мои альвиолы спутались в один клубок, \nзаставляя меня окунуться в муки безкислородного существования. %", 60);
	PrintScript("\nЭти страдания заставили меня взглянуть на мир немного по-иному (открыть глаза). %", 40);
	PrintScript("\nМонитор, подобный палящему солнцу окончательно развеял остатки мучительного сна. %");
	PrintScript("\nИ тут я понял - я заснул сидя за компьютером. %\nВзглянув на дату календаря, мой разум озарило понимание того, \nчто настал тщетный день недели - среда(иными словами - маленькая пятница). %");

	PrintScript("\n\n\tПосмотрев на время и осознав отсутсвие евонного, я решил... %");
	int choice;

	printf("\n\n\t1 --- Пойду на пробежку в лес ---");
	printf("\n\t2 --- Пойду на пары ---\n");

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
	PrintScript("\t\nВ голове было пусто, поэтому я решил пробежаться по зимнему лесу. %\nОт свежего воздуха, мой разум начал проясняться. %");
	PrintScript("\nМысли начали раскладываться по полочкам, и тут я понял, что уже на протяжении полуминуты \nя стою на месте и пристально изучаю предмет, непонятной сонному человеку природы. %");

	PrintScript("\n\n\tЧто же это такое?... %");
	int choice;

	printf("\n\n\t1 --- Изучить непонятный предмет ---");
	printf("\n\t2 --- Продолжить отрезвляющую ото сна деятельность ---\n");

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
	PrintScript("\n\tЯ подошел к неизвестному объекту. Увидев на нем изображение сочных и спелых бананов, я понял, что это коробка. %");
	PrintScript("\nКакого было мое удивление, когда я обнаружил внутри сырой коробки 2 банана. %");
	player.bananas += 2;
	Check_Banana();
	Act_1__Dont_take_Banana();
}

void Act_1__Dont_take_Banana()
{
	PrintScript("\n\tВремени оставалось не так много и я поспешил на родное Ранчо. %\nБыстро добравшись до дома, я продолжил свою рутину. %");
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