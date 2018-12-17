#include <iostream>

using namespace std;

void swap(int * A, int * B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

int partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First];
	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
		{
			++Left;
		}

		while (DataSet[Right] > Pivot && Left <= Right)
		{
			--Right;
		}

		if (Left < Right)
		{
			swap(&DataSet[Left], &DataSet[Right]);
		}
		else
		{
			break;
		}
	}

	swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = partition(DataSet, Left, Right);
		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

int main()
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Leght = sizeof(DataSet) / sizeof(DataSet[0]);

	QuickSort(DataSet, 0, Leght - 1);

	for (int i = 0; i < Leght; ++i)
	{
		cout << DataSet[i] << " ";
	}

	cout << endl;
}