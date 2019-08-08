#include <iostream>

using namespace std;

class SumOfBtNum
{
    private :
    int num1; // 첫번째 수
    int num2; // 두번째 수

    public :
    SumOfBtNum(int num1, int num2); // 생성자
    long long getResult(); // 두 수 사이의 합을 반환한다.
    
    private :
    int getRelationOfBtNum(int num1, int num2); // num1==num2이면 0, num1>num2이면 1, num1<num2이면 2를 반환한다.
    long long getSumOfBtNum(int num1, int num2); // num1>num2라고 가정하고, num1~num2 사이의 합을 반환한다.
};

// 생성자
SumOfBtNum::SumOfBtNum(int num1, int num2) : num1(num1), num2(num2) {}

// 두 수 사이의 합을 반환한다.
long long SumOfBtNum::getResult()
{
    switch(getRelationOfBtNum(num1, num2))
    {
        case 0 :
            return num1; 
        case 1 :
            return getSumOfBtNum(num2,num1);
        case 2 :
            return getSumOfBtNum(num1,num2);
    }
}

// num1==num2이면 0, num1>num2이면 1, num1<num2이면 2를 반환한다.
int SumOfBtNum::getRelationOfBtNum(int num1, int num2)
{
    if(num1 == num2) return 0;
    else if (num1 > num2) return 1;
    else return 2;
}

// num1>num2라고 가정하고, num1~num2 사이의 합을 반환한다.
long long SumOfBtNum::getSumOfBtNum(int num1, int num2)
{
    long long result = 0;
    for(int i=num1; i<=num2; i++)
    {
        result += i;
    }
    return result;
}

void test()
{
    cout << "Case 1 : (3,5) -> 12 / " << SumOfBtNum(3,5).getResult() << " : " << ((SumOfBtNum(3,5).getResult() == 12) ? "TRUE" : "FALSE") << endl;
    cout << "Case 2 : (3,3) -> 3 / " << SumOfBtNum(3,3).getResult() << " : " << ((SumOfBtNum(3,3).getResult() == 3) ? "TRUE" : "FALSE") << endl;
    cout << "Case 3 : (5,3) -> 12 / " << SumOfBtNum(5,3).getResult() << " : " << ((SumOfBtNum(5,3).getResult() == 12) ? "TRUE" : "FALSE") << endl;
}

int main ()
{
    test();
}