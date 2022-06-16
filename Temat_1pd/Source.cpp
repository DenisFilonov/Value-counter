#include"Counter.h"

int main()
{
	setlocale(NULL, "");
	srand(time(NULL));
	
	FILE* fp = nullptr;
	Counter* C = nullptr;
	int menu1, menu2;
	int a, b, c;

	do
	{
		cout << "\n1. Операции загрузки и выгрузки информации.";
		cout << "\n2. Показать значения счётчика.";
		cout << "\n3. Создать пустой счётчик.";
		cout << "\n4. Создать счётчик с определёнными параметрами.";
		cout << "\n5. Настройки параметров.";
		cout << "\n6. Просмотр параметров.";
		cout << "\n7. Меню запуска работы счётчика.";
		cout << "\n0. Завершить работу с приложением.\nВыбор: ";
		cin >> menu1;
		switch (menu1)
		{
		case 1:
			cout << "\n1. Загрузить параметры с текстового типа файла.";
			cout << "\n2. Сохранить параметры в текстовый типа файл.";
			cout << "\n3. Загрузить параметры с бинарного типа файла.";
			cout << "\n4. Сохранить параметры в бинарного типа файл.";
			cout << "\n0. Вернуться назад.\nВыбор: ";
			cin >> menu2;

			switch (menu2)
			{
			case 1: 
				cout << "\n\tВнимание! Вся несохранённая информация может быть утеряна! ";
				system("pause");
				cout << "\nПродолжить ? \n1) Да\n2) Нет\n";
				cin >> a;
				if (a == 1)
				{
					if (C != NULL) delete C;
					C = new Counter();

					C->fromTextFile(fp);
				}
				else break;

				break;

			case 2: 
				C->toTextFile(fp);
				break;

			case 3: 
				cout << "\n\tВнимание! Вся несохранённая информация может быть утеряна! ";
				system("pause");
				cout << "\nПродолжить ? \n1) Да\n2) Нет\n";
				cin >> a;
				if (a == 1)
				{
					if (C != NULL) delete C;
					C = new Counter();

					C->fromBinFile(fp);
				}
				else break;
				break;

			case 4: 
				C->toBinFile(fp);
				break;

			default: if (menu2 > 4 && menu2 != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
			}
			
			break;

		case 2: 
			C->showInfo();
			break;

		case 3:
			if (C != NULL) delete C;

			C = new Counter();
			break;

		case 4: 
			if (C != NULL) delete C;

			cout << "\nНеобходимые параметры значений:\n1) Начальное 2) Конечное 3) Шаг\nВвод: ";
			cin >> a >> b >> c;
			C = new Counter(a, b, c);
			break;

		case 5: 
			do
			{
				cout << "\n1. Установить начальное значение.";
				cout << "\n2. Установить конечное значение.";
				cout << "\n3. Установить шаг.";
				cout << "\n4. Установить текущее значение.";
				cout << "\n5. Установить цикл повторений.";
				cout << "\n0. Вернуться назад.\nВыбор: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\nЗначение: ";
					cin >> a;
					C->setStartValue(a);
					break;

				case 2:
					cout << "\nЗначение: ";
					cin >> a;
					C->setEndValue(a);
					break;

				case 3:
					cout << "\nЧисло: ";
					cin >> a;
					C->setStep(a);
					break;

				case 4:
					cout << "\nЗначение: ";
					cin >> a;
					C->setCurrentValue(a);
					break;

				case 5:
					cout << "\nЗначение: ";
					cin >> a;
					C->setCurrentCycle(a);
					break;

				default: if (menu2 > 5 && menu2 != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
				}
			} while (menu2 != 0);
			break;

		case 6: 
			do
			{
				cout << "\n1. Просмотреть начальное значение.";
				cout << "\n2. Просмотреть конечное значение.";
				cout << "\n3. Просмотреть шаг.";
				cout << "\n4. Просмотреть текущее значение.";
				cout << "\n5. Просмотреть цикл повторений.";
				cout << "\n0. Вернуться назад.\nВыбор: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\nЗначение: " << C->getStartValue() << endl << endl;
					break;

				case 2:
					cout << "\nЗначение: " << C->getEndValue() << endl << endl;
					break;

				case 3:
					cout << "\nЧисло: " << C->getStep() << endl << endl;
					break;

				case 4:
					cout << "\nЗначение: " << C->getCurrentValue() << endl << endl;
					break;

				case 5:
					cout << "\nЗначение: " << C->getCurrentCycle() << endl << endl;
					break;

				default: if (menu2 > 5 && menu2 != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
				}
			} while (menu2 != 0);

			break;

		case 7:
			do
			{
				cout << "\n1. Добавить значение.";
				cout << "\n2. Удалить значение.";
				cout << "\n3. Запустить работу счётчика вперёд.";
				cout << "\n4. Запустить работу счётчика назад.";
				cout << "\n5. Показать значения счётчика.";
				cout << "\n0. Вернуться назад.\nВыбор: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					C->nextValue();
					cout << "\nЗначение добавлено!\n\n";
					C->showInfo();
					break;

				case 2:
					C->prevValue();
					cout << "\nЗначение удалено!\n\n";
					C->showInfo();
					break;

				case 3:
					cout << "\nКоличество раз: ";
					cin >> a;
					C->runCounter(a);
					cout << "\nЗначения добавлены!\n\n";
					C->showInfo();
					break;

				case 4:
					cout << "\nКоличество раз: ";
					cin >> a;
					C->backCounter(a);
					cout << "\nЗначения удалены!\n\n";
					C->showInfo();
					break;

				case 5:
					C->showInfo();
					break;

				default: if (menu2 > 5 && menu2 != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
				}
			} while (menu2 != 0);

			break;

		default: if (menu1 > 7 && menu1 != 0) cout << "\nНеверно выбран пункт меню.\n\n";	break;
		}
	} while (menu1 != 0);


	if (C != NULL) delete C;
	return 0;
}