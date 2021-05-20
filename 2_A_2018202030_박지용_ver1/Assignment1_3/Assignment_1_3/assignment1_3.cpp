#include <iostream>

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));	//generate random number

	int size, i, j, row, col;
	int** nums;

	cout << "Array Size(0<N<11) : ";
	cin >> size;								//array size �Է�

	nums = new int* [size];	//sizeũ���� int�� �迭 �����Ҵ�
	for (i = 0; i < size; ++i)
		nums[i] = new int[size];	//sizeũ���� int�� �迭�� �� �࿡ �����Ҵ�.

	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			nums[i][j] = rand() % 100 + 1;		//��� ���� 1 ~ 99 �����ʱ�ȭ

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
			cout << nums[i][j] << "\t";
		cout << endl;
	}											//�迭�� ��� ���� ���
	cout << endl;

	for (i = 0; i < size * size; ++i)		//Bubble sort ����
	{
		for (j = size * size - 1; j > i; --j)
		{
			if (nums[j / size][j % size] < nums[(j - 1) / size][(j - 1) % size])	//j / size �� ���� ����, j % size �� ���� ����
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
	}											//�迭�� ��� ���� ���


	for (i = 0; i < size; ++i)
		delete[] nums[i];	//�� ���� sizeũ���� int�� �迭 �Ҵ� ���
	delete[] nums;	//sizeũ���� int�� �迭 �Ҵ� ���
}

