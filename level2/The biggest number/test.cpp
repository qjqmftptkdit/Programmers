#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Get the biggist number by connecting numbers in array
class theBiggistNumber {
    private :
    vector<int> numberArray; 

    public :
    theBiggistNumber(vector<int> numberArray); // Constructor
    string getResult(); // Get result by string type

    private :
    map<string, int, greater<string>> sortNumberArray(vector<int> numberArray); // Sortting numbers to connect biggetst number
    string connectNumbers(map<string, int, greater<string>> sortedNumber); // Connect numbers in array order
    string stretchNumber(int number); // The maximum number is 100,000. so, that function will strecth number by adding last number to 6.
};

// Constructor
theBiggistNumber::theBiggistNumber(vector<int> numberArray) : numberArray(numberArray){}

// Get result by string type
string theBiggistNumber::getResult()
{
    map<string, int, greater<string>> sortedNumber = sortNumberArray(numberArray);
    return connectNumbers(sortedNumber);
}

// Sortting numbers to connect biggetst number
map<string, int, greater<string>> theBiggistNumber::sortNumberArray(vector<int> numberArray)
{
    map<string, int, greater<string>> sortedNumber;
    for(int number : numberArray)
        sortedNumber[stretchNumber(number)] = number;
    return sortedNumber;
}

// The maximum number is 100,000. so, that function will strecth number by adding last number to 6.
string theBiggistNumber::stretchNumber(int number)
{
    string number_s = to_string(number);
    char lastNumber = number_s.back();

    while(number_s.length() < 6) number_s += lastNumber; // Add lastnumber to string.
    return number_s;
} 

// Connect numbers in array order
string theBiggistNumber::connectNumbers(map<string, int, greater<string>> sortedNumber)
{
    string result = "";
    for(auto num : sortedNumber)
        result += to_string(num.second);
    if(atoi(result.c_str()) == 0) return "0";
    return result;
}

void printVector(vector<int> numbers)
{
    cout << "[ ";
    for(int num : numbers)
        cout << num << ", ";
    cout << " ]";
}

// Function for testing
void test(vector<int> numbers, string result)
{
    static int caseNum = 0;
    caseNum++;

    cout << "case " << caseNum << " : " ; printVector(numbers); cout << " -> " << result ;
    cout << " : " << theBiggistNumber(numbers).getResult(); 
    cout << " : " << ((theBiggistNumber(numbers).getResult() == result) ? "SUCCESS" : "FALE") << endl;
}

int main ()
{
    test(vector<int>({6, 10, 2}), "6210");
    test(vector<int>({3, 30, 34, 5, 9}), "9534330");
    test(vector<int>{0,0,0,0,0}, "0");
}