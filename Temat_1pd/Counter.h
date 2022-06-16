#pragma once
#include<iostream>
#include<cstdio>
using namespace std;

class Counter
{
	int startValue;
	int endValue;
	int step;
	int currentValue;
	int cycle; // ����� �� ���� � ��, ������� �� ���� ���������� ��������, ��� �������
	// ��. ��� ���� � 	void nextValue(); void prevValue();


public:
	Counter();
	Counter(int start, int end, int eps);
	~Counter();

	void setStartValue(int value);
	int getStartValue();

	void setEndValue(int value);
	int getEndValue();

	void setStep(int step);
	int getStep();

	void setCurrentValue(int value);
	int getCurrentValue();

	void setCurrentCycle(int value);
	int getCurrentCycle();

	void showInfo();
	void nextValue();
	void prevValue();
	void runCounter(int n);
	void backCounter(int n);	//��� � ������� �� ����, �� ���� � ��


	void toTextFile(FILE* fp);
	void fromTextFile(FILE* fp);
	void toBinFile(FILE* fp);
	void fromBinFile(FILE* fp);
};

