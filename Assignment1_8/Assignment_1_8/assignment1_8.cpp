#include <iostream>
#include <stdlib.h>

#define MAXVOL 5

using namespace std;

bool left(char(*)[MAXVOL], int& x, int& y);
bool right(char(*)[MAXVOL], int& x, int& y);
bool up(char(*)[MAXVOL], int& x, int& y);
bool down(char(*)[MAXVOL], int& x, int& y);
bool isFull(char(*)[MAXVOL], int& x, int& y);
void initialize(char(*)[MAXVOL]);
void print(char(*)[MAXVOL]);

int main()
{
	char matrix[MAXVOL][MAXVOL] = { 0 };
	int current_x, current_y;
	bool terminateCode = false;
	current_x = current_y = 0;
	char op;	//operator command를 받는 문자형 변수

	initialize(matrix);
	
	
	
	while (1)
	{
		
		print(matrix);
		cout << "Command : ";

		if (isFull(matrix, current_x, current_y))	//만약에 사방이 a로 둘러싸여 잇을 경우 프로그램 종료
		{
			cout << "END" << endl;
			return 0;
		}

		cin >> op;

		switch (op)
		{
		case 'a':
			terminateCode = left(matrix, current_x, current_y);
			break;
		case 'd':
			terminateCode = right(matrix, current_x, current_y);
			break;
		case 'w':
			terminateCode = up(matrix, current_x, current_y);
			break;
		case 's':
			terminateCode = down(matrix, current_x, current_y);
			break;
		default:
			break;
		}
		
		system("cls");		//커맨드창 지우기

	}
}

bool isFull(char(*matrix)[MAXVOL], int& x, int& y)
{
	if (y - 1 < 0 || matrix[x][y - 1] == 'a')		//좌측이 배열의 밖이거나 a로 차있는 경우
	{
		
		if (x + 1 >= MAXVOL || matrix[x + 1][y] == 'a')		//하단이 배열의 밖이거나 a로 차있는 경우
		{
			
			if (y + 1 >= MAXVOL || matrix[x][y + 1] == 'a')		//우측이 배열의 밖이거나 a로 차있는 경우
			{
				
				if (x - 1 < 0 || matrix[x - 1][y] == 'a')		//상단이 배열의 밖이거나 a로 차있는 경우
				{
					return true;
				}
			}
		}
	}
					
	return false;
}

void initialize(char(*matrix)[MAXVOL])
{
	int i, j;
	i = j = 0;

	for(i = 0; i < MAXVOL; ++i)
	{
		for (j = 0; j < MAXVOL; ++j)	//모든 원소들을 '0'으로 초기화
			matrix[i][j] = '0';
	}

	matrix[0][0] = 'a';	//시작점인 [0][0]을 'a'로 초기화
	return;
}

bool left(char(*matrix)[MAXVOL], int& x, int& y)
{
	if (y - 1 >= 0 && matrix[x][y - 1] != 'a')	//만얀에 y - 1이 0보다 크고 'a'아니면 false반환
		matrix[x][--y] = 'a';					//y - 1을 체크하는것은 배열의 밖으로 나가지 않게 하기 위함
	
	else
		return true;
	return false;
}

bool right(char(*matrix)[MAXVOL], int& x, int& y)
{
	if (y + 1 < MAXVOL && matrix[x][y + 1] != 'a')	//만약에 y + 1이 MAXVOL보다 작고 'a'가 아니면 false 반환
		matrix[x][++y] = 'a';
	else
		return true;
	return false;
}

bool up(char(*matrix)[MAXVOL], int& x, int& y)	//만약에 x - 1이 MAXVOL보다 작고 'a'가 아니면 false 반환
{
	if (x - 1 >= 0 && matrix[x - 1][y] != 'a')
		matrix[--x][y] = 'a';
	else
		return true;
	return false;
}

bool down(char(*matrix)[MAXVOL], int& x, int& y)	//만약에 x + 1이 MAXVOL보다 작고 'a'가 아니면 false 반환
{
	if (x + 1 < MAXVOL && matrix[x + 1][y] != 'a')
		matrix[++x][y] = 'a';
	else
		return true;
	return false;
}

void print(char(*matrix)[MAXVOL])
{
	int i, j;
	for (i = 0; i < MAXVOL; ++i)
	{
		for (j = 0; j < MAXVOL; ++j)	//모든 원소 출력
			cout << " " << matrix[i][j];
		cout << endl;

	}
}