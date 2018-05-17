#include <iostream>

// true - wall. false - free
bool grid[40][40];
int sortInt[] = { 21 , 35 , 20 };

<<<<<<< HEAD
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
	for (int x = 0; x < 40; x++)
		for (int y = 0; y < 40; y++)
			grid[x][y] = false;

	std::cout << "OI YOU AH " << std::endl;

	return 0;
}