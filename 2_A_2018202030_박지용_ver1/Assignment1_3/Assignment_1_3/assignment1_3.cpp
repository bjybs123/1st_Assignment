#include <iostream>

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));	//generate random number

	int size, i, j, row, col;
	int** nums;

	cout << "Array Size(0<N<11) : ";
	cin >> size;								//array size 입력

	nums = new int* [size];	//size크기의 int형 배열 동적할당
	for (i = 0; i < size; ++i)
		nums[i] = new int[size];	//size크기의 int형 배열을 각 행에 동적할당.

	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			nums[i][j] = rand() % 100 + 1;		//모든 원소 1 ~ 99 랜덤초기화

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
			cout << nums[i][j] << "\t";
		cout << endl;
	}											//배열의 모든 원소 출력
	cout << endl;

	for (i = 0; i < size * size; ++i)		//Bubble sort 구현
	{
		for (j = size * size - 1; j > i; --j)
		{
			if (nums[j / size][j % size] < nums[(j - 1) / size][(j - 1) % size])	//j / size 는 행의 원소, j % size 는 열의 원소
			{
				int temp = nums[j / size][j % size];
				nums[j / size][j % size] = nums[(j - 1) / size][(j - 1) % size];
				nums[(j - 1) / size][(j - 1) % size] = temp;
			}
		}
	}


	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
			cout  << nums[i][j] << "\t";
		cout << endl;
	}											//배열의 모든 원소 출력


	for (i = 0; i < size; ++i)
		delete[] nums[i];	//각 행의 size크기의 int형 배열 할당 취소
	delete[] nums;	//size크기의 int형 배열 할당 취소
}

