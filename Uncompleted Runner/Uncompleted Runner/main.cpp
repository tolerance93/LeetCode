#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    for (auto& name : completion)
    {
        if (map.find(name) == map.end())
        {
            map[name] = 1;
        }
        else
        {
            map[name]++;
        }
    }
    
    for (auto& name : participant)
    {
        if (map.find(name) == map.end())
        {
            return name;
        }
        else
        {
            map[name]--;
            if (map[name] == 0)
            {
                map.erase(name);
            }
        }
    }
    return "";
}

int main()
{
    vector<string> parti = {"leo", "kiki", "eden"};
    vector<string> comp = {"eden", "kiki"};
    solution(parti, comp);
    return 0;
}
