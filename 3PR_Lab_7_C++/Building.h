#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Facade.h"

using namespace std;

class Building
{
private:
	// Длина стороны основания.
	float sideLength;
	// Высота фундамента.
	float basementHeight;
	// Высота этажа.
	float floorHeight;
	// Количество этажей.
	int floorAmount;
	// Объект класса фасада здания, содержащий информацию об окнах здания.
	Facade facade;
	// Коэффициент устойчивости.
	float stabilityFactor;
	/* Функция по установке переданных значений в свойства экземпляра класса Building. */
	void setBuiling(float b_sideLength, float b_basementHeight, float b_floorHeight, unsigned b_floorAmount, float b_stabilityFactor)
	{
		sideLength = b_sideLength;
		basementHeight = b_basementHeight;
		floorHeight = b_floorHeight;
		floorAmount = b_floorAmount;
		stabilityFactor = b_stabilityFactor;
	}
public:
	/* Функция по выводу свойств экземпляра класса Building. */
	void getBuilding()
	{
		cout << "Свойства данного здания:" << endl;
		cout << "Длина стороны основания: " << sideLength << endl;
		cout << "Высота фундамента: " << basementHeight << endl;
		cout << "Высота этажа: " << floorHeight << endl;
		cout << "Количество этажей: " << floorAmount << endl;
		facade.getFacade();
		cout << "Коэффициент устойчивости: " << stabilityFactor << endl << endl;
	}
	/* Функция по заданию свойств по умолчанию экземпляра класса Building. */
	void initBuilding()
	{
		setBuiling(1.0, 1.0, 1.0, 1, 1.0);
		facade.setFacade(0, 0);
	}
	/* Функция по вводу с клавиатуры свойств для экземпляра класса Building */
	void inputBuilding()
	{
		// Защиты от дурака для ввода всех необходимых данных.
		cout << "Введите длину стороны вашего здания: ";
		while (!(cin >> sideLength) || cin.get() != '\n' || sideLength <= 0)
		{
			cout << "Неверный ввод длины стороны - она должна быть положительным числом. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "Введите высоту фундамента вашего здания: ";
		while (!(cin >> basementHeight) || cin.get() != '\n' || basementHeight <= 0)
		{
			cout << "Неверный ввод высоты фундамента - она должна быть положительным числом. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "Введите высоту одного этажа вашего здания: ";
		while (!(cin >> floorHeight) || cin.get() != '\n' || floorHeight <= 0)
		{
			cout << "Неверный ввод высоты этажа - она должна быть положительным числом. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}

		cout << "Введите количество этажей вашего здания: ";
		while (!(cin >> floorAmount) || cin.get() != '\n' || floorAmount <= 0)
		{
			cout << "Неверный ввод количества - оно должно быть положительным целым числом. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}
		facade.inputFacade();
		// Расчет коэффицента устойчивости.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		// Если коэффициент устойчивости меньше 1 - здание упадет; необхлдим повторный ввод характеристик
		if (stabilityFactor < 1.0)
		{
			cout << "Коэффициент стабильности вашего здания k = " << stabilityFactor << " меньше единицы. Оно может рухнуть с минуты на минуту. Хотите ли перестроить его?" << endl;
			cout << "Если НЕТ - нажмите Esc, если ДА - любую другую кнопку." << endl << endl;
			if (_getch() != 27)
			{
				inputBuilding();
			}
			else
			{
				cout << "Здание не смогло устоять и рухнуло!" << endl << endl << endl;
				initBuilding();
			}
		}
		else
		{
			cout << "Отлично! Здание получилось устойчивым с коэффициентом устойчивости k = " << stabilityFactor << "." << endl << endl << endl;
		}
	}
	/* Функция по сложению двух экземпляров класса Building, где build - экземпляр, который будет прибавляться. */
	void addToBuilding(Building build)
	{
		cout << "Совмещаем два здания... Их свойства такие:" << endl;
		cout << "Длины сторон оснований: " << sideLength << " и " << build.sideLength << endl <<
			"Высоты фундаментов: " << basementHeight << " и " << build.basementHeight << endl << "Высоты этажей: " << floorHeight << " и " << build.floorHeight << endl <<
			"Количества этажей: " << floorAmount << " и " << build.floorAmount << endl << "Коэффициенты устойчивости: " << stabilityFactor << " и " << build.stabilityFactor << endl <<
			"Общие количества окон: " << facade.getWindowsAmount() << " и " << build.facade.getWindowsAmount() << endl <<
			"Количества открытых окон: " << facade.getOpenedWindowsAmount() << " и " << build.facade.getOpenedWindowsAmount() << endl << endl;

		if (sideLength < build.sideLength)
			sideLength = build.sideLength;

		if (basementHeight < build.basementHeight)
			basementHeight = build.basementHeight;

		if (floorHeight < build.floorHeight)
			floorHeight = build.floorHeight;

		floorAmount = floorAmount + build.floorAmount;

		facade.addToFacade(build.facade);
		// Расчет нового коэффициента устойчивости и проверка его корректности.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1)
		{
			cout << "К сожалению, после совмещения двух зданий новое здание сразу же развалилось, так как его коэффициент устойчивости k = " << stabilityFactor << " меньше нуля." << endl << endl;
			initBuilding();
		}
		else
		{
			cout << "Отлично! Новое здание устояло. Его свойства такие:" << endl << endl;
			getBuilding();
		}
	}
	/* Функция по добавлению floorsToAdd этажей экземпляру класса Building. */
	void addFloors()
	{
		unsigned floorsToAdd;
		// Защита от дурака для ввода floorsToAdd.
		cout << "Введите количество этажей для добавления к вашему зданию: ";
		while (!(cin >> floorsToAdd) || cin.get() != '\n' || floorsToAdd < 0)
		{
			cout << "Неверный ввод количества - оно должно быть неотрицательным целым числом. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}

		floorAmount = floorAmount + floorsToAdd;
		// Расчет нового коэффициента устойчивости и проверка его корректности.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1.0)
		{
			cout << "Коэффициент стабильности вашего здания k = " << stabilityFactor <<
				" стал меньше единицы.\nОно может рухнуть с минуты на минуту. Попробуйте изменить количество этажей к добавлению (например, на 0)" << endl << endl;
			floorAmount = floorAmount - floorsToAdd;
			addFloors();
		}
		else
		{
			cout << "Отлично! Здание получилось устойчивым с коэффициентом устойчивости k = " << stabilityFactor << endl << endl;
			// Отображение информации о здании.
			getBuilding();
		}
	}

	/* Функция по удалению floorsToRemove этажей у экземпляра класса Building. */
	void removeFloors()
	{
		int floorsToRemove;
		// Защита от дурака для ввода floorsToRemove.
		cout << "Введите количество этажей для удаления с вашего здания: ";
		while (!(cin >> floorsToRemove) || cin.get() != '\n' || floorsToRemove < 0 || floorsToRemove >= floorAmount)
		{
			cout << "Неверный ввод количества - оно должно быть неотрицательным целым числом и меньшим общего числа этажей. Попробуйте еще раз: ";
			cin.clear();
			rewind(stdin);
		}
		// Расчет нового коэффициента устойчивости.
		floorAmount = floorAmount - floorsToRemove;
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		cout << "Этажи успешно удалены!" << endl;
		// Отображение информации о здании.
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

};