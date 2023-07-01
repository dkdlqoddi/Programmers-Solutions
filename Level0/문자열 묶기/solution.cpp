#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> strArr) {
    unordered_map<int,int> ht;
    int size;
    for (auto s: strArr)
    {
        size = s.size();
        if (ht.find(size) == ht.end())
        {
            ht[size] = 1;
        }
        else
        {
            ht[size] += 1;
        }
    }
    
    int m = 0;
    for (auto h: ht)
    {
        if (m < h.second)
        {
            m = h.second;
        }
    }
    return m;
}