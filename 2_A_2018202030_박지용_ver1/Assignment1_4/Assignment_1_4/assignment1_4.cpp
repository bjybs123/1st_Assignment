#include <iostream>

using namespace std;

#define MAXLINE 100

int main()
{
	int i = 0;
	char c;
	char str[MAXLINE];
	while (cin.get(c) && c != '\n')
		str[i++] = c;
	str[i] = '\0';	//�Է¹��� ���� c�� �迭�� i��° ���ҿ� ����.

	i = 0;
	while (str[i])
	{
		if (isalpha(str[i]))	//���࿡ i���� ���� ���ĺ��̶��
			cout << (char)tolower(str[i]);	//lower case�� ��ȯ �� ĳ���������� ����Ѵ�.
		++i;
	}
	cout << endl;

}