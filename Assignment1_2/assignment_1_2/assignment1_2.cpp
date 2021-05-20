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

	int **Matrix = new int*[size];	//입력받은 size변수로 Matrix row 동적할당.
	for (i = 0; i < size; ++i)
		Matrix[i] = new int[size];	//각 row 를 size만큼  column 동적할당 


	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			Matrix[i][j] = 1;	// 모든 원소를 1로 초기화

	print(Matrix, size);

	cout << "Shift All Direction : ";
	cin >> op;

	switch (op) //op변수를 입려받고 해당 함수를 호출.
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
		delete[] Matrix[j];		//매 row 의 할당된 size만큼의 column 메모리 헤제
	delete[] Matrix;	//row 메모리 헤제


}

void up(int** ary, int size)
{
	int i, j;

	for (i = size - 1; i >= 0; --i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[j][i];	//행의 모든 원소의 합을 sum에 저장.
		}
		ary[0][i] = sum; //상단에 있는 원소들 sum의 값으로 초기화.
	}

	for (i = 1; i < size; ++i)
		for (j = 0; j < size; ++j)
			ary[i][j] = 0; //좌측의 0열의 원소들을 제외한 모든 워소 0으로 초기화.

}


void down(int** ary, int size)
{

	int i, j;

	for (i = 0; i < size; ++i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[j][i]; // [0][0], [1][0], [2][0], [n][0] 한 열의 합을 sum에 저장.
		}
		ary[size - 1][i] = sum;		//마지막 행을 sum으로 초기화
	}

	for (i = 0; i < size - 1; ++i)
		for (j = 0; j < size; ++j)
			ary[i][j] = 0;	//	마지막 행 을 제외한 모든 원소을 0으로 초기화.
}

void left(int** ary, int size)
{
	int i, j;
	 
	for (i = 0; i < size; ++i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[i][j]; // 각 행의 원소의 합을 sum에 저장
		}
		ary[i][0] = sum; //좌측  0열 원소들 에게 sum의 값을 저장.
	}

	for (i = 0; i < size; ++i)
		for (j = 1; j < size; ++j)
			ary[i][j] = 0;	//좌측 열을 제외한 모든 원소 0으로 초기화
}

void right(int** ary, int size)
{
	int i, j;

	for (i = 0; i < size; ++i)
	{
		int sum = 0;
		for (j = 0; j < size; ++j)
		{
			sum += ary[i][j];	//각 행의 모든 원소의 합을 sum에 저장.
		}
		ary[i][size - 1] = sum;		// 좌측 size - 1열에 sum의 값을 저장.
	}

	for (i = 0; i < size; ++i)
		for (j = size - 2; j >= 0; --j)
			ary[i][j] = 0;		//우측 열을 제외한 모든 원소 0을 초기화
}

void downleft(int** ary, int size)
{
	int i, j;
	i = j = 0;
	while (i < size)
	{
		int sum = 0, x, y;
		x = i;
		y = j;  //[i][j]는 최종적으로 add all given direction을 저장 할 위치.


		if (j == size - 1)	 //만약에 마지막 열에 도착했다면 아래 열으로 이동.
		{
			while (x < size && y >= 0)
			{
				sum += ary[x++][y--];	//대각선 leftdown방향으로 이동하면서 값을 sum에 저장.
				if (x > size - 1 || y < 0) 
				{
					ary[--x][++y] = sum; // 배열을 벗어나면 다시 되돌려 그 leftdown의 마지막 자리에 sum을 저장.
					break;
				}
			}
			++i;	//아래 열으로 이동.
		}
		else
		{
			while (x < size && y >= 0) // 0열과 1열일 경우
			{
				sum += ary[x++][y--];			//대각선 left방향으로 이동하면서 값을 sum에 저장.
				if (x > size - 1 || y < 0)
				{
					ary[--x][++y] = sum;	// 배열을 벗어나면 다시 되돌여 leftdown의 마지막 자리에 sum을 저장
					break;
				}
			}
			++j;	//다음 열 이도
		}

	}
	for (i = 0; i < size - 1; ++i)
		for (j = 1; j < size; ++j)
			ary[i][j] = 0;				//leftdown 0열과 마지막 행의 원소들을 제외한 모든 원소 0으로 초기화.

}

void upright(int** ary, int size)
{
	int i, j;
	i = j = 0;
	while (j < size)
	{
		int sum = 0, x, y;
		x = i;
		y = j; //[i][j]는 최종적으로 upright의 원소로 sum을 저장할 위치

		if (i == size - 1)	//만약의 마지막 행의 도달했을 시 
		{
			while (y < size && x >= 0)
			{
				sum += ary[x--][y++];	//대각선 방향으로 upright방향으로 원소들의 합을 sum에 저장
				if (y > size - 1 || x < 0)	
				{
					ary[++x][--y] = sum;	//만약 배열의 밖에 도달하면 되돌려 upright방향의 원소에 sum을 저장
					break;
				}
			}
			++j;	// 다음 열 이동.
		}
		else
		{
			while (y < size && x >= 0)	//0행과 1행일 경우
			{

				sum += ary[x--][y++];	//대각선 방향 upright방향으로 원소들의 합을 sum에 저장
				if (y > size - 1 || x < 0)
				{
					ary[++x][--y] = sum;	//만약 배열의 밖에 도달하면 되돌려 upright방향의 원소에 sum을 저장
					break;
				}
			}
			++i;	//다음 행 이동
		}
	}

	for (i = 1; i < size; ++i)
		for (j = 0; j < size - 1; ++j)
			ary[i][j] = 0;			//upright의 원소들을 제외한 모든 원소들 0으로 초기화
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