#include <string>
#include <iostream>

using namespace std;

class CheckString
{
    private :
    string word; // Provided word.

    public :
    CheckString(string word); // Constructor
    bool getResult(); 

    private :
    int getNumOfChar(string word, char target); // Get num of target in word
};

// Constructor
CheckString::CheckString(string word) : word(word) {}

bool CheckString::getResult()
{
    return (getNumOfChar(word, 'p')+getNumOfChar(word, 'P')) == (getNumOfChar(word, 'y')+getNumOfChar(word, 'Y'));
}

// Get num of target in word
int CheckString::getNumOfChar(string word, char target)
{
    int numOfChar=0;
    for(char c : word)
    {
        if(c == target) numOfChar++; // If there is targeted char, numOfChar is increased.
    }
    return numOfChar; // Return num of targeted char.
}

// Function for test
void test(string word, bool result)
{
    static int caseNum=0;
    caseNum++;

    cout << "Case " << caseNum << " : \"" << word << "\" -> " << ((result) ? "TRUE" : "FALSE") ;
    cout << " : " << CheckString(word).getResult() << " : " << ((result == CheckString(word).getResult()) ? "PASS" : "FAIL") << endl;
}

int main ()
{
    test("pPooyY", true);
    test("Pyy", false);
}
