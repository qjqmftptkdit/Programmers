#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std; 

class Marathon
{
    private :
    vector<string> participant; // 참여한 사람들
    vector<string> completion; // 완주한 사람들

    public :
    Marathon(vector<string> participant, vector<string> completion); // 생성자
    string getResult(); // 완주하지 못한 사람을 반환한다.

    private :
    map<string, int> getCompletionMap(vector<string> completion); // completion를 Key-Value쌍으로 만들어서 반환한다.
    string checkParticipantWithMap(vector<string> participant, map<string, int> completionMap); // participant과 map을 비교해서, map이 없는 대상을 반환한다.
};

// 생성자
Marathon::Marathon(vector<string> participant, vector<string> completion) \
    : participant(participant), completion(completion) {}

// 완주하지 못한 사람을 반환한다.
string Marathon::getResult()
{
    map<string, int> completionMap = getCompletionMap(completion);
    return checkParticipantWithMap(participant, completionMap);
}

// completion를 Key-Value쌍으로 만들어서 반환한다.
map<string, int> Marathon::getCompletionMap(vector<string> completion)
{
    map<string, int> completionMap;
    for(string part : completion)
    {
        if(completionMap[part]) completionMap[part]+=1; // 값이 이미 존재할 경우 (동명이인)
        else completionMap[part]=1; // 값이 없을 경우
    }
    return completionMap;
}

// participant과 map을 비교해서, map이 없는 대상을 반환한다.
string Marathon::checkParticipantWithMap(vector<string> participant, map<string, int> completionMap)
{
    for(string part : participant)
        if(completionMap[part]!=0) 
            completionMap[part]-=1;
        else 
            return part;
}

void printVector(vector<string> vec)
{
    cout << "[";
    for(string i : vec)
    {
        cout << i << ", ";
    }
    cout << "]";
}

void test(vector<string> para1, vector<string> para2, string result)
{
    static int caseNum = 0;
    caseNum++;

    cout << "Case " << caseNum << " : (" ; printVector(para1); 
    cout << ", "; printVector(para2); cout << ") -> " << result << " / ";
    cout << Marathon(para1, para2).getResult() << " : ";
    cout << ((Marathon(para1, para2).getResult() == result) ? "TRUE" : "FALSE") << endl;
}

int main()
{
    test(vector<string>({"leo", "kiki", "eden"}), vector<string>({"eden", "kiki"}), "leo");
    test(vector<string>({"marina", "josipa", "nikola", "vinko", "filipa"}), vector<string>({"josipa", "filipa", "marina", "nikola"}), "vinko");
    test(vector<string>({"mislav", "stanko", "mislav", "ana"}), vector<string>({"stanko", "ana", "mislav"}), "mislav");
}