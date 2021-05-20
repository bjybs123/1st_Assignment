#include <iostream>

using namespace std;

void up(int** ary, int size);
void down(int** ary, int size);
void left(int** ary, int size);
void right(int** ary, int size);
void downleft(int** ary, int size);
void upright(int** ary, int size);
void print(int** ary, int size);

int main()
{
	int size, i, j, op;
	cout << "Array Size(0<N<10) : ";
	cin >> size;

	int **Matrix = new int*[size];	//�Է¹��� size������ Matrix row �����Ҵ�.
	for (i = 0; i < size; ++i)
		Matrix[i] = new int[size];	//�� row �� size��ŭ  column �����Ҵ� 


	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			Matrix[i][j] = 1;	// ��� ���Ҹ� 1�� �ʱ�ȭ

	print(Matrix, size);

	cout << "Shift All Direction : ";
	cin >> op;

	switch (op) //op������ �Է��ް� �ش� �Լ��� ȣ��.
	{
	case 0:
		up(Matrix, size);
		print(Matrix, size);
		break;
	case 1:
		down(Matrix, size);
		print(Matrix, size);
		break;
	case 2:
		right(Matrix, size);
		print(Matrix, size);
		break;
	case 3:
		left(Matrix, size);
		print(Matrix, size);
		break;
	case 4:
		downleft(Matrix, size);
		print(Matrix, size);
		break;
	case 5:
		upright(Matrix, size);
		print(Matrix, size);
		break;

	default:
		break;
	}

	

	for (j = 0; j < size; ++j)
		delete[] Matrix[j];		//�� row �� �Ҵ�� size��ŭ�� column �޸� ����
	delete[] Matrix;	//row �޸� ����


}

void up(int** ary, int size)
{
	int i, j;

	for (i = size - 1; i >= 0; --i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[j][i];	//���� ��� ������ ���� sum�� ����.
		}
		ary[0][i] = sum; //��ܿ� �ִ� ���ҵ� sum�� ������ �ʱ�ȭ.
	}

	for (i = 1; i < size; ++i)
		for (j = 0; j < size; ++j)
			ary[i][j] = 0; //������ 0���� ���ҵ��� ������ ��� ���� 0���� �ʱ�ȭ.

}


void down(int** ary, int size)
{

	int i, j;

	for (i = 0; i < size; ++i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[j][i]; // [0][0], [1][0], [2][0], [n][0] �� ���� ���� sum�� ����.
		}
		ary[size - 1][i] = sum;		//������ ���� sum���� �ʱ�ȭ
	}

	for (i = 0; i < size - 1; ++i)
		for (j = 0; j < size; ++j)
			ary[i][j] = 0;	//	������ �� �� ������ ��� ������ 0���� �ʱ�ȭ.
}

void left(int** ary, int size)
{
	int i, j;
	 
	for (i = 0; i < size; ++i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[i][j]; // �� ���� ������ ���� sum�� ����
		}
		ary[i][0] = sum; //����  0�� ���ҵ� ���� sum�� ���� ����.
	}

	for (i = 0; i < size; ++i)
		for (j = 1; j < size; ++j)
			ary[i][j] = 0;	//���� ���� ������ ��� ���� 0���� �ʱ�ȭ
}

void right(int** ary, int size)
{
	int i, j;

	for (i = 0; i < size; ++i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[i][j];	//�� ���� ��� ������ ���� sum�� ����.
		}
		ary[i][size - 1] = sum;		// ���� size - 1���� sum�� ���� ����.
	}

	for (i = 0; i < size; ++i)
		for (j = size - 2; j >= 0; --j)
			ary[i][j] = 0;		//���� ���� ������ ��� ���� 0�� �ʱ�ȭ
}

void downleft(int** ary, int size)
{
	int i, j;
	i = j = 0;
	while (i < size)
	{
		int sum = 0, x, y;
		x = i;
		y = j;  //[i][j]�� ���������� add all given direction�� ���� �� ��ġ.


		if (j == size - 1)	 //���࿡ ������ ���� �����ߴٸ� �Ʒ� ������ �̵�.
		{
			while (x < size && y >= 0)
			{
				sum += ary[x++][y--];	//�밢�� leftdown�������� �̵��ϸ鼭 ���� sum�� ����.
				if (x > size - 1 || y < 0) 
				{
					ary[--x][++y] = sum; // �迭�� ����� �ٽ� �ǵ��� �� leftdown�� ������ �ڸ��� sum�� ����.
					break;
				}
			}
			++i;	//�Ʒ� ������ �̵�.
		}
		else
		{
			while (x < size && y >= 0) // 0���� 1���� ���
			{
				sum += ary[x++][y--];			//�밢�� left�������� �̵��ϸ鼭 ���� sum�� ����.
				if (x > size - 1 || y < 0)
				{
					ary[--x][++y] = sum;	// �迭�� ����� �ٽ� �ǵ��� leftdown�� ������ �ڸ��� sum�� ����
					break;
				}
			}
			++j;	//���� �� �̵�
		}

	}
	for (i = 0; i < size - 1; ++i)
		for (j = 1; j < size; ++j)
			ary[i][j] = 0;				//leftdown 0���� ������ ���� ���ҵ��� ������ ��� ���� 0���� �ʱ�ȭ.

}

void upright(int** ary, int size)
{
	int i, j;
	i = j = 0;
	while (j < size)
	{
		int sum = 0, x, y;
		x = i;
		y = j; //[i][j]�� ���������� upright�� ���ҷ� sum�� ������ ��ġ

		if (i == size - 1)	//������ ������ ���� �������� �� 
		{
			while (y < size && x >= 0)
			{
				sum += ary[x--][y++];	//�밢�� �������� upright�������� ���ҵ��� ���� sum�� ����
				if (y > size - 1 || x < 0)	
				{
					ary[++x][--y] = sum;	//���� �迭�� �ۿ� �����ϸ� �ǵ��� upright������ ���ҿ� sum�� ����
					break;
				}
			}
			++j;	// ���� �� �̵�.
		}
		else
		{
			while (y < size && x >= 0)	//0��� 1���� ���
			{

				sum += ary[x--][y++];	//�밢�� ���� upright�������� ���ҵ��� ���� sum�� ����
				if (y > size - 1 || x < 0)
				{
					ary[++x][--y] = sum;	//���� �迭�� �ۿ� �����ϸ� �ǵ��� upright������ ���ҿ� sum�� ����
					break;
				}
			}
			++i;	//���� �� �̵�
		}
	}

	for (i = 1; i < size; ++i)
		for (j = 0; j < size - 1; ++j)
			ary[i][j] = 0;			//upright�� ���ҵ��� ������ ��� ���ҵ� 0���� �ʱ�ȭ
}

void print(int** ary, int size)
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
			cout << ary[i][j] << " ";
		cout << endl;
	}

	cout << endl;
}