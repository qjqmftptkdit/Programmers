#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class getHIndex {
    private :
    vector<int> citations;
    int LenOfCitation;

    public :
    getHIndex(vector<int> citations); // Constructor
    int getResult(); // get H-Index for given citations

    private :
    vector<int> sortCitations(vector<int> citations); // Sort citations in descending
};

// Constructor
getHIndex::getHIndex(vector<int> citations) : citations(citations) \
{LenOfCitation = citations.size();}

// get H-Index for given citations
int getHIndex::getResult()
{
    vector<int> sortedCitations = sortCitations(citations);
    int hIndex = 0; // Initial hindex
    
    // Compute H-index
    for(int cindex; cindex<LenOfCitation; cindex++)
    {
        if((sortedCitations[cindex] <= (cindex+1)) && (LenOfCitation - (cindex+1)) <= sortedCitations[cindex])
        {
            hIndex = cindex;
            break;
        }
    }

    return hIndex;
}

// Sort citations in descending
vector<int> getHIndex::sortCitations(vector<int> citations)
{
    sort(citations.rbegin(), citations.rend());
    return citations;
}

// Print vector to show
void printVector(vector<int> citations)
{
    cout << "[" ;
    for (int citation : citations)
        cout << citation << ", ";
    cout << "]" ;
}

// Simple function for testing
void test(vector<int> citations, int result)
{
    static int caseNum = 0;
    caseNum++;

    cout << "case " << caseNum << " : " ; printVector(citations); cout << " -> " << result << " : ";
    cout << getHIndex(citations).getResult() << " : " << ((getHIndex(citations).getResult() == result) ? "TRUE" : "FALSE") << endl;
}

int main ()
{
    test(vector<int>({3, 0, 6, 1, 5}), 3);
}