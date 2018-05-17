#include <iostream>

// true - wall. false - free
bool grid[40][40];
int sortInt[] = { 21 , 35 , 20 };

void Sort(int arrayToSort[])
{
	for (int i = 0; i < sizeof(arrayToSort) / sizeof(int); i++)
	{
		int key = arrayToSort[i];
		int j = i - 1;
		while (j >= 0 && key < arrayToSort[j])
		{
			arrayToSort[j + 1] = arrayToSort[j];
			j--;
		}

		arrayToSort[j + 1] = key;
	}
}

int main() {
	Sort(sortInt);
	return 0;
}