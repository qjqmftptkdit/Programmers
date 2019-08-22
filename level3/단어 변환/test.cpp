#include <vector>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


// 그래프에서 사용하기 위한 Node 클래스
class Node
{
    private :
    string word; // 단어를 저장한다.
    Node* next; // 다음 노드를 연결한다.

    public :
    Node(string word, Node* next); // 노드 초기화
    string getWord(); // 저장된 단어를 얻는다.
    Node* getNextptr(); // 저장된 포인터를 얻는다.
    void setNextptr(Node* nextPtr); // 포인터를 설정한다.
};

Node::Node(string word, Node* next) : word(word), next(next) {}

string Node::getWord() {return word;} // 저장된 단어를 얻는다.
Node* Node::getNextptr(){return next;} // 저장된 포인터를 얻는다.
void Node::setNextptr(Node* nextPtr) {next=nextPtr;} // 포인터를 설정한다.


// 그래프 클래스
class Graph
{
    private :
    vector<Node> nodes; // 노드 배열을 저장한다.
    map<string, bool> visited; // 방문여부 확인 (DFS)
    int totalNum; // 총 갯수를 저장한다.

    public :
    Graph(string begin, vector<string> words); // 각 begin과 words에 대한 그래프노드를 생성해서 초기화시킨다.
    int getTotalNum(); // 이 그래프 노드의 총 갯수를 반환한다.
    vector<Node> getNodes(); // Node 배열을 반환한다.
    Node getNode(string target); // target을 word로 가진 node를 반환한다.
    void setVisited(string target); // target을 True로 변경시킨다. 
    bool getVisited(string target); // target의 True/False 여부를 반환시킨다.

    private :
    // 처음으로 노드를 초기화 시킨다.
    vector<Node> initNodes(string begin, vector<string> words);
    // 해당 단어와 다른 target단어가 관계를 가지고 있는지 확인한다.
    // 관계를 가지고 있음 : true, 관계가 없음 : false
    bool isProper(string word, string target);
    // nodes에 속한 target문자열을 가진 특정 node에 word가진 노드를 생성하여 연결시킨다.
    void insertNode(Node& target, string word);

    // visited를 초기화 시킨다.
    map<string, bool> initVisited(string begin, vector<string> words);
};

// 각 begin과 words에 대한 그래프노드를 생성해서 초기화시킨다.
Graph::Graph(string begin, vector<string> words)
{
    // 초기화
    totalNum = words.size()+1;
    nodes = initNodes(begin, words);
    visited = initVisited(begin, words);
    
    // 연결
    for(Node& node : nodes)
        for(Node node_ : nodes)
            if(isProper(node.getWord(), node_.getWord()))
                insertNode(node, node_.getWord());
}

int Graph::getTotalNum(){return totalNum;}  // 이 그래프 노드의 총 갯수를 반환한다.
vector<Node> Graph::getNodes(){return nodes;} // Node 배열을 반환한다.
void Graph::setVisited(string target){visited[target] = true;} // target을 True로 변경시킨다. 
bool Graph::getVisited(string target){return visited[target];} // target의 True/False 여부를 반환시킨다.
Node Graph::getNode(string target) // target을 word로 가진 node를 반환한다.
{
    for(Node node : nodes)
    {
        if(target == node.getWord()) return node;
    }
}

// 처음으로 노드를 초기화 시킨다.
vector<Node> Graph::initNodes(string begin, vector<string> words)
{
    vector<Node> nodes;
    nodes.push_back(Node(begin, nullptr));
    for(string word : words)
        nodes.push_back(Node(word, nullptr));
    return nodes;
}

// 해당 단어와 다른 target단어가 관계를 가지고 있는지 확인한다.
bool Graph::isProper(string word, string target)
{
    int checkNum = 0;
    int len = word.length();
    
    for(int i=0; i<len; i++)
        if(word[i] != target[i]) checkNum++;

    return (checkNum == 1) ;
}

// nodes에 속한 target문자열을 가진 특정 node에 word가진 노드를 생성하여 연결시킨다.
void Graph::insertNode(Node& target, string word)
{
    Node* Node_new = new Node(word, target.getNextptr());
    target.setNextptr(Node_new);
}

// visited를 초기화 시킨다.
map<string, bool> Graph::initVisited(string begin, vector<string> words)
{
    map<string, bool> visited;
    visited[begin] = false;
    
    for(string word : words)
        visited[word] = false;

    return visited;
}

class WordTransition
{
    private :
    string begin; // 시작할때의 단어
    string target; // 목표 단어
    vector<string> words; // 변환 가능한 단어 리스트

    public :
    WordTransition(string begin, string target, vector<string> words);
    int getResult(); // 최소 변환 횟수를 반환한다.

    private :
    // words안에 target이 있어서 변환이 가능한지 확인한다.
    // 변환이 가능 : true, 변환이 불가능 : false 
    bool isAvailable(string target, vector<string> words);
    // 해당 노드와 연결된 노드들이 모두 방문되었는지에 대한 여부를 반환한다.
    bool isHaveUnvisitedNode(Node* node_next, Graph graph);
    // 해당 타겟단어에 도달하기 위한 최소 횟수를 DFS를 통해서 알아낸다.
    int startDfsForTarget(string begin, string target, vector<string> words);
};

WordTransition::WordTransition(string begin, string target, vector<string> words) : \
    begin(begin), target(target), words(words) {}

// 최소 변환 횟수를 반환한다.
int WordTransition::getResult()
{
    if(!isAvailable(target, words))
        return 0;
    return startDfsForTarget(begin, target, words);
}

// 변환이 가능 : true, 변환이 불가능 : false 
bool WordTransition::isAvailable(string target, vector<string> words)
{
    return (find(words.begin(), words.end(), target) != words.end());
}

// 해당 타겟단어에 도달하기 위한 최소 횟수를 DFS를 통해서 알아낸다.
int WordTransition::startDfsForTarget(string begin, string target, vector<string> words)
{
    Graph graph = Graph(begin, words);
    stack<string> stack;

    stack.push(begin);
    graph.setVisited(begin);

    while(!stack.empty())
    {
        string word = stack.top();
        stack.pop();
        Node node = graph.getNode(word);
        Node* node_next = node.getNextptr();
        if(isHaveUnvisitedNode(node_next, graph))
            stack.push(word);

        while(node_next)
        {
            if(!graph.getVisited(node_next->getWord()))
            {
                if(stack.empty()) stack.push(word);
                stack.push(node_next->getWord());
                graph.setVisited(node_next->getWord());
                if(target == node_next->getWord()) return stack.size()-1;
                node_next = graph.getNode(node_next->getWord()).getNextptr();
            }
            else
            {
                node_next = node_next->getNextptr();
            }
        }
    }

    return 0;
}

// 해당 노드와 연결된 노드들이 모두 방문되었는지에 대한 여부를 반환한다.
bool WordTransition::isHaveUnvisitedNode(Node* node_next, Graph graph)
{
    Node* node = node_next;;

    while(node)
    {
        if(!graph.getVisited(node->getWord())) return true;
        else node = node->getNextptr();
    }
    return false;
}

void printVector(vector<string> words)
{
    cout << "[";
    for(string word : words)
    {
        cout << word << ", ";
    }
    cout << "]";
}

void test(string begin, string target, vector<string> words, int result)
{
    static int caseNum = 0;
    caseNum++;

    cout << "Case " << caseNum << " : (" << begin << ", " << target; printVector(words); cout << ") -> " << result;
    cout << " / " << WordTransition(begin, target, words).getResult() << " : ";
    cout << ((WordTransition(begin, target, words).getResult() == result) ? "TRUE" : "FALSE") << endl;
}

int main()
{
    test("hit", "hog",  vector<string>({"hot","hog","lot"}), 2);
    test("hit", "cog", vector<string>({"hot", "dot", "dog", "lot", "log", "cog"}), 4);
    test("hit", "cog", vector<string>({"hot", "dot", "dog", "lot", "log"}), 0);
}