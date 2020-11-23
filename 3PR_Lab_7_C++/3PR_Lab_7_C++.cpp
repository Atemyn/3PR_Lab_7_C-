#include "Building.h"

int main()
{

	// Подключение русского консольного ввода.
	SetConsoleCP(1251);
	// Подключение русского консольного вывода.
	SetConsoleOutputCP(1251);

	/* Работа со статическими экземплярами класса. */
	Building firstStaticB, secondStaticB;

	cout << "Программа по созданию зданий." << endl << "Все размерные данные вводятся в метрах." << endl;
	cout << "Статические экземпляры: " << endl << endl;

	firstStaticB.inputBuilding();
	secondStaticB.initBuilding();

	firstStaticB.addToBuilding(secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
	/*............................................*/

	/* Работа с динамическими экземплярами класса. */
	Building* firstDynamicB = new Building;
	Building* secondDynamicB;
	// Выделение памяти через malloc.
	secondDynamicB = (Building*)malloc(sizeof(Building));

	cout << "Динамические экземпляры: " << endl << endl;

	firstDynamicB->inputBuilding();
	secondDynamicB->initBuilding();

	firstDynamicB->addToBuilding(*secondDynamicB);

	firstDynamicB->addFloors();
	firstDynamicB->removeFloors();
	// Очистка памяти двумя разными способами.
	delete firstDynamicB;
	free(secondDynamicB);
	/*............................................*/

	/* Динамический массив объектов. */
	int amount = 2;
	Building* firstDynamicArray = new Building[amount];
	Building* secondDynamicArray;

	cout << "Динамический массив объектов: " << endl << endl;

	firstDynamicArray->inputBuilding();
	(firstDynamicArray + 1)->initBuilding();

	firstDynamicArray->addToBuilding(*(firstDynamicArray + 1));

	// Аналог для выделения памяти по массив объектов.
	secondDynamicArray = (Building*)calloc(amount, sizeof(Building));
	if (secondDynamicArray != NULL)
	{
		secondDynamicArray = (Building*)realloc(secondDynamicArray, (amount + 2) * sizeof(Building));
		if (secondDynamicArray != NULL)
		{
			cout << "Четвертый элемент массива: " << endl;
			(secondDynamicArray + 3)->initBuilding();
			(secondDynamicArray + 3)->getBuilding();
		}
	}
	// Очистка памяти двумя разными способами.
	delete[] firstDynamicArray;
	free(secondDynamicArray);
	/*...............................*/

	/* Массив динамических объектов. */
	Building* firstArrayOfDyn[2], * secondArrayOfDyn[2];
	for (int i = 0; i < 2; i++)
	{
		// Выделение памяти двумя разными способами.
		firstArrayOfDyn[i] = new Building;
		secondArrayOfDyn[i] = (Building*)malloc(sizeof(Building));
	}

	cout << "Массив динамических объектов: " << endl << endl;

	firstArrayOfDyn[0]->inputBuilding();
	secondArrayOfDyn[1]->initBuilding();

	firstArrayOfDyn[0]->addToBuilding(*secondArrayOfDyn[1]);

	for (int i = 0; i < 2; i++)
	{
		// Очистка памяти двумя разными способами.
		delete firstArrayOfDyn[i];
		free(secondArrayOfDyn[i]);
	}
	/*..............................*/
	/* Новые функции Ассоциации. */
	Building staticB;
	cout << "Новые функции Ассоциации: " << endl;

	staticB.inputBuilding();

	staticB.openWindowsOnFacade();
	staticB.closeWindowsOnFacade();
	/*..........................*/
	cin.get();
	return 0;
}