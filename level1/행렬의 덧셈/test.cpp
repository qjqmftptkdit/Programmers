#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    private :
    vector<vector<int>> matrix_val;

    public :
    Matrix(vector<vector<int>> matrix_val) : matrix_val(matrix_val) {}
    vector<vector<int>> operator+ (const Matrix& matrix);
};

vector<vector<int>> Matrix::operator+ (const Matrix& matrix)
{
    const int ROW = matrix_val.size();
    const int COL = matrix_val[0].size();

    vector<vector<int>> result(ROW, vector<int>(COL,0));
    
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            result[i][j] = matrix_val[i][j] + matrix.matrix_val[i][j];

    return result;
}

int main ()
{
    vector<vector<int>> num1 = {{1},{2}};
    vector<vector<int>> num2 = {{3},{4}};
    vector<vector<int>> result = Matrix(num1)  + Matrix(num2);

    for(auto i : result)
    {
        for(auto j : i)
        {
            cout << j;
        }
    }
}