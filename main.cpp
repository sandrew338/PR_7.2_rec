// Lab_7_2_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 0
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void ChangeMaxElemEveryPairRowWithMinElemOddRow(int**& a, const int k, const int n, int i);
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int SearchMax(int* a, const int n, int index_min, int j);
int SearchMin(int* a, const int n, int index_min, int j);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n, k;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High, 0, 0);

	if (k == 1)
		cout << "There won't pair and odd rows.Try again" << endl;
	Print(a, k, n, 0, 0);
	cout << "After modification: " << endl;
	ChangeMaxElemEveryPairRowWithMinElemOddRow(a, k, n, 1);
	Print(a, k, n, 0, 0);

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
	{
		Create(a, rowCount, colCount, Low, High, i, j + 1);

	}
	else
		if (i < rowCount - 1)
		{
			Create(a, rowCount, colCount, Low, High, i + 1, 0);

		}
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
int SearchMin(int* a, const int n, int index_min, int j)
{
	if (j < n)
	{
		if (a[index_min] > a[j])
		{
			index_min = j;
		}
		SearchMin(a, n, index_min, j + 1);
	}
	else
	{
		return index_min;
	}
}
int SearchMax(int* a, const int n, int index_max, int j)
{
	if (j < n)
	{
		if (a[index_max] < a[j])
		{
			index_max = j;
		}
		SearchMax(a, n, index_max, j + 1);
	}
	else
	{
		return index_max;
	}
}
void ChangeMaxElemEveryPairRowWithMinElemOddRow(int**& a, const int k, const int n, int i)
{
	if(i < k)
	{
		int index_min = SearchMin(a[i - 1], n, 0, 0);
		int index_max = SearchMax(a[i], n, 0, 0);
		int temp = a[i - 1][index_min];
		a[i - 1][index_min] = a[i][index_max];
		a[i][index_max] = temp;
		ChangeMaxElemEveryPairRowWithMinElemOddRow(a, k, n, i + 2);
	}
}
