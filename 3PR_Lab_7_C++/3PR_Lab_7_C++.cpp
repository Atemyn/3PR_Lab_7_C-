#include "Building.h"

int main()
{

	// ����������� �������� ����������� �����.
	SetConsoleCP(1251);
	// ����������� �������� ����������� ������.
	SetConsoleOutputCP(1251);

	/* ������ �� ������������ ������������ ������. */
	Building firstStaticB, secondStaticB;

	cout << "��������� �� �������� ������." << endl << "��� ��������� ������ �������� � ������." << endl;
	cout << "����������� ����������: " << endl << endl;

	firstStaticB.inputBuilding();
	secondStaticB.initBuilding();

	firstStaticB.addToBuilding(&secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
	/*............................................*/

	/* ������ � ������������� ������������ ������. */
	Building* firstDynamicB = new Building;
	Building* secondDynamicB;
	// ��������� ������ ����� malloc.
	secondDynamicB = (Building*)malloc(sizeof(Building));

	cout << "������������ ����������: " << endl << endl;

	firstDynamicB->inputBuilding();
	secondDynamicB->initBuilding();

	firstDynamicB->addToBuilding(secondDynamicB);

	firstDynamicB->addFloors();
	firstDynamicB->removeFloors();
	// ������� ������ ����� ������� ���������.
	delete firstDynamicB;
	free(secondDynamicB);
	/*............................................*/

	/* ������������ ������ ��������. */
	int amount = 2;
	Building* firstDynamicArray = new Building[amount];
	Building* secondDynamicArray;

	cout << "������������ ������ ��������: " << endl << endl;

	firstDynamicArray->inputBuilding();
	(firstDynamicArray + 1)->initBuilding();

	firstDynamicArray->addToBuilding((firstDynamicArray + 1));

	// ������ ��� ��������� ������ �� ������ ��������.
	secondDynamicArray = (Building*)calloc(amount, sizeof(Building));
	if (secondDynamicArray != NULL)
	{
		secondDynamicArray = (Building*)realloc(secondDynamicArray, (amount + 2) * sizeof(Building));
		if (secondDynamicArray != NULL)
		{
			cout << "��������� ������� �������: " << endl;
			(secondDynamicArray + 3)->initBuilding();
			(secondDynamicArray + 3)->getBuilding();
		}
	}
	// ������� ������ ����� ������� ���������.
	delete[] firstDynamicArray;
	free(secondDynamicArray);
	/*...............................*/

	/* ������ ������������ ��������. */
	Building* firstArrayOfDyn[2], * secondArrayOfDyn[2];
	for (int i = 0; i < 2; i++)
	{
		// ��������� ������ ����� ������� ���������.
		firstArrayOfDyn[i] = new Building;
		secondArrayOfDyn[i] = (Building*)malloc(sizeof(Building));
	}

	cout << "������ ������������ ��������: " << endl << endl;

	firstArrayOfDyn[0]->inputBuilding();
	secondArrayOfDyn[1]->initBuilding();

	firstArrayOfDyn[0]->addToBuilding(secondArrayOfDyn[1]);

	for (int i = 0; i < 2; i++)
	{
		// ������� ������ ����� ������� ���������.
		delete firstArrayOfDyn[i];
		free(secondArrayOfDyn[i]);
	}
	/*..............................*/
	/* ����� ������� ����������. */
	Building staticB;
	cout << "����� ������� ����������: " << endl;

	staticB.inputBuilding();

	staticB.openWindowsOnFacade();
	staticB.closeWindowsOnFacade();
	/*..........................*/

	/* ����������� �������� �� ������� ����� ��������� � ����� ������. */
	Building b1, b2;
	cout << "����������� �������� �� ������� ����� ��������� � ����� ������: " << endl;

	b1.inputBuilding();
	b2.initBuilding();
	// ����� ������� ������ ����� ���������.
	b1.exchangeWindowsOnBuildings(&b2);

	cout << "������ ������ ����� ������� ������:" << endl;
	b1.getBuilding();

	cout << "������ ������ ����� ������� ������:" << endl;
	b2.getBuilding();
	// ����� ������� ������ ����� ������.
	b1.exchangeWindowsOnBuildings(b2);

	cout << "������ ������ ����� ������� ������:" << endl;
	b1.getBuilding();

	cout << "������ ������ ����� ������� ������:" << endl;
	b2.getBuilding();
	/*................................................................*/

	/* �������� ������� � �������������� this � ������� addToBuilding. */
	cout << "�������� ������� � �������������� this � ������� addToBuilding:" << endl;
	b1.inputBuilding();
	b1.addToBuilding(&b1);
	/*.................................................................*/
	cin.get();
	return 0;
}