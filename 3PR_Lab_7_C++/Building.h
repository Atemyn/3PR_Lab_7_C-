#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Facade.h"

using namespace std;

class Building
{
private:
	// ��� ������.
	string typeOfBuilding;
	// ����� ������� ���������.
	float sideLength;
	// ������ ����������.
	float basementHeight;
	// ������ �����.
	float floorHeight;
	// ���������� ������.
	int floorAmount;
	// ������ ������ ������ ������, ���������� ���������� �� ����� ������.
	Facade facade;
	// ����������� ������������.
	float stabilityFactor;
	/* ������� �� ��������� ���������� �������� � �������� ���������� ������ Building. */
	void setBuiling(string typeOfBuilding, float sideLength, float basementHeight, float floorHeight, unsigned floorAmount, float stabilityFactor)
	{
		this->typeOfBuilding = typeOfBuilding;
		this->sideLength = sideLength;
		this->basementHeight = basementHeight;
		this->floorHeight = floorHeight;
		this->floorAmount = floorAmount;
		this->stabilityFactor = stabilityFactor;
	}
public:
	/* ������� �� ������ ������� ���������� ������ Building. */
	void getBuilding()
	{
		cout << "�������� ������� ������:" << endl;
		cout << "��� ������: " << typeOfBuilding << endl;
		cout << "����� ������� ���������: " << sideLength << endl;
		cout << "������ ����������: " << basementHeight << endl;
		cout << "������ �����: " << floorHeight << endl;
		cout << "���������� ������: " << floorAmount << endl;
		facade.getFacade();
		cout << "����������� ������������: " << stabilityFactor << endl << endl;
	}
	/* ������� �� ������� ������� �� ��������� ���������� ������ Building. */
	friend void initBuilding(Building &building)
	{
		building.setBuiling("����� ������", 1.0, 1.0, 1.0, 1, 1.0);
		building.facade.setFacade(0, 0);
	}
	/* ������� �� ����� � ���������� ������� ��� ���������� ������ Building */
	void inputBuilding()
	{
		// ������ �� ������ ��� ����� ���� ����������� ������.
		cout << "������� ��� ������ ������ (� ���� ������): ";
		cin >> typeOfBuilding;
		cin.clear();
		rewind(stdin);

		cout << "������� ����� ������� ������ ������: ";
		while (!(cin >> sideLength) || cin.get() != '\n' || sideLength <= 0)
		{
			cout << "�������� ���� ����� ������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "������� ������ ���������� ������ ������: ";
		while (!(cin >> basementHeight) || cin.get() != '\n' || basementHeight <= 0)
		{
			cout << "�������� ���� ������ ���������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "������� ������ ������ ����� ������ ������: ";
		while (!(cin >> floorHeight) || cin.get() != '\n' || floorHeight <= 0)
		{
			cout << "�������� ���� ������ ����� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "������� ���������� ������ ������ ������: ";
		while (!(cin >> floorAmount) || cin.get() != '\n' || floorAmount <= 0)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ������������� ����� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}
		facade.inputFacade();
		// ������ ����������� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		// ���� ����������� ������������ ������ 1 - ������ ������; ��������� ��������� ���� �������������
		if (stabilityFactor < 1.0)
		{
			cout << "����������� ������������ ������ ������ k = " << stabilityFactor << " ������ �������. ��� ����� ������� � ������ �� ������. ������ �� ����������� ���?" << endl;
			cout << "���� ��� - ������� Esc, ���� �� - ����� ������ ������." << endl << endl;
			if (_getch() != 27)
			{
				inputBuilding();
			}
			else
			{
				cout << "������ �� ������ ������� � �������!" << endl << endl << endl;
				initBuilding(*this);
			}
		}
		else
		{
			cout << "�������! ������ ���������� ���������� � ������������� ������������ k = " << stabilityFactor << "." << endl << endl << endl;
		}
	}
	/* ������� �� �������� ���� ����������� ������ Building, ��� build - ���������, ������� ����� ������������. */
	void addToBuilding(Building *build)
	{
		if (this == build)
		{
			cout << "�� �� ������ ������� ������ ���� � �����!" << endl;
			return;
		}
		cout << "��������� ��� ������... �� �������� �����:" << endl;
		cout <<"���� ������: " << typeOfBuilding << " � " << build->typeOfBuilding << endl << "����� ������ ���������: " << sideLength << " � " << build->sideLength << endl <<
			"������ �����������: " << basementHeight << " � " << build->basementHeight << endl << "������ ������: " << floorHeight << " � " << build->floorHeight << endl <<
			"���������� ������: " << floorAmount << " � " << build->floorAmount << endl << "������������ ������������: " << stabilityFactor << " � " << build->stabilityFactor << endl <<
			"����� ���������� ����: " << facade.getWindowsAmount() << " � " << build->facade.getWindowsAmount() << endl <<
			"���������� �������� ����: " << facade.getOpenedWindowsAmount() << " � " << build->facade.getOpenedWindowsAmount() << endl << endl;

		typeOfBuilding = typeOfBuilding + " " + build->typeOfBuilding;

		if (sideLength < build->sideLength)
			sideLength = build->sideLength;

		if (basementHeight < build->basementHeight)
			basementHeight = build->basementHeight;

		if (floorHeight < build->floorHeight)
			floorHeight = build->floorHeight;

		floorAmount = floorAmount + build->floorAmount;

		facade.addToFacade(build->facade);
		// ������ ������ ������������ ������������ � �������� ��� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1)
		{
			cout << "� ���������, ����� ���������� ���� ������ ����� ������ ����� �� �����������, ��� ��� ��� ����������� ������������ k = " << stabilityFactor << " ������ ����." << endl << endl;
			initBuilding(*this);
		}
		else
		{
			cout << "�������! ����� ������ �������. ��� �������� �����:" << endl << endl;
			getBuilding();
		}
	}
	/* ������� �� ���������� floorsToAdd ������ ���������� ������ Building. */
	void addFloors()
	{
		unsigned floorsToAdd;
		// ������ �� ������ ��� ����� floorsToAdd.
		cout << "������� ���������� ������ ��� ���������� � ������ ������: ";
		while (!(cin >> floorsToAdd) || cin.get() != '\n' || floorsToAdd < 0)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ��������������� ����� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}

		floorAmount = floorAmount + floorsToAdd;
		// ������ ������ ������������ ������������ � �������� ��� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1.0)
		{
			cout << "����������� ������������ ������ ������ k = " << stabilityFactor <<
				" ���� ������ �������.\n��� ����� ������� � ������ �� ������. ���������� �������� ���������� ������ � ���������� (��������, �� 0)" << endl << endl;
			floorAmount = floorAmount - floorsToAdd;
			addFloors();
		}
		else
		{
			cout << "�������! ������ ���������� ���������� � ������������� ������������ k = " << stabilityFactor << endl << endl;
			// ����������� ���������� � ������.
			getBuilding();
		}
	}

	/* ������� �� �������� floorsToRemove ������ � ���������� ������ Building. */
	void removeFloors()
	{
		int floorsToRemove;
		// ������ �� ������ ��� ����� floorsToRemove.
		cout << "������� ���������� ������ ��� �������� � ������ ������: ";
		while (!(cin >> floorsToRemove) || cin.get() != '\n' || floorsToRemove < 0 || floorsToRemove >= floorAmount)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ��������������� ����� ������ � ������� ������ ����� ������. ���������� ��� ���: ";
			cin.clear();
			rewind(stdin);
		}
		// ������ ������ ������������ ������������.
		floorAmount = floorAmount - floorsToRemove;
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		cout << "����� ������� �������!" << endl;
		// ����������� ���������� � ������.
		getBuilding();
	}

	void openWindowsOnFacade()
	{
		facade.openWindows();
		getBuilding();
	}

	void closeWindowsOnFacade()
	{
		facade.closeWindows();
		getBuilding();
	}

	int getWindowsAmount()
	{
		return facade.getWindowsAmount();
	}

	int getOpenedWindowsAmount()
	{
		return facade.getOpenedWindowsAmount();
	}

	void setFacade(int windAmount, int opWindAmount)
	{
		facade.setFacade(windAmount, opWindAmount);
	}

	void exchangeWindowsOnBuildings(Building* building)
	{
		int windows, opened;

		windows = building->getWindowsAmount();
		opened = building->getOpenedWindowsAmount();

		building->setFacade(this->getWindowsAmount(), this->getOpenedWindowsAmount());

		this->facade.setFacade(windows, opened);
	}

	void exchangeWindowsOnBuildings(Building& building)
	{
		int windows, opened;

		windows = building.getWindowsAmount();
		opened = building.getOpenedWindowsAmount();

		building.setFacade(this->getWindowsAmount(), this->getOpenedWindowsAmount());

		this->facade.setFacade(windows, opened);
	}

	friend Building operator+(Building b1, Building b2)
	{
		Building resultB;

		b1.typeOfBuilding = b1.typeOfBuilding + " " + b2.typeOfBuilding;

		if (b1.sideLength > b2.sideLength)
			resultB.sideLength = b1.sideLength;
		else
			resultB.sideLength = b2.sideLength;

		if (b1.basementHeight > b2.basementHeight)
			resultB.basementHeight = b1.basementHeight;
		else
			resultB.basementHeight = b2.basementHeight;

		if (b1.floorHeight > b2.floorHeight)
			resultB.floorHeight = b1.floorHeight;
		else
			resultB.floorHeight = b2.floorHeight;

		resultB.floorAmount = b1.floorAmount + b2.floorAmount;

		resultB.facade = b1.facade;
		resultB.facade.addToFacade(b2.facade);
		// ������ ������ ������������ ������������ � �������� ��� ������������.
		resultB.stabilityFactor = (float)(resultB.sideLength * resultB.sideLength * sqrt(resultB.basementHeight)) / (resultB.floorHeight * resultB.floorAmount);

		if (resultB.stabilityFactor < 1)
		{
			initBuilding(resultB);
		}
		return resultB;
	}

	friend Building& operator++(Building& building)
	{
		building.floorAmount++;

		building.stabilityFactor = (float)(building.sideLength * building.sideLength * sqrt(building.basementHeight)) / (building.floorHeight * building.floorAmount);
		if (building.stabilityFactor < 1)
		{
			initBuilding(building);
		}

		return building;
	}

	friend Building operator++(Building& building, int)
	{
		Building result(building);
		building.floorAmount++;

		building.stabilityFactor = (float)(building.sideLength * building.sideLength * sqrt(building.basementHeight)) / (building.floorHeight * building.floorAmount);
		if (building.stabilityFactor < 1)
		{
			initBuilding(building);
		}

		return result;
	}
};