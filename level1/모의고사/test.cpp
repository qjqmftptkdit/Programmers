#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MathSolve
{
    private :
        vector<int> answers; // 정답이 들어있는 배열

        vector<int> person1; // 첫번째 사람이 찍는 패턴
        vector<int> person2; // 두번째 사람이 찍는 패턴
        vector<int> person3; // 세번째 사람이 찍는 패턴

    public :
        MathSolve(vector<int> answers);
        vector<int> getPerson(); // 가장 많이 맞춘 사람은?

    private :
        bool isPerson1Correct(int number); // 해당 번호 문제를 첫번째 사람은 맞췄는가?
        bool isPerson2Correct(int number); // 해당 번호 문제를 두번째 사람은 맞췄는가?
        bool isPerson3Correct(int number); // 해당 번호 문제를 세번째 사람은 맞췄는가?

        int getMaxAnswers(vector<int> answers); // answers에서 얻어지는 최대값을 반환한다.
        vector<int> findIndexInSolveNum(int find, vector<int> solveNum); 
        // 특정 백터에서 해당 값이 발견되는 위치를 반환한다. 
        // 단, 여러개이면 오름차순으로 반환한다.
};

MathSolve::MathSolve(vector<int> answers) : \
    answers(answers) 
    {
        person1 = {1,2,3,4,5};
        person2 = {2,1,2,3,2,4,2,5};
        person3 = {3,3,1,1,2,2,4,4,5,5};
    }

// 가장 많이 맞춘 사람은?
vector<int> MathSolve::getPerson()
{
    vector<int> solveNum(3,0); // 맞춘 횟수가 들어있는 배열

    // 맞춘 횟수 계산
    for(vector<int>::size_type i=0; i<answers.size(); i++)
    {
        if(isPerson1Correct(i)) solveNum[0]++;
        if(isPerson2Correct(i)) solveNum[1]++;
        if(isPerson3Correct(i)) solveNum[2]++;
    }

    int maxSolveNum = getMaxAnswers(solveNum);
    return findIndexInSolveNum(maxSolveNum,solveNum);
}

// 해당 번호 문제를 첫번째 사람은 맞췄는가?
bool MathSolve::isPerson1Correct(int number)
{
    return (answers.at(number) == person1.at(number%person1.size()));
}

// 해당 번호 문제를 두번째 사람은 맞췄는가?
bool MathSolve::isPerson2Correct(int number)
{
    return (answers.at(number) == person2.at(number%person2.size()));
}

// 해당 번호 문제를 세번째 사람은 맞췄는가?
bool MathSolve::isPerson3Correct(int number)
{
    return (answers.at(number) == person3.at(number%person3.size()));
}

// answers에서 얻어지는 최대값을 반환한다.
int MathSolve::getMaxAnswers(vector<int> answers)
{
    return *max_element(answers.begin(), answers.end());
} 

// 특정 백터에서 해당 값이 발견되는 위치를 반환한다. 
// 단, 여러개이면 오름차순으로 반환한다
vector<int> MathSolve::findIndexInSolveNum(int find, vector<int> solveNum)
{
    vector<int> answer;
    for(vector<int>::size_type i=0; i<solveNum.size(); i++)
    {
        if(solveNum[i] == find) answer.push_back(i+1);
    }
    return answer;
}

void printVector(vector<int> vec)
{
    cout << "[";
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << "]";
}

void test()
{
    cout << "Case 1 : ([1,2,3,4,5]) -> [1] / "; printVector(MathSolve(vector<int>({1,2,3,4,5})).getPerson()); 
    cout << " : " << (MathSolve(vector<int>({1,2,3,4,5})).getPerson() == vector<int>({1}));
    cout << endl;

    cout << "Case 2 : ([1,3,2,4,2]) -> [1,2,3] / "; printVector(MathSolve(vector<int>({1,3,2,4,2})).getPerson()); 
    cout << " : " << (MathSolve(vector<int>({1,3,2,4,2})).getPerson() == vector<int>({1,2,3}));
    cout << endl;
}

int main ()
{
    test();
}