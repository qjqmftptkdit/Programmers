#include <vector>
#include <algorithm>
#include <iostream>

using namespace std ;

class Budget
{
    private :
    vector<int> department; // 각 부서별로 필요한 예산이 들어간 배열
    int budget; // 주어진 예산

    public :
    Budget(vector<int> department, int budget);
    int getMaxDepartment(); // 지원가능한 최대의 부서를 구한다.

    private :
    void sortDepartment(); // 주어진 예산을 오름차순으로 정렬시킨다.
};

Budget::Budget(vector<int> department, int budget) : \
department(department), budget(budget) {}

int Budget::getMaxDepartment()
{
    sortDepartment(); // 부서를 정렬시킨다.

    int currentBudget = 0;
    for(vector<int>::size_type i = 0; i<department.size(); i++)
    {
        if((currentBudget + department[i])<=budget)
            currentBudget += department[i];
        else
            return i;
    }
    return department.size();
}

void Budget::sortDepartment()
{
    sort(department.begin(), department.end());
}

int main ()
{
    // 검증
    cout << "Case 1 : ([1,3,2,5,4],9) -> 3 / " << Budget(vector<int>({1,3,2,5,4}),9).getMaxDepartment() << " : " << (Budget(vector<int>({1,3,2,5,4}),9).getMaxDepartment() == 3) << endl;
    cout << "Case 2 : ([2,2,3,3],10) -> 4 / " << Budget(vector<int>({2,2,3,3}),10).getMaxDepartment() << " : " << (Budget(vector<int>({2,2,3,3}),10).getMaxDepartment() == 4) << endl;
    cout << "Case 3 : ([1,2,2,3,4,6,7],8) -> 4 / " << Budget(vector<int>({1,2,2,3,4,6,7}),8).getMaxDepartment() << " : " << (Budget(vector<int>({1,2,2,3,4,6,7}),8).getMaxDepartment() == 4) << endl;
}