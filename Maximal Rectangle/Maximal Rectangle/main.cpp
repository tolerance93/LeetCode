#include <iostream>
#include <vector>
/**
 * init project
 */
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int nRow = matrix.size();
        if (nRow == 0) return 0;
        int nCol = matrix[0].size();
        int res = 0;
        
        Rec dp[nRow][nCol];
        
        res = dp[0][0].width = dp[0][0].height = matrix[0][0] - '0';
        
        for (int i = 1; i < nCol; i++)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i].height = 1;
                dp[0][i].width = dp[0][i - 1].width + 1;
                res = dp[0][i].getArea() > res ? dp[0][i].getArea() : res;
            }
            else
            {
                dp[0][i].height = 0;
                dp[0][i].width = 0;
            }
        }
        
        for (int i = 1; i < nRow; i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0].width = 1;
                dp[i][0].height = dp[i - 1][0].width + 1;
                res = dp[i][0].getArea() > res ? dp[i][0].getArea() : res;
            }
            else
            {
                dp[i][0].height = 0;
                dp[i][0].width = 0;
            }
        }
        
        for (int i = 1; i < nRow; i++)
        {
            for (int j = 1; j < nCol; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (matrix[i - 1][j] == '0' && matrix[i][j - 1] == '0')
                    {
                        dp[i][j].width = dp[i][j].height = 1;
                    }
                    else if (matrix[i][j - 1] == '0')
                    {
                        dp[i][j].width = 1;
                        dp[i][j].height = dp[i - 1][j].height + 1;
                    }
                    else if (matrix[i - 1][j] == '0')
                    {
                        dp[i][j].height = 1;
                        dp[i][j].width = dp[i][j - 1].width + 1;
                    }
                    else if (matrix[i - 1][j - 1] == '0')
                    {
                        if (dp[i - 1][j].height > dp[i][j - 1].width)
                        {
                            dp[i][j].height = dp[i - 1][j].height + 1;
                            dp[i][j].width = 1;
                        }
                        else
                        {
                            dp[i][j].height = 1;
                            dp[i][j].width = dp[i][j - 1].width + 1;
                        }
                    }
                    else
                    {
                        dp[i][j].height = min(min(dp[i - 1][j - 1].height, dp[i - 1][j].height), dp[i][j - 1].height) + 1;
                        dp[i][j].width = min(min(dp[i - 1][j - 1].width, dp[i - 1][j].width), dp[i][j - 1].width) + 1;
                    }
                    res = dp[i][j].getArea() > res ? dp[i][j].getArea() : res;
                }
                else
                {
                    dp[i][j].width = dp[i][j].height = 0;
                }
            }
        }
        return res;
    }
private:
    struct Rec
    {
        int width;
        int height;
        
        Rec(){}
        Rec(int width, int height) : width(width), height(height) {}
        
        int getArea()
        {
            return width * height;
        }
    };
};

int main()
{
    return 0;
}
