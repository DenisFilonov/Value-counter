#include "Counter.h"

Counter::Counter()
{
	startValue = 0;
	endValue = 0;
	step = 0;
	currentValue = 0;
	cycle = 0;
	cout << "\n������� � �������� ����������� ������� �����������!\n\n";
}

Counter::Counter(int start, int end, int eps)
{
	startValue = start;
	endValue = end;
	step = eps;
	cout << "\n������� � ��������� ����������� ������� �����������!\n\n";
}

Counter::~Counter()
{
	cout << "������� ������!\n";
}

void Counter::setStartValue(int value)
{
	if (value < endValue || endValue == 0)
	{
		startValue = value;
		cout << "\n��������� �������� �����������!\n\n";

	}
	else cout << "\n������ ������������ �������� ���������!\n\n";
}

int Counter::getStartValue()
{
	return startValue;
}

void Counter::setEndValue(int value)
{
	if (value > startValue || startValue == 0)
	{
		endValue = value;
		cout << "\n�������� �������� �����������!\n\n";
	}
	else cout << "\n������ ������������ �������� ���������!\n\n";
}

int Counter::getEndValue()
{
	return endValue;
}

void Counter::setStep(int step)
{		
	//1) limit = _limit;
	//2) void Counter::setStep(int):step(_step)
	if (step >= startValue && step <= endValue)
	{
		this->step = step;
		cout << "\n��� ����������!\n\n";
	}
	else cout << "\n������ ������������ �������� ���������!\n\n";
}

int Counter::getStep()
{
	return step;
}

void Counter::setCurrentValue(int value)
{
	if (value > startValue && value < endValue)
	{
		currentValue = value;
		cout << "\n������� �������� �����������!\n\n";
	}
	else cout << "\n������ ������������ �������� ���������!\n\n";
}

int Counter::getCurrentValue()
{
	return currentValue;
}

void Counter::setCurrentCycle(int value)
{
	if (value > 0)
	{
		cycle = value;
		cout << "\n�������� ����� �����������!\n\n";
	}
	else cout << "\n������ ������������ �������� ���������!\n\n";
}

int Counter::getCurrentCycle()
{
	return cycle;
}

void Counter::showInfo()
{
	cout << "\n================================================";
	cout << "\n\t���������� � ��������� ��������:";
	cout << "\n��������� ��������: " << startValue;
	cout << "\n�������� ��������: " << endValue;
	cout << "\n���: " << step;
	cout << "\n������� ��������: " << currentValue;
	cout << "\n���� ����������: " << cycle;
	cout << "\n================================================\n\n";
}

void Counter::nextValue()
{
	/*if (startValue == endValue)
	{
		currentValue++;
		startValue = 0;
	}
	else
	{
		currentValue += step;
	}*/
	currentValue += step;
	if (currentValue > endValue)
	{
		currentValue = startValue + (currentValue - endValue);
		cycle++;
	}
}

void Counter::prevValue()
{
	/*if (endValue == startValue)
	{
		currentValue--;
		endValue = 0;
	}
	else
	{
		currentValue -= step;
	}*/
	currentValue -= step;
	if (currentValue < startValue)
	{
		currentValue = endValue - (startValue - currentValue);
		cycle--;
		if (cycle < 0)
		{
			cycle = 0;
			cout << "\n������! �������� ����� �� ����� ���� �������������!";
			cout << "\n����: " << cycle << endl << endl;
		}
	}
}

void Counter::runCounter(int n)
{
	for (int i = 0; i < n; i++)
	{
		nextValue();
	}
}

void Counter::backCounter(int n)
{
	for (int i = 0; i < n; i++)
	{
		prevValue();
	}
}

void Counter::toTextFile(FILE* fp)
{
	fopen_s(&fp, "Counter_txt.txt", "w");

	if (fp == NULL)
	{
		cout << "\n������ �������� �����!\n\n";
	}
	else
	{
		fprintf(fp, "%d ", startValue);
		fprintf(fp, "%d ", endValue);
		fprintf(fp, "%d ", step);
		fprintf(fp, "%d ", currentValue);
		fprintf(fp, "%d ", cycle);
		fclose(fp);
		cout << "\n��������� ������� ��������� � ���� ���������� ����!\n\n";
	}
}

void Counter::fromTextFile(FILE* fp)
{
	fopen_s(&fp, "Counter_txt.txt", "r");

	if (fp == NULL)
	{
		cout << "\n������ �������� �����!\n\n";
	}
	else
	{
		fscanf_s(fp, "%d ", &startValue);
		fscanf_s(fp, "%d ", &endValue);
		fscanf_s(fp, "%d ", &step);
		fscanf_s(fp, "%d ", &currentValue);
		fscanf_s(fp, "%d ", &cycle);
		fclose(fp);
		cout << "\n��������� ������� ��������� �� ����� ���������� ����!\n\n";
	}
}

void Counter::toBinFile(FILE* fp)
{
	fopen_s(&fp, "Counter_bin.dat", "wb");

	if (fp == NULL)
	{
		cout << "\n������ �������� �����!\n\n";
	}
	else
	{
		fwrite(&startValue, sizeof(int), 1, fp);
		fwrite(&endValue, sizeof(int), 1, fp);
		fwrite(&step, sizeof(int), 1, fp);
		fwrite(&currentValue, sizeof(int), 1, fp);
		fwrite(&cycle, sizeof(int), 1, fp);
		fclose(fp);
		cout << "\n��������� ������� ��������� � ���� ��������� ����!\n\n";
	}
}

void Counter::fromBinFile(FILE* fp)
{
	fopen_s(&fp, "Counter_bin.dat", "rb");

	if (fp == NULL)
	{
		cout << "\n������ �������� �����!\n\n";
	}
	else
	{
		fread(&startValue, sizeof(int), 1, fp);
		fread(&endValue, sizeof(int), 1, fp);
		fread(&step, sizeof(int), 1, fp);
		fread(&currentValue, sizeof(int), 1, fp);
		fread(&cycle, sizeof(int), 1, fp);
		fclose(fp);
		cout << "\n��������� ������� ��������� �� ����� ��������� ����!\n\n";
	}
}
