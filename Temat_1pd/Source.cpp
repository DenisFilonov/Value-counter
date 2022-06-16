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
		cout << "\n1. �������� �������� � �������� ����������.";
		cout << "\n2. �������� �������� ��������.";
		cout << "\n3. ������� ������ �������.";
		cout << "\n4. ������� ������� � ������������ �����������.";
		cout << "\n5. ��������� ����������.";
		cout << "\n6. �������� ����������.";
		cout << "\n7. ���� ������� ������ ��������.";
		cout << "\n0. ��������� ������ � �����������.\n�����: ";
		cin >> menu1;
		switch (menu1)
		{
		case 1:
			cout << "\n1. ��������� ��������� � ���������� ���� �����.";
			cout << "\n2. ��������� ��������� � ��������� ���� ����.";
			cout << "\n3. ��������� ��������� � ��������� ���� �����.";
			cout << "\n4. ��������� ��������� � ��������� ���� ����.";
			cout << "\n0. ��������� �����.\n�����: ";
			cin >> menu2;

			switch (menu2)
			{
			case 1: 
				cout << "\n\t��������! ��� ������������ ���������� ����� ���� �������! ";
				system("pause");
				cout << "\n���������� ? \n1) ��\n2) ���\n";
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
				cout << "\n\t��������! ��� ������������ ���������� ����� ���� �������! ";
				system("pause");
				cout << "\n���������� ? \n1) ��\n2) ���\n";
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

			default: if (menu2 > 4 && menu2 != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
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

			cout << "\n����������� ��������� ��������:\n1) ��������� 2) �������� 3) ���\n����: ";
			cin >> a >> b >> c;
			C = new Counter(a, b, c);
			break;

		case 5: 
			do
			{
				cout << "\n1. ���������� ��������� ��������.";
				cout << "\n2. ���������� �������� ��������.";
				cout << "\n3. ���������� ���.";
				cout << "\n4. ���������� ������� ��������.";
				cout << "\n5. ���������� ���� ����������.";
				cout << "\n0. ��������� �����.\n�����: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\n��������: ";
					cin >> a;
					C->setStartValue(a);
					break;

				case 2:
					cout << "\n��������: ";
					cin >> a;
					C->setEndValue(a);
					break;

				case 3:
					cout << "\n�����: ";
					cin >> a;
					C->setStep(a);
					break;

				case 4:
					cout << "\n��������: ";
					cin >> a;
					C->setCurrentValue(a);
					break;

				case 5:
					cout << "\n��������: ";
					cin >> a;
					C->setCurrentCycle(a);
					break;

				default: if (menu2 > 5 && menu2 != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
				}
			} while (menu2 != 0);
			break;

		case 6: 
			do
			{
				cout << "\n1. ����������� ��������� ��������.";
				cout << "\n2. ����������� �������� ��������.";
				cout << "\n3. ����������� ���.";
				cout << "\n4. ����������� ������� ��������.";
				cout << "\n5. ����������� ���� ����������.";
				cout << "\n0. ��������� �����.\n�����: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\n��������: " << C->getStartValue() << endl << endl;
					break;

				case 2:
					cout << "\n��������: " << C->getEndValue() << endl << endl;
					break;

				case 3:
					cout << "\n�����: " << C->getStep() << endl << endl;
					break;

				case 4:
					cout << "\n��������: " << C->getCurrentValue() << endl << endl;
					break;

				case 5:
					cout << "\n��������: " << C->getCurrentCycle() << endl << endl;
					break;

				default: if (menu2 > 5 && menu2 != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
				}
			} while (menu2 != 0);

			break;

		case 7:
			do
			{
				cout << "\n1. �������� ��������.";
				cout << "\n2. ������� ��������.";
				cout << "\n3. ��������� ������ �������� �����.";
				cout << "\n4. ��������� ������ �������� �����.";
				cout << "\n5. �������� �������� ��������.";
				cout << "\n0. ��������� �����.\n�����: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					C->nextValue();
					cout << "\n�������� ���������!\n\n";
					C->showInfo();
					break;

				case 2:
					C->prevValue();
					cout << "\n�������� �������!\n\n";
					C->showInfo();
					break;

				case 3:
					cout << "\n���������� ���: ";
					cin >> a;
					C->runCounter(a);
					cout << "\n�������� ���������!\n\n";
					C->showInfo();
					break;

				case 4:
					cout << "\n���������� ���: ";
					cin >> a;
					C->backCounter(a);
					cout << "\n�������� �������!\n\n";
					C->showInfo();
					break;

				case 5:
					C->showInfo();
					break;

				default: if (menu2 > 5 && menu2 != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
				}
			} while (menu2 != 0);

			break;

		default: if (menu1 > 7 && menu1 != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
		}
	} while (menu1 != 0);


	if (C != NULL) delete C;
	return 0;
}