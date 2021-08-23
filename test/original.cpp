#include <bits/stdc++.h>
using namespace std;

int Partition(int* arr, int front, int end, int& tmp_switching, double& switching, int& tmp_comparisons, double& comparisons)
{
	int pivot = arr[end];
	int i = front - 1;
	for (int j = front; j < end; j++)
	{
		comparisons++;
		tmp_comparisons++;
		if (arr[j] < pivot)
		{
			i++;
			switching++;
			tmp_switching++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[end]);
	return i;
}

void QuickSort(int* arr, int front, int end, double& switching, int& tmp_switching, double& comparisons, int& tmp_comparisons, int& worst_comparisons, int& worst_switching)
{
	if (front < end)
	{
		int pivot = Partition(arr, front, end, tmp_switching, switching, tmp_comparisons, comparisons);
		QuickSort(arr, front, pivot - 1, switching, tmp_switching, comparisons, tmp_comparisons, worst_comparisons, worst_switching);             //排序pivot之前的陣列
		QuickSort(arr, pivot + 1, end, switching, tmp_switching, comparisons, tmp_comparisons, worst_comparisons, worst_switching);               //排序pivot之後的陣列
	}
	if (tmp_comparisons > worst_comparisons)
		worst_comparisons = tmp_comparisons;
	if (tmp_switching > worst_switching)
		worst_switching = tmp_switching;
}

void Shuffle(int* arr, size_t n)
{
	srand(time(NULL));
	if (n > 1)
	{
		size_t i;
		for (i = 0; i < n; i++) {
			size_t j = rand() / (RAND_MAX / (n));
			swap(arr[i], arr[j]);
		}
	}
}

int x = 10000;
int arr[10000];

int main()
{
	double start, end, total = 0;
	start = clock();

	int times = 10;
	double comparisons = 0, switching = 0;
	int worst_comparisons = 0, worst_switching = 0;
	unsigned __int64 tmp = 0;
	for (int i = x - 2; i >= 0; i -= 2)
	{
		tmp += i;
	}
	cout << "乂 快速排序法 乂" << endl << endl;
	cout << "理論最大交換次數為: " << tmp << " 次" << endl;
	cout << "理論最大比較次數為: " << x * (x - 1) / 2 << " 次" << endl << endl;
	cout << "時間複雜度: O(n*log n)" << endl << endl;

	for (int i = 0; i < x; i++)
		arr[i] = i + 1;

	for (int k = 0; k < times; k++)
	{
		Shuffle(arr, x);

		start = clock();
		int tmp_switching = 0, tmp_comparisons = 0;

		QuickSort(arr, 0, x - 1, switching, tmp_switching, comparisons, tmp_comparisons, worst_comparisons, worst_switching);
		end = clock();
		total += end - start;
	}

	cout << "平均交換了 " << switching / times << " 次" << endl;
	cout << "平均比較了 " << comparisons / times << " 次" << endl << endl;
	cout << "最多交換了 " << worst_switching << " 次" << endl;
	cout << "最多比較了 " << worst_comparisons << " 次" << endl << endl;

	cout << "排序執行時間: " << total << " 毫秒" << endl;

	return 0;
}