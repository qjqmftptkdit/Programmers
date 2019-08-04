#include <vector>
#include <iostream>

using namespace std;

class NoDropPrice
{
    private:
        vector<int> prices; // 초당 가격이 담긴 배열
    
    public:
        NoDropPrice(vector<int> prices); // 생성자
        vector<int> getResult(); // 각 시기에 대해 가격이 떨어지지 않은 기간을 반환

    private:
        int getOneResult(vector<int> prices, int index); // 단일 값에 대하여 계산한다.
};

// 생성자
NoDropPrice::NoDropPrice(vector<int> prices) : \
    prices(prices) {}

// 각 시기에 대해 가격이 떨어지지 않은 기간을 반환
vector<int> NoDropPrice::getResult()
{
    vector<int> result; // 결과 저장
    
    for(vector<int>::size_type i=0; i<prices.size(); i++)
        result.push_back(getOneResult(prices, i));

    return result;
}

// 단일 값에 대하여 계산한다.
int NoDropPrice::getOneResult(vector<int> prices, int index)
{
    if(index == prices.size()-1) return 0;

    int result = 0;
    for(vector<int>::size_type i=index+1; i<prices.size(); i++)
    {
        result++;
        if(prices[index]>prices[i]) break;
    }
    return result;
}

int printVec(vector<int> vec)
{
    cout << "[";
    for(int i : vec)
        cout << i << ", ";
    cout << "]";
}

int test()
{
    cout << "Case 1 : ([1,2,3,2,3]) -> [4,3,1,1,0] / " ;
    printVec(NoDropPrice(vector<int>({1,2,3,2,3})).getResult());
    cout << " / " << ((NoDropPrice(vector<int>({1,2,3,2,3})).getResult() == vector<int>({4,3,1,1,0})) ? "TRUE" : "FALSE");
}

int main ()
{
    test();
}