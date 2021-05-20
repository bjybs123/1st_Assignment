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
	str[i] = '\0';	//입력받은 문자 c를 배열의 i번째 원소에 저장.

	i = 0;
	while (str[i])
	{
		if (isalpha(str[i]))	//만약에 i번쨰 항이 알파벳이라면
			cout << (char)tolower(str[i]);	//lower case로 변환 후 캐릭터형으로 출력한다.
		++i;
	}
	cout << endl;

}