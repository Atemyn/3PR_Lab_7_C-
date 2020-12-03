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
	initBuilding(secondStaticB);

	firstStaticB.addToBuilding(&secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
	/*............................................*/

	/* Работа с динамическими экземплярами класса. */
	Building* firstDynamicB = new Building;
	Building* secondDynamicB = new Building;

	cout << "Динамические экземпляры: " << endl << endl;

	firstDynamicB->inputBuilding();
	initBuilding(*secondDynamicB);

	firstDynamicB->addToBuilding(secondDynamicB);

	firstDynamicB->addFloors();
	firstDynamicB->removeFloors();
	// Очистка памяти.
	delete firstDynamicB;
	delete secondDynamicB;
	/*............................................*/

	/* Динамический массив объектов. */
	int amount = 2;
	Building* firstDynamicArray = new Building[amount];

	cout << "Динамический массив объектов: " << endl << endl;

	firstDynamicArray->inputBuilding();
	initBuilding(*(firstDynamicArray + 1));

	firstDynamicArray->addToBuilding((firstDynamicArray + 1));
	// Очистка памяти.
	delete[] firstDynamicArray;
	/*...............................*/

	/* Массив динамических объектов. */
	Building* firstArrayOfDyn[2];
	for (int i = 0; i < 2; i++)
	{
		// Выделение памяти двумя разными способами.
		firstArrayOfDyn[i] = new Building;
	}

	cout << "Массив динамических объектов: " << endl << endl;

	firstArrayOfDyn[0]->inputBuilding();
	initBuilding(*firstArrayOfDyn[1]);

	firstArrayOfDyn[0]->addToBuilding(firstArrayOfDyn[1]);

	for (int i = 0; i < 2; i++)
	{
		// Очистка памяти двумя разными способами.
		delete firstArrayOfDyn[i];
	}
	/*..............................*/
	/* Новые функции Ассоциации. */
	Building staticB;
	cout << "Новые функции Ассоциации: " << endl;

	staticB.inputBuilding();

	staticB.openWindowsOnFacade();
	staticB.closeWindowsOnFacade();
	/*..........................*/

	/* Возвращение значения из функции через указатель и через ссылку. */
	Building b1, b2;
	cout << "Возвращение значения из функции через указатель и через ссылку: " << endl;

	b1.inputBuilding();
	initBuilding(b2);
	// Вызов первого метода через указатель.
	b1.exchangeWindowsOnBuildings(&b2);

	cout << "Первое здание после первого обмена:" << endl;
	b1.getBuilding();

	cout << "Второе здание после первого обмена:" << endl;
	b2.getBuilding();
	// Вызов второго метода через ссылку.
	b1.exchangeWindowsOnBuildings(b2);

	cout << "Первое здание после второго обмена:" << endl;
	b1.getBuilding();

	cout << "Второе здание после второго обмена:" << endl;
	b2.getBuilding();
	/*................................................................*/

	/* Проверка условия с использованием this в функции addToBuilding. */
	cout << "Проверка условия с использованием this в функции addToBuilding:" << endl;
	b1.inputBuilding();
	b1.addToBuilding(&b1);
	/*.................................................................*/

	/* Использование дружественной классу Building функции initBuilding. */
	cout << "Использование дружественной классу Building функции Init:" << endl;
	initBuilding(b1);
	b1.getBuilding();
	/*...................................................................*/

	/* Проверка переопределенных операторов. */
	cout << "Проверка переопределенных операторов:" << endl;
	Building b3;

	b1.inputBuilding();
	initBuilding(b2);

	b3 = b1 + b2;
	
	b3.getBuilding();

	b1 = b3++;
	b2 = ++b3;

	b1.getBuilding();
	b2.getBuilding();
	/*......................................*/
	cin.get();
	return 0;
}