#include <iostream>
#include <string>

using namespace std;

class IsHarshadNumber
{
    private :
    int number; // Given number

    public :
    IsHarshadNumber(int number); // Constructor
    bool getResult();

    private :
    int getSumOfDigit(int number); // Return sum of digit in number
};

// Constructor
IsHarshadNumber::IsHarshadNumber(int number) : number(number) {} 

bool IsHarshadNumber::getResult() 
{
    int sumOfDigit = getSumOfDigit(number);
    return !(number % sumOfDigit);
}

// Return sum of digit in number
int IsHarshadNumber::getSumOfDigit(int number)
{
    int sumOfDigit = 0;
    for(char digit : to_string(number))
        sumOfDigit += atoi(&digit);
    return sumOfDigit;
}

// Function for testing
void test(int number, bool result)
{
    static int caseNum = 0;
    cout << "case " << caseNum << " : " << number << " -> " << ((result) ? "TRUE" : "FALSE") << " : " ;
    cout << ((IsHarshadNumber(number).getResult()) ? "TRUE" : "FALSE") << " : " << ((IsHarshadNumber(number).getResult() == result) ? "SUCCESS" : "FALE") << endl; 
}

int main ()
{
    test(10, true);
    test(12, true);
    test(11, false);
    test(13, false);
}