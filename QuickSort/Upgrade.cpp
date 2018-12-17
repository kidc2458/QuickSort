#include <iostream>

using namespace std;

//int partition(int DataSet[], int Left, int Right)
//{
//	int First = Left;
//	int Pivot = DataSet[First];
//	++Left;
//
//	while (Left <= Right)
//	{
//		while (DataSet[Left] <= Pivot && Left < Right)
//		{
//			++Left;
//		}
//
//		while (DataSet[Right] > Pivot && Left <= Right)
//		{
//			--Right;
//		}
//
//		if (Left < Right)
//		{
//			int temp = DataSet[Left];
//			DataSet[Left] = DataSet[Right];
//			DataSet[Right] = temp;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//
//	
//		int temp = DataSet[First];	//pivot
//		DataSet[First] = DataSet[Right];	//==Data[Left]
//		DataSet[Right] = temp;
//	
//	return Right;
//}
//
//void QuickSort(int DataSet[], int Left, int Right)
//{
//	if (Left < Right)
//	{
//		int Index = partition(DataSet, Left, Right);
//		QuickSort(DataSet, Left, Index - 1);
//		QuickSort(DataSet, Index + 1, Right);
//	}
//}

void QuickSort(int DataSet[], int Start, int End)
{
	if (Start < End)
	{
		int Pivot = Start;
		int Left = Start + 1;
		int Right = End;

		while (Left <= Right)
		{
			while (DataSet[Left] < DataSet[Pivot] && Left < Right)
			{
				++Left;
			}

			while (DataSet[Right] > DataSet[Pivot] && Left <= Right)
			{
				--Right;
			}

			if (Left < Right)
			{
				int temp = DataSet[Right];
				DataSet[Right] = DataSet[Left];
				DataSet[Left] = temp;
			}
			else
				break;	//그냥 명시적?

		}

		int temp = DataSet[Right];
		DataSet[Right] = DataSet[Pivot];
		DataSet[Pivot] = temp;

		QuickSort(DataSet, Start, Right - 1);
		QuickSort(DataSet, Right + 1, End);
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