#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;
inline int minutes(string t) {
    return (600 * (t[0] - '0')) + (60 * (t[1] - '0')) + (10 * (t[3] - '0')) + (t[4] - '0');
}
bool compare(const pair<int,int> a, const pair<int,int> b) {
    return a.first < b.first;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int,int> rec;
    unordered_map<int,int> fee;
    vector<pair<int,int>> result;
    stringstream ss;
    string temp;
    int min, id;
    for (auto line : records) {
        ss.clear();
        ss.str(line);
        getline(ss, temp, ' ');
        min = minutes(temp);
        ss >> id;
        getline(ss, temp, ' ');
        getline(ss, temp, ' ');
        switch (temp[0]) {
            case 'I':
                rec[id] = min;
                break;
            case 'O':
                if (fee.find(id) == fee.end())
                    fee[id] = min - rec[id];
                else
                    fee[id] += min - rec[id];
                rec.erase(id);
                break;
        }
        // printf("%d %d\n", min, id);
    }
    for (auto val: rec) {
        if (fee.find(val.first) == fee.end())
            fee[val.first] = 1439 - val.second;
        else
            fee[val.first] += 1439 - val.second;
    }
    for (auto val: fee) {
        if (val.second < fees[0])
            result.push_back(make_pair(val.first, fees[1]));
        else
            result.push_back(make_pair(val.first, fees[1] + (((val.second - fees[0] + fees[2] - 1) / fees[2]) * fees[3])));
    }
    sort(result.begin(), result.end(), compare);
    for (auto val: result)
        answer.push_back(val.second);
    return answer;
}