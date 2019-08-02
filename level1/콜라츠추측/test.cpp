#include <iostream>

using namespace std;

class Collatz
{
    private:
    long long number;

    public:
    Collatz(long long number) : number(number) {}
    int returnLoopNum ();
};

int Collatz::returnLoopNum()
{
    int loopNum = 0;

    while(number != 1)
    {
        number = (number%2==0) ? (number/2) : (number*3+1);  
        loopNum++;
        if (loopNum>=500) return -1;
    }

    return loopNum;
}

int main ()
{
    cout << (Collatz(6).returnLoopNum());
}