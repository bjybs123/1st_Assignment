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
	char op;	//operator command�� �޴� ������ ����

	initialize(matrix);
	
	
	
	while (1)
	{
		
		print(matrix);
		cout << "Command : ";

		if (isFull(matrix, current_x, current_y))	//���࿡ ����� a�� �ѷ��ο� ���� ��� ���α׷� ����
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
		
		system("cls");		//Ŀ�ǵ�â �����

	}
}

bool isFull(char(*matrix)[MAXVOL], int& x, int& y)
{
	if (y - 1 < 0 || matrix[x][y - 1] == 'a')		//������ �迭�� ���̰ų� a�� ���ִ� ���
	{
		
		if (x + 1 >= MAXVOL || matrix[x + 1][y] == 'a')		//�ϴ��� �迭�� ���̰ų� a�� ���ִ� ���
		{
			
			if (y + 1 >= MAXVOL || matrix[x][y + 1] == 'a')		//������ �迭�� ���̰ų� a�� ���ִ� ���
			{
				
				if (x - 1 < 0 || matrix[x - 1][y] == 'a')		//����� �迭�� ���̰ų� a�� ���ִ� ���
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
		for (j = 0; j < MAXVOL; ++j)	//��� ���ҵ��� '0'���� �ʱ�ȭ
			matrix[i][j] = '0';
	}

	matrix[0][0] = 'a';	//�������� [0][0]�� 'a'�� �ʱ�ȭ
	return;
}

bool left(char(*matrix)[MAXVOL], int& x, int& y)
{
	if (y - 1 >= 0 && matrix[x][y - 1] != 'a')	//���ῡ y - 1�� 0���� ũ�� 'a'�ƴϸ� false��ȯ
		matrix[x][--y] = 'a';					//y - 1�� üũ�ϴ°��� �迭�� ������ ������ �ʰ� �ϱ� ����
	
	else
		return true;
	return false;
}

bool right(char(*matrix)[MAXVOL], int& x, int& y)
{
	if (y + 1 < MAXVOL && matrix[x][y + 1] != 'a')	//���࿡ y + 1�� MAXVOL���� �۰� 'a'�� �ƴϸ� false ��ȯ
		matrix[x][++y] = 'a';
	else
		return true;
	return false;
}

bool up(char(*matrix)[MAXVOL], int& x, int& y)	//���࿡ x - 1�� MAXVOL���� �۰� 'a'�� �ƴϸ� false ��ȯ
{
	if (x - 1 >= 0 && matrix[x - 1][y] != 'a')
		matrix[--x][y] = 'a';
	else
		return true;
	return false;
}

bool down(char(*matrix)[MAXVOL], int& x, int& y)	//���࿡ x + 1�� MAXVOL���� �۰� 'a'�� �ƴϸ� false ��ȯ
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
		for (j = 0; j < MAXVOL; ++j)	//��� ���� ���
			cout << " " << matrix[i][j];
		cout << endl;

	}
}