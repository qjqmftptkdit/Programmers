#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

void printVector(vector<int> vec);

class KNumber
{
    private :
    vector<int> array; // 대상이 되는 베열
    vector<vector<int>> commands; // [i,j,k] 가 저장된 배열

    public :
    KNumber(vector<int> array, vector<vector<int>> commands);
    vector<int> getKNumber(); // k번째 수를 구한다.

    private :
    void parseCommand(vector<int> command, int &i, int &j, int &k); // 단일 command를 i,j,k에 대응시킨다.
    vector<int> cutArray(int i, int j, vector<int> command); // i~j번째까지 자른다.
    void sortCommand(vector<int> &command); // 백터를 정렬시킨다.
};

KNumber::KNumber(vector<int> array, vector<vector<int>> commands) \
    : array(array), commands(commands) {}

vector<int> KNumber::getKNumber()
{
    vector<int> answer;
    for(vector<int> command : commands)
    {
        int i,j,k;
        parseCommand(command,i,j,k);
        vector<int> targetArray = cutArray(i, j, array);
        sortCommand(targetArray);
        answer.push_back(targetArray.at(k-1));
    }
    return answer;
}

void KNumber::parseCommand(vector<int> command, int &i, int &j, int &k)
{
    i = command.at(0); j = command.at(1); k = command.at(2);
}

vector<int> KNumber::cutArray(int i, int j, vector<int> command)
{
    vector<int> targetArray;
    for(vector<int>::size_type t=i-1; t<j; t++)
        targetArray.push_back(command.at(t));
    return targetArray;
}

void KNumber::sortCommand(vector<int> &command)
{
    sort(command.begin(), command.end() );
}

void printVector(vector<int> vec)
{
    cout << "[";
    for(int i : vec)
        cout << i << " ";
    cout << "]";
}

int main()
{
    vector<int> answer = KNumber(vector<int>({1,5,2,6,3,7,4}), vector<vector<int>>({{2,5,3},{4,4,1},{1,7,3}})).getKNumber();
    cout << "Case 1 : ([1,5,2,6,3,7,4],[[2,5,3],[4,4,1],[1,7,3]) -> [5,6,3] / "; printVector(answer); cout << "/" << (answer == vector<int>({5,6,3}));
}