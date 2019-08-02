#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void DebugVector(vector<int> vec);

class Progress
{
    private :
        vector<int> progresses; // 프로그램의 진행정도 및 우선순위
        vector<int> speeds; // 하루당 진행할 수 있는 정도

    public :
        Progress(vector<int> progresses, vector<int> speeds);
        vector<int> getDistribute(); // 몇개의 기능이 배포되는지 반환시킨다.

    private :
        int getCompleteDay(int progress, int speed); // 완수한 날짜를 반환시킨다.
};


Progress::Progress(vector<int> progresses, vector<int> speeds) : \
progresses(progresses), speeds(speeds) {}

// 몇개의 기능이 배포되는지 반환시킨다.
vector<int> Progress::getDistribute()
{
    vector<int> completeDays; // 일이 완수되는 날짜
    vector<bool> progressCheck(progresses.size(),false); // 해당 인덱스의 일이 반환되었는지 여부를 나타낸다.
    vector<int> answer; // 반환되는 값

    // competeDays 채우기
    for(vector<int>::size_type i=0; i<progresses.size(); i++)
    {
        completeDays.push_back(getCompleteDay(progresses[i], speeds[i]));
    }

    // progressCheck가 모두 true가 될때까지 반복한다.
    while(true)
    {
        // 맨 앞에 있는 false를 찾는다.
        vector<bool>::iterator falseIt = std::find(progressCheck.begin(), progressCheck.end(), false);

        // false가 발견되지 않음
        if(falseIt == progressCheck.end())
             break;
        // false가 발견됨
        int falseIndex = std::distance(progressCheck.begin(), falseIt); // false의 완전한 인덱스를 구한다.
        progressCheck[falseIndex] = true; // 해당 값을 true로 바꾼다.

        // false가 발견된 부분부터 마지막 인덱스까지 그 날의 day이하인 것을 true로 만들어서 포함시킨다.
        int distNum = 1;
        int findIndex = falseIndex+1;
        while(findIndex < progressCheck.size())
        {
            // 동시에 완수되는 일
            if(completeDays[falseIndex] >= completeDays[findIndex] && progressCheck[findIndex] == false)
            {
                progressCheck[findIndex] = true; // 동시에 완수되는 일을 true로 바꾼다.
                distNum++;
                findIndex++;
            }
            else 
                break;
        }
        answer.push_back(distNum);
    }

    return answer;
}

// 완수한 날짜를 반환시킨다.
int Progress::getCompleteDay(int progress, int speed)
{
    int day=0;
    while(progress<100)
    {
        progress+=speed;
        day++;
    }
    return day;
}

int main(void)
{
    DebugVector(Progress(vector<int>({15, 1, 14, 9, 29, 25, 17, 24, 4, 27, 7, 19, 29, 14, 23, 4, 21, 3, 8, 14}), vector<int>({9, 11, 21, 16, 11, 21, 7, 5, 6, 30, 11, 24, 26, 18, 20, 18, 15, 30, 7, 18})).getDistribute());
}

void DebugVector(vector<int> vec)
{
    for(int result : vec)
    {
        std::cout << result << " ";
    }
    std::cout << "----- END -----" << std::endl;
}