#include <iostream>
#include <string>
using namespace std;

#define MAXVOL 20

void sender(char* data);
void transmission_process(const char* data);
void receiver(const char* data);

int main()
{
	char data[MAXVOL];
	sender(data);
}

void sender(char *data)
{
	char check_data[MAXVOL];
	char numInput;
	int checksum = 0, i = 0;
	cout << "Data :";	//data�� �Է�
	
	while (cin.get(numInput) && numInput != '\n')
	{
		checksum += numInput - 48; //�Է� �޴� ���ڸ� 48�� ���־� int�� ����checksum�� ���Ѵ�.
		check_data[i++] = numInput;//�Է� ���� ���ڸ� ���ڿ��� ����
	}
	checksum %= 10;	//����� checkcum�� checksum number�� ����� �ֱ����� 10���� ���� �������� ����.
	check_data[i++] = (char)checksum + 48; //���ڿ� �������� checksum�� ����.
	check_data[i] = '\0';//���������� �ι��ڸ� ������ ���ڿ��� ���� �˸�

	cout << "Send data :" << check_data << endl;
	
	transmission_process(check_data);
}

void transmission_process(const char* data)
{
	srand((unsigned int)time(NULL));
	char manipulatedData[MAXVOL];	//������ ������ ���ο� ���ڿ�
	int i = 0;
	while (*data != '\0')
		manipulatedData[i++] = *data++;		//������ ������ ���ڿ��� ���� data���ڿ��� ����
	manipulatedData[i] = '\0';

	int randomNum;
	int randomSub = rand() % 5;		//4���� ��ǲ�� üũ���� ������ 5���� �����߿��� error�� ������ ���� ��ġ(subscript)�� ���ϴ� ���� �ѹ�
	
	while (true)
	{
		randomNum = rand() % 10;	//0���� 9������ �����ѹ� ����
		if (randomNum != manipulatedData[randomSub]) //���࿡ ������ �����ѹ��� manipulatedData[randomSub]�� ��ġ ���Ѵٸ�
			if (randomNum >= 0 && randomNum <= 3)	//���� ������ ������ 0�� 3���̿� �ִٸ� ���ڿ��� �����Ѵ�. 
			{
				manipulatedData[randomSub] = randomNum + 48;	//0����9���� 40�ۼ�Ʈ�� Ȯ���� 0���� 3������ ���ڰ� ������ ����� ����
				break;
			}
	}

	cout << "Received datd : " << manipulatedData << endl;


	receiver(manipulatedData);
}

void receiver(const char* data)
{
	int Sum = 0;
	int checksum;
	const char* p = data;	//������ p�� ���� point to data
	while (*p)
		p++;	//*p�� �����Ҷ� ��ġ�� �ι��ڿ� �ٴٸ��� ���Ѵ�. 
	--p;	//�ι��� ���� checksum��ġ�� point�ϰ� �Ѵ�. 

	checksum = *p-- - 48;	//checksum�� p�� �������ϴ� �迭�� üũ���� int�� checksum�� �����Ѵ�

	while (p >= data)
	{
										 //data�� ��ġ�� data[0]���̱� ������ p�� ���� ��ġ�� data[3]�̴�
		Sum += *p - 48;					 //���ҽ�Ű�� sum�� data�� �Է¹��� ���ڵ��� ���Ѵ�. 
		p--;
	}
	Sum %= 10;				//Sum�� ����� ���� 10���� ���� �������� ���Ѵ�. 
	
	if(Sum == checksum)
		cout << checksum << "==" << Sum << "\tError is not Ocurred!" <<  endl;
	else
		cout << checksum << "!=" << Sum << "\tError!" << endl;
}
