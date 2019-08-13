#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class SortStrings
{
    private :
    vector<string> strings; // 문자열들을 저장해놓은 배열.
    int n; // 어떤 인덱스를 기준으로 정렬할 것인가?

    public :
    SortStrings(vector<string> strings, int n); // 생성자
    vector<string> getResult(); // 특정 인덱스 n으로 정렬된 결과를 반환한다.

    private :
    // strings가 주어졌을 경우, 이를 기반으로 n 인덱스의 문자를 map의 첫번째 인덱스로, 그 내부의 map의 키로는 그 단어를 집어넣는다.
    map<char, map<string,string>> getMapOfStrings(vector<string> strings, int n);
    // 정렬된 map이 반환하는 결과를 얻어서 vector<string>으로 만들어서 반환시킨다.
    vector<string> getResultOfMap(map<char, map<string,string>> mapOfStrings);
};

// 생성자
SortStrings::SortStrings(vector<string> strings, int n) \
    : strings(strings), n(n) {}

// 특정 인덱스 n으로 정렬된 결과를 반환한다.
vector<string> SortStrings::getResult()
{
    map<char, map<string,string>> mapOfStrings = getMapOfStrings(strings,n);
    return getResultOfMap(mapOfStrings);
}

// strings가 주어졌을 경우, 이를 기반으로 n 인덱스의 문자를 map의 첫번째 인덱스로, 그 내부의 map의 키로는 그 단어를 집어넣는다.
map<char, map<string,string>> SortStrings::getMapOfStrings(vector<string> strings, int n)
{
    map<char, map<string,string>> mapOfStrings;

    for(string word : strings)
        mapOfStrings[word.at(n)][word] = word;

    return mapOfStrings;
}

// 정렬된 map이 반환하는 결과를 얻어서 vector<string>으로 만들어서 반환시킨다.
vector<string> SortStrings::getResultOfMap(map<char, map<string,string>> mapOfStrings)
{
    vector<string> result;

    for(auto mapOfString : mapOfStrings)
        for(auto word : mapOfString.second)
            result.push_back(word.second);

    return result;
}

void printVector(vector<string> vec)
{
    cout << "[";
    for(string str : vec)
    {
        cout << str << ", ";
    }
    cout << "]";
}

void test(vector<string> para1, int para2, vector<string> result)
{
    static int caseNum = 0;
    caseNum++ ;

    cout << "Case " + to_string(caseNum) + " : ("; printVector(para1); cout << ", " << to_string(para2) << ") -> "; printVector(result); 
    cout << " / "; printVector(SortStrings(para1, para2).getResult()); cout << " : ";
    cout << ((result == SortStrings(para1, para2).getResult()) ? "TRUE" : "FALSE") << endl;
}

int main ()
{
    test(vector<string>({"sun", "bed", "car"}), 1, vector<string>({"car", "bed", "sun"}));
    test(vector<string>({"abce", "abcd", "cdx"}), 2, vector<string>({"abcd", "abce", "cdx"}));
}