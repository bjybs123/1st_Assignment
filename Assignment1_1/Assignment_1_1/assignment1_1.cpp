#include <iostream>

using namespace std;


int main()
{
	int num, i;
	long long Fibo[51] = { 0 };	 //50번쨰 항이 long이 표현 할 수 있는 최대 범위를 초과하여 long long배열 선언 및 0으로 초기화

	cout << "Number : ";
	cin >> num;         //출력하고자 하는 num번째 항 을 입력받음. 

	Fibo[1] = Fibo[2] = 1;	//1번째 항과 2번째항은 1

	for (i = 3; i < 51; ++i)
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];	//피보나치 수열의 조건

	cout << Fibo[num] << endl;
}
