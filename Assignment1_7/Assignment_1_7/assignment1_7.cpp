#include <iostream>

#define MAXVOL 100

using namespace std;


bool isNum(char);
bool isOperator(char);
bool isInput(char);
void faulty(void);

int main()
{
	char formula[MAXVOL];
	int parentheseIn = 0, i = 0;
	char c;
	 
	cout << "formula : ";
	while (cin.get(c) && c != '\n')
		if (c != ' ' && c != '\t')
			formula[i++] = c;		//c���ڿ� ������ ������ ���ڸ� ���ڿ� formula�� ����.
	formula[i] = '\0';

	i = 0;

	while (formula[i] != '\0')	//�ι��ڰ� �Ë����� ���� �ϳ��ϳ� �˻�
	{
		if (!isInput(formula[i]))	//����, ��ȣ, operator�� �ƴ� ��� faulty�Լ� ȣ��
		{
			faulty();
			return 0;
		}

		if (isNum(formula[i]))	//���ڰ� �����϶�
		{
			if (formula[i + 1] == '(' || formula[i + 1] == 'x')	// ���� ���ڰ� ( ��ȣ Ȥ�� x�� ������ faulty ȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
			else if(formula[i - 1] == ')' || formula[i - 1] == 'x')	//���� ���ڰ� )��ȣ Ȥ�� x�� faultyȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
		}
		else if (isOperator(formula[i]))	//���ڰ� operator�϶�
		{
			if (formula[i + 1] == ')' || isOperator(formula[i + 1]))	//���� ���ڰ� )��ȣ Ȥ�� operator�� ��� faulty �� ���α׷� ����
			{
				faulty();
				return 0;
			}
			else if(i - 1 < 0 || formula[i - 1] == '(' || isOperator(formula[i - 1]))	//���� ���ڰ� (��ȣ Ȥ�� operator�� ��� faultyȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
			
			
		}
		else if (formula[i] == 'x')	//���ڰ� x�� ���
		{
			if (formula[i + 1] == '(' || formula[i + 1] == 'x' || isNum(formula[i + 1]))	// ���� ���ڰ� �����̰ų� Ȥ�� x�� ������ faulty ȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
			else if (formula[i - 1] == ')' || isNum(formula[i - 1]) || formula[i - 1] == 'x')	// ���� ���ڰ� ) ��ȣ Ȥ�� ���ڸ� faulty ȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
		}
		else if (formula[i] == ')')	//���ڰ� )�� ���
		{
			--parentheseIn;	//������ȣ�� �Է� �Ǿ����Ƿ� - 1 ����.
			if(formula[i + 1] == '(' || formula[i + 1] == 'x' || isNum(formula[i + 1]))	//���� ���ڰ� (���� Ȥ�� x�� ��� faulty�Լ� ȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
			else if(isOperator(formula[i - 1]))	//���� ���ڰ� operator�� ��� faulty�Լ� ȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
		}
		else if (formula[i] == '(')	//���ڰ� (�� ���
		{
			++parentheseIn;
			if (isOperator(formula[i + 1]))	// ���� ���ڰ� operator�� ��� faulty ȣ�� �� ���α׷� ����
			{
				faulty();
				return 0;
			}
			if (i - 1 > 0)
			{
				if (formula[i - 1] == ')' || isNum(formula[i - 1]) || formula[i - 1] == 'x')	// ���� ���ڰ� )��ȣ, ����, x�� ��� faulty ȣ�� �� ���α׷� ����
				{
					faulty();
					return 0;
				}
			}
		}
		
		++i;
	}
	if (parentheseIn != 0)		//��ȣ ���ڰ� 0�� �ƴϸ� faultyȣ�� �� ���α׷� ����
	{
		faulty();
		return 0;
	}
	cout << "integrity" << endl;
	return 0;
}

bool isInput(char input)
{
	if (isNum(input) || isOperator(input) || input == '(' || input == ')' || input == 'x')
		return true;
	return false;
}

bool isNum(char num)
{
	if (num >= 48 && num <= 57)
		return true;
	return false;
}

bool isOperator(char op)
{
	switch (op)
	{
	case '-':
	case '+':
	case '*':
	case '/':
		return true;
	default:
		break;
	}
	return false;
}


void faulty(void)
{
	cout << "faulty" << endl;
}