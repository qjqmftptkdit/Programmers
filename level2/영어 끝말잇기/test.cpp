#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class EndToEnd
{
    private :
        int numOfPerson; // 참여하는 사람의 수
        vector<string> words; // 참여한 사람들이 말한 단어 리스트

    public :
        EndToEnd(int numOfPerson, vector<string> words); // 생성자
        vector<int> getResult(); // 탈락한 사람의 번호, 몇번째 차례에 탈락했는지 반환
        
    private :
        bool isRightWord(string word1, string word2); // word1단어 다음에 word2단어를 말하는 것이 옳으면 true, 아니면 false.
        bool isDupWord(vector<string> words, string word, int wordIndex);  // wodIndex에 위차한 word가 words에 있어서, wordIndex이전에 동일한 단어가 있으면 true, 아니면 false
};

// 생성자
EndToEnd::EndToEnd(int numOfPerson, vector<string> words) : \
    numOfPerson(numOfPerson), words(words) {}

// 탈락한 사람의 번호, 몇번째 차례에 탈락했는지 반환
vector<int> EndToEnd::getResult()
{
    int failNum = 0; // 탈락한 차례

    for(vector<string>::size_type i=1; i<words.size(); i++)
    {
        if(!isRightWord(words[i-1], words[i]) || isDupWord(words, words[i], i)) 
        {
            failNum = i;
            break;
        }
    }
    return (failNum == 0) ? vector<int>({0,0}) : vector<int>({failNum%numOfPerson+1, failNum/numOfPerson+1});
} 

// word1단어 다음에 word2단어를 말하는 것이 옳으면 true, 아니면 false.
bool EndToEnd::isRightWord(string word1, string word2)
{
    return (word1.back() == word2[0]);
}

// wodIndex에 위차한 word가 words에 있어서, wordIndex이전에 동일한 단어가 있으면 true, 아니면 false
bool EndToEnd::isDupWord(vector<string> words, string word, int wordIndex)
{
    for(vector<string>::size_type i=0; i<wordIndex; i++)
    {
        if(words[i] == word) return true;
    }
    return false;
}  

// vector을 출력시킨다.
void printVector(vector<int> vec)
{
    cout << "(";
    for(int i : vec)
        cout << i << ",";
    cout << ")";
} 

// 검증을 위한 함수
void test()
{
    cout << "Case 1 : (3,[tank, kick, know, wheel, land, dream, mother, robot, tank]) -> (3,3) / ";
    printVector(EndToEnd(3, vector<string>({"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"})).getResult());
    cout << " / " << ((EndToEnd(3, vector<string>({"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"})).getResult() == vector<int>({3,3})) ? "TRUE" : "FALSE");
    cout << endl;

    cout << "Case 2 : (5,[hello, observe, effect, take, either, recognize, encourage, ensure, establish, hang, gather, refer, reference, estimate, executive]) -> (0,0) / ";
    printVector(EndToEnd(5, vector<string>({"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"})).getResult());
    cout << " / " << ((EndToEnd(5, vector<string>({"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"})).getResult() == vector<int>({0,0})) ? "TRUE" : "FALSE");
    cout << endl;

    cout << "Case 3 : (2,[hello, one, even, never, now, world, draw]) -> (1,3) / ";
    printVector(EndToEnd(2, vector<string>({"hello", "one", "even", "never", "now", "world", "draw"})).getResult());
    cout << " / " << ((EndToEnd(2, vector<string>({"hello", "one", "even", "never", "now", "world", "draw"})).getResult() == vector<int>({1,3})) ? "TRUE" : "FALSE");
    cout << endl;
}

int main()
{
    test();
}
