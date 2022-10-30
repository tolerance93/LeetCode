/**
 * Runtime: 10 ms, faster than 67.45% of C++ online submissions for Maximum Non Negative Product in a Matrix.
 * Memory Usage: 10.5 MB, less than 20.53% of C++ online submissions for Maximum Non Negative Product in a Matrix.
 */

#include <vector>
#define MODULO 1000000007
using namespace std;

class Solution {
public:
    
    bool isPositive(long long num)
    {
        if (num >= 0) return true;
        return false;
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<long long>> negMat(rows, vector<long long> (cols, 0));
        vector<vector<long long>> posMat(rows, vector<long long> (cols, 0));
        //long long으로 선언하면 모듈로 연산 마지막에만 하면 됨!
        long long product = grid[0][0];
        
        //예외: 인풋이 하나의 원소로 이루어진 matrix
        if (rows == 1 && cols == 1)
        {
            if (product >= 0) return product;
            else return -1;
        }
        
        //길이 한 개인 맨 왼쪽 초기화
        for (int row = 1; row < rows; row++)
        {
            product = product * grid[row][0];
            if (isPositive(product))
            {
                posMat[row][0] = product;
            }
            else
            {
                negMat[row][0] = product;
            }
        }
        //길이 한 개인 맨 위쪽 초기화
        product = grid[0][0];
        for (int col = 1; col < cols; col++)
        {
            product = product * grid[0][col];
            if (isPositive(product))
            {
                posMat[0][col] = product;
            }
            else
            {
                negMat[0][col] = product;
            }
        }
        //길이 두개인 나머지 부분
        for (int row = 1; row < rows; row++)
        {
            for (int col = 1; col < cols; col++)
            {
                long long negDownProduct = negMat[row - 1][col] * grid[row][col];
                long long posDownProduct = posMat[row - 1][col] * grid[row][col];
                long long negleftProduct = negMat[row][col - 1] * grid[row][col];
                long long posLeftProduct = posMat[row][col - 1] * grid[row][col];
                if (isPositive(grid[row][col]))
                {
                    posMat[row][col] = max(posDownProduct, posLeftProduct);
                    negMat[row][col] = min(negDownProduct, negleftProduct);
                }
                else
                {
                    posMat[row][col] = max(negDownProduct, negleftProduct);
                    negMat[row][col] = min(posDownProduct, posLeftProduct);
                }
            }
        }
        //예외: 곱이 0일때
        long long res = posMat[rows - 1][cols - 1];
        if (res == 0)
        {
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    if (grid[row][col] == 0) return 0;
                }
            }
            return -1;
        }
        return res % MODULO;
    }
};


int main()
{
    vector<vector<int>> input;
    input.push_back({-1, -2, -3});
    input.push_back({-2, -3, -3});
    input.push_back({-3, -3, -2});
    Solution sol;
    sol.maxProductPath(input);
    return 0;
}
