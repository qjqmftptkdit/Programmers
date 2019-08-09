#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Get124
{
    private :
    int number; // 10진수 자연수 n을 저장

    public :
    Get124(int number); // 생성자
    string getResult(); // 124나라의 숫자로 변환된 결과를 반환

    private :
    int getDigit(int number); // 해당 10진법 number가 124나라의 숫자로 변환되었을 경우의 자릿수를 반환한다.
    string get124Num(int number, int digist); // 10진법 number와 124나라로 변환되었을 경우의 자릿수를 입력받으면, 124나라로 변환된 결과를 반환한다.
    string get124NumFromremainder(int number); // 나머지로 반환된 숫자를 124나라의 숫자로 변환한다.
};

// 생성자
Get124::Get124(int number) : \
    number(number) {} ;

// 124나라의 숫자로 변환된 결과를 반환
string Get124::getResult()
{
    int digist = getDigit(number);
    return get124Num(number, digist);
}

// 해당 10진법 number가 124나라의 숫자로 변환되었을 경우의 자릿수를 반환한다.
int Get124::getDigit(int number)
{
    int checkNum = 0;
    int i = 0;

    while(true)
    {
        i++;
        if(checkNum<number && number<=(checkNum+pow(3,i)))
            break;
        checkNum += pow(3,i);
    }

    return i;
}

// 10진법 number와 124나라로 변환되었을 경우의 자릿수를 입력받으면, 124나라로 변환된 결과를 반환한다.
string Get124::get124Num(int number, int digist)
{
    int share = 0;
    int remainder = 0;
    string result = "";

    for(int i=0; i<digist; i++)
    {
        if(number!=0)
        {
            remainder = number%3;
            result = get124NumFromremainder(remainder) + result;

            share = number/3 ;
            number = share ;
        }
    }

    return result;
}

// 나머지로 반환된 숫자를 124나라의 숫자로 변환한다.
string Get124::get124NumFromremainder(int number)
{
    switch (number)
    {
        case 0 :
            return "4";
        case 1 :
            return "1";
        case 2 :
            return "2";
    }
}

void test(int caseNum, int para, string result)
{
   cout << "Case " + to_string(caseNum) + " : (" + to_string(para) + ") -> " + result + " / ";
   cout << Get124(para).getResult() << " : ";
   cout << ((Get124(para).getResult() == result) ? "TRUE" : "FALSE") << endl;
}

int main()
{
    test(1, 1, "1");
    test(2, 3, "4");
    test(3, 5, "12");
    test(4, 8, "22");
    test(5, 10, "41");
}