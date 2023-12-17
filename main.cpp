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
		printf("\nЯ...   ");
		scanf_s("%i", &choice);
	} while (choice != 1 && choice != 2);
}

void Check_Banana()
{
	printf("\n\n\t===> У меня теперь бананов: %i <===\n", player.bananas);
}

void Check_Hp()
{
	printf("\n\n\t===> У меня теперь здоровья: %i <===\n", player.hp);
}



void Act1__End()
{
	PrintScript("\n\n\tС горем пополам я оказался в стенах родного ВУЗа и поспешил на первую пару. %\nЗайдя в лекционную, я быстро занял первое попавшееся свободное место. %");
}

void Act1__DontHelp()
{
	PrintScript("\n\n\tЯ оценил, что времени у меня в обрез и решил не махаться с этой проблемой. %\nЯ продолжил свой путь в гордом одиночистве. %");
	Act1__End();
}

void Act1__Help()
{
	PrintScript("\n\n\tЯ не стал медлить и спросил нужна ли ему моя помощь. %\nОн кивнул и попросил подтолкнуть его. %");
	PrintScript("\nСовместными усилиями, забороли проблему... %\nМужик решил отблагодарить меня и подвезти до университета. %");
	PrintScript("\nПокидая транспорт, я навернулся на ледяной глыбе и ушибся коленом. %");
	Check_Hp();
	Act1__End();
}

void Act_1__Go_to_para()
{
	PrintScript("\n\n\tНаспех переодевшись я захватил свой обед и поспешил на пары. %");
	player.bananas += 1;
	Check_Banana();
	PrintScript("\nПо пути в свой прекрасный ВУЗ, я заметил мужчину средних лет, \nкоторый пытался выехать со двора на своей машине. %");
	PrintScript("\n\n\tА если...");
	printf("\n\n\t1 --- Помогу мужику ---");
	printf("\n\t2 --- Поспешу в университет ---\n");
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
	PrintScript("\n\tВремени оставалось не так много и я поспешил на родное Ранчо. %\nБыстро добравшись до дома, я продолжил свою рутину. %");
	Act_1__Go_to_para();
}

void Act_1__Take_Banana()
{
	PrintScript("\n\tЯ подошел к неизвестному объекту. Увидев на нем изображение сочных и спелых бананов, я понял, что это коробка. %");
	PrintScript("\nКакого было мое удивление, когда я обнаружил внутри сырой коробки 2 банана. %");
	player.bananas += 2;
	Check_Banana();
	Act_1__Dont_take_Banana();
}

void Act_1__Go_to_walk()
{
	PrintScript("\t\nВ голове было пусто, поэтому я решил пробежаться по зимнему лесу. %\nОт свежего воздуха, мой разум начал проясняться. %");
	PrintScript("\nМысли начали раскладываться по полочкам, и тут я понял, что уже на протяжении полуминуты \nя стою на месте и пристально изучаю предмет, непонятной сонному человеку природы. %");

	PrintScript("\n\n\tЧто же это такое?... %");
	int choice;

	printf("\n\n\t1 --- Изучу непонятный предмет ---");
	printf("\n\t2 --- Продолжу отрезвляющую ото сна деятельность ---\n");

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
	PrintScript("\tПопытавшись сделать первый вдох свежего утреннего воздуха, \nя понял что мои альвиолы спутались в один клубок, \nзаставляя меня окунуться в муки безкислородного существования. %", 60);
	PrintScript("\nЭти страдания заставили меня взглянуть на мир немного по-иному (открыть глаза). %", 40);
	PrintScript("\nМонитор, подобный палящему солнцу окончательно развеял остатки мучительного сна. %");
	PrintScript("\nИ тут я понял - я заснул сидя за компьютером. %\nВзглянув на дату календаря, мой разум озарило понимание того, \nчто настал тщетный день недели - среда(иными словами - маленькая пятница). %");

	PrintScript("\n\n\tПосмотрев на время и осознав отсутсвие евонного, я решил... %");
	int choice;

	printf("\n\n\t1 --- Пойду на пробежку в лес ---");
	printf("\n\t2 --- Пойду на пару в ВУЗ ---\n");

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