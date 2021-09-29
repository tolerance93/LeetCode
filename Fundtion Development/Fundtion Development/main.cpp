#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remains(progresses.size(), 0);
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        if (remain % speeds[i] == 0)
        {
            remains[i] = remain / speeds[i];
        }
        else
        {
            remains[i] = (remain / speeds[i]) + 1;
        }
    }
    
    answer.push_back(0);
    for (int i = 1; i < remains.size(); i++)
    {
        int lastIndex = answer[answer.size() - 1];
        if (remains[lastIndex] < remains[i])
        {
            answer.push_back(i);
            lastIndex = i;
        }
    }
    
    for (int i = 0; i < answer.size() - 1; i++)
    {
        answer[i] = answer[i + 1] - answer[i];
    }
    answer[answer.size() - 1] = remains.size() - answer[answer.size() - 1];
    
    return answer;
}

int main()
{
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = {1, 1, 1, 1, 1, 1};
    solution(progresses, speeds);
    return 0;
}
