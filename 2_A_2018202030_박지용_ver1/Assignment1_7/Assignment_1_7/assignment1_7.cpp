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
			formula[i++] = c;		//c문자에 공백을 제외한 문자를 문자열 formula에 저장.
	formula[i] = '\0';

	i = 0;

	while (formula[i] != '\0')	//널문자가 올떄가지 문자 하나하나 검사
	{
		if (!isInput(formula[i]))	//숫자, 괄호, operator가 아닐 경우 faulty함수 호출
		{
			faulty();
			return 0;
		}

		if (isNum(formula[i]))	//문자가 숫자일때
		{
			if (formula[i + 1] == '(' || formula[i + 1] == 'x')	// 다음 문자가 ( 괄호 혹은 x가 있으면 faulty 호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
			else if(formula[i - 1] == ')' || formula[i - 1] == 'x')	//이전 문자가 )괄호 혹은 x면 faulty호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
		}
		else if (isOperator(formula[i]))	//문자가 operator일때
		{
			if (formula[i + 1] == ')' || isOperator(formula[i + 1]))	//다음 문자가 )괄호 혹은 operator일 경우 faulty 및 프로그램 종료
			{
				faulty();
				return 0;
			}
			else if(i - 1 < 0 || formula[i - 1] == '(' || isOperator(formula[i - 1]))	//이전 문자가 (괄호 혹은 operator일 경우 faulty호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
			
			
		}
		else if (formula[i] == 'x')	//문자가 x일 경우
		{
			if (formula[i + 1] == '(' || formula[i + 1] == 'x' || isNum(formula[i + 1]))	// 다음 문자가 숫자이거나 혹은 x가 있으면 faulty 호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
			else if (formula[i - 1] == ')' || isNum(formula[i - 1]) || formula[i - 1] == 'x')	// 이전 문자가 ) 괄호 혹은 숫자면 faulty 호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
		}
		else if (formula[i] == ')')	//문자가 )일 경우
		{
			--parentheseIn;	//닫힌괄호가 입력 되었으므로 - 1 해줌.
			if(formula[i + 1] == '(' || formula[i + 1] == 'x' || isNum(formula[i + 1]))	//다음 문자가 (문자 혹은 x일 경우 faulty함수 호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
			else if(isOperator(formula[i - 1]))	//이전 문자가 operator일 경우 faulty함수 호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
		}
		else if (formula[i] == '(')	//문자가 (일 경우
		{
			++parentheseIn;
			if (isOperator(formula[i + 1]))	// 다음 문자가 operator일 경우 faulty 호출 및 프로그램 종료
			{
				faulty();
				return 0;
			}
			if (i - 1 > 0)
			{
				if (formula[i - 1] == ')' || isNum(formula[i - 1]) || formula[i - 1] == 'x')	// 이전 문자가 )괄호, 숫자, x일 경우 faulty 호출 및 프로그램 종료
				{
					faulty();
					return 0;
				}
			}
		}
		
		++i;
	}
	if (parentheseIn != 0)		//괄호 숫자가 0이 아니면 faulty호출 및 프로그램 종료
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