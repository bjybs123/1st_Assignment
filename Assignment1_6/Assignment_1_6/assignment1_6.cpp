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
	cout << "Data :";	//data를 입력
	
	while (cin.get(numInput) && numInput != '\n')
	{
		checksum += numInput - 48; //입력 받는 문자를 48를 빼주어 int형 변수checksum에 더한다.
		check_data[i++] = numInput;//입력 받은 문자를 문자열에 저장
	}
	checksum %= 10;	//저장된 checkcum을 checksum number로 만들어 주기위해 10으로 나눈 나머지를 저장.
	check_data[i++] = (char)checksum + 48; //문자열 마지막에 checksum을 저장.
	check_data[i] = '\0';//최종적으로 널문자를 삽입해 문자열의 끝을 알림

	cout << "Send data :" << check_data << endl;
	
	transmission_process(check_data);
}

void transmission_process(const char* data)
{
	srand((unsigned int)time(NULL));
	char manipulatedData[MAXVOL];	//에러를 생성할 새로운 문자열
	int i = 0;
	while (*data != '\0')
		manipulatedData[i++] = *data++;		//에러를 생성할 문자열에 원래 data문자열을 복사
	manipulatedData[i] = '\0';

	int randomNum;
	int randomSub = rand() % 5;		//4개의 인풋과 체크썸을 포함한 5개의 원소중에서 error를 생성할 원소 위치(subscript)를 정하는 랜덤 넘버
	
	while (true)
	{
		randomNum = rand() % 10;	//0부터 9까지의 랜덤넘버 생성
		if (randomNum != manipulatedData[randomSub]) //만약에 생성한 랜덤넘버와 manipulatedData[randomSub]가 일치 안한다면
			if (randomNum >= 0 && randomNum <= 3)	//만약 생선된 난수가 0과 3사이에 있다면 문자열에 저장한다. 
			{
				manipulatedData[randomSub] = randomNum + 48;	//0부터9에서 40퍼센트의 확률을 0부터 3까지의 숫자가 나왓을 경우라고 가정
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
	const char* p = data;	//포인터 p를 생성 point to data
	while (*p)
		p++;	//*p가 존재할때 위치를 널문자에 다다르게 더한다. 
	--p;	//널문자 전인 checksum위치에 point하게 한다. 

	checksum = *p-- - 48;	//checksum에 p가 포인팅하는 배열의 체크섬을 int형 checksum에 저장한다

	while (p >= data)
	{
										 //data의 위치는 data[0]값이기 떄문에 p의 현재 위치는 data[3]이다
		Sum += *p - 48;					 //감소시키며 sum에 data에 입력받은 문자들을 더한다. 
		p--;
	}
	Sum %= 10;				//Sum에 저장된 값을 10나눈 값의 나머지를 구한다. 
	
	if(Sum == checksum)
		cout << checksum << "==" << Sum << "\tError is not Ocurred!" <<  endl;
	else
		cout << checksum << "!=" << Sum << "\tError!" << endl;
}
