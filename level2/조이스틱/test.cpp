#include <string>
#include <iostream>

using namespace std;

class Joystick
{
    private :
    string myName; // 이름을 저장시킬 변수
    int stringlen; // 문자열 길이.

    public :
    Joystick(string myName);
    int getMinimum(); // 조이스틱을 움직여서 최소가 되는 그 값을 구하는 함수

    private :
    int isRightFast(int& tryNum, int& tryNum2); // 오른쪽이 빠른가? 왼쪽이 빠른가? 아니면 양쪽으로 왔다 갔다하는게 빠른가?
    int minTryChar(char tryChar); // 최소의 횟수로 형성되는 문자
};

Joystick::Joystick(string myName) : myName(myName)
{
    stringlen = myName.size();
}

// 조이스틱을 움직여서 최소가 되는 그 값을 구하는 함수
int Joystick::getMinimum()
{
    int answer = 0;
    int tryNum = 0;
    int tryNum2 = 0 ;

    // 첫 문자는 따로 계산한다.
    answer += minTryChar(myName[0]);
    if(stringlen == 1) return answer;

    int derec = isRightFast(tryNum, tryNum2);
    if( derec == 1)
    { // 오른쪽 이동이 빠른 경우
        for(int i=1; i<tryNum+1; i++)
        {
            answer += minTryChar(myName[i]);
        }
    }
    else if( derec == 2)
    { // 왼쪽 이동이 빠른 경우
        for(int i=stringlen-1; i>stringlen-tryNum-1; i--)
        { 
            answer += minTryChar(myName[i]);
        }
    }
    else
    { // 양쪽으로 왔다 갔다 하는게 빠른 경우
        for(int i=1; i<tryNum+1; i++)
        {
            answer += minTryChar(myName[i]);
        }
        // 왼쪽 이동이 빠른 경우
        for(int i=stringlen-1; i>stringlen-tryNum2-1; i--)
        { 
            answer += minTryChar(myName[i]);
        }
    }

    if( derec == 3) return (answer + tryNum*2 + tryNum2);
    return (answer + tryNum);
}

// 오른쪽이 빠른가? 왼쪽이 빠른가? 아니면 양쪽으로 왔다 갔다하는게 빠른가?
int Joystick::isRightFast(int& tryNum, int& tryNum2)
{
    int rightNum = 0; // 오른쪽 이동 횟수
    int leftNum = 0; // 왼쪽 이동 횟수
    int middleNum = 0; // 오른쪽 -> 왼쪽 이동횟수
    int middleNumR = 0; // Right
    int middleNumL = 0; // Left

    // 오른쪽 측정
    for(int i=stringlen-1; i>=0; i--)
    {
        if(myName.at(i) != 'A') 
        {
            rightNum = i;
            break;
        }
    }

    // 왼쪽 측정
    for(int i=1; i<stringlen; i++)
    {
        if(myName.at(i) != 'A')
        {
            leftNum = stringlen - i;
            break;
        }
    }

    // 오른쪽 -> 왼쪽 측정
    for(int i=1; i<stringlen/2; i++)
    {
        if(myName.at(i) != 'A')
        {
            middleNumR = i;
        }
    }
    for(int i=stringlen-1; i>=stringlen/2; i--)
    {
        if(myName.at(i) != 'A') 
        {
            middleNumL = stringlen - i;
        }
    }
    middleNum = middleNumR*2 + middleNumL;
    
    if(middleNum<leftNum && middleNum<rightNum)
    {
        tryNum = middleNumR;
        tryNum2 = middleNumL;
        return 3;
    }
    else if(rightNum<=leftNum)
    {
        tryNum = rightNum;
        return 1;
    }
    else
    {
        tryNum = leftNum;
        return 2;
    }
}

// 최소의 횟수로 형성되는 문자
int Joystick::minTryChar(char tryChar)
{
    return (tryChar <= 'M') ? (tryChar - 'A') : ('Z' - tryChar + 1);
}

int test()
{
    cout << "Case 1 : 'JEROEN' -> 56 / " << Joystick("JEROEN").getMinimum() << ":" << (Joystick("JEROEN").getMinimum()==56) << endl;
    cout << "Case 2 : 'JAN' -> 23 / " << Joystick("JAN").getMinimum() << ":" << (Joystick("JAN").getMinimum()==23) << endl ;
    cout << "Case 3 : 'AAB' -> 2 / " << Joystick("AAB").getMinimum() << ":" << (Joystick("AAB").getMinimum()==2) << endl ;
    cout << "Case 4 : 'AAZ' -> 2 / " << Joystick("AAZ").getMinimum() << ":" << (Joystick("AAZ").getMinimum()==2) << endl ;
    cout << "Case 5 : 'CAAAC' -> 5 / " << Joystick("CAAAC").getMinimum() << ":" << (Joystick("CAAAC").getMinimum()==5) << endl ;
    cout << "Case 6 : 'ABCDE' -> 14 / " << Joystick("ABCDE").getMinimum() << ":" << (Joystick("ABCDE").getMinimum()==14) << endl;
}

int main ()
{
    test();
}
