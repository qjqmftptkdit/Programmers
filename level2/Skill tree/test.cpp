#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CheckSkillTree 
{
    private :
    string skillPrior; // Skill Prior list to follow
    vector<string> skill_trees; // Given skill trees

    public :
    CheckSkillTree(string skillPrior, vector<string> skill_trees); // Constructor
    int getNumOfAvailiableSkillTree(); // Get num of available skill tree

    private :
    bool isExistsInList(char skill, string skillPrior); // Check if given skill exists in the skill prior list
};

// Constructor
CheckSkillTree::CheckSkillTree(string skillPrior, vector<string> skill_trees) : \
    skillPrior(skillPrior), skill_trees(skill_trees) {}

// Get num of available skill tree
int CheckSkillTree::getNumOfAvailiableSkillTree()
{
    int result = 0; 

    for(string skill_tree : skill_trees)
    {
        bool isCorrect = true;
        int checkIndex = 0; 
        for(char skill : skill_tree)
            if(isExistsInList(skill, skillPrior))
                if(skill == skillPrior[checkIndex])
                {
                    checkIndex++;
                }
                else
                {
                    isCorrect = false;
                    break;
                }   
        if(isCorrect)
            result++;
    }

    return result;
}

// Check if given skill exists in the skill prior list
bool CheckSkillTree::isExistsInList(char skill, string skillPrior)
{
    for(char skillP : skillPrior)
        if(skill == skillP)
            return true;
    return false;
}

void printSkillTrees(vector<string> skill_trees)
{
    cout << "[";
    for(string skill : skill_trees)
    {
        cout << skill <<", ";
    }
    cout << "]";
}

void test(string skillPrior, vector<string> skill_trees, int result)
{
    int caseNum = 0;
    caseNum++;

    cout << "Case " << caseNum << " : (" << skillPrior << "," ; printSkillTrees(skill_trees) ; cout << ") -> " << result;
    cout << " : " << CheckSkillTree(skillPrior, skill_trees).getNumOfAvailiableSkillTree() ;
    cout << " : " << ((CheckSkillTree(skillPrior, skill_trees).getNumOfAvailiableSkillTree() == result) ? "TRUE" : "FALSE") << endl;
}

int main ()
{
    test("CBD", vector<string>({"BACDE", "CBADF", "AECB", "BDA"}), 2);
    return 0;
}