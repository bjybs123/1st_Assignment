#include <iostream>

using namespace std;


int main()
{
	int num, i;
	long long Fibo[51] = { 0 };	 //50���� ���� long�� ǥ�� �� �� �ִ� �ִ� ������ �ʰ��Ͽ� long long�迭 ���� �� 0���� �ʱ�ȭ

	cout << "Number : ";
	cin >> num;         //����ϰ��� �ϴ� num��° �� �� �Է¹���. 

	Fibo[1] = Fibo[2] = 1;	//1��° �װ� 2��°���� 1

	for (i = 3; i < 51; ++i)
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];	//�Ǻ���ġ ������ ����

	cout << Fibo[num] << endl;
}
