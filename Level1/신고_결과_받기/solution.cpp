#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int id_cnt = id_list.size();
    unordered_map<string, set<string>> from_hash_table;
    unordered_map<string, set<string>> to_hash_table;
    for (auto id: id_list) {
        from_hash_table.insert(make_pair(id,  set<string>()));
        to_hash_table.insert(make_pair(id,  set<string>()));
    }
    
    for (auto line: report) {
        auto space = line.find(' ');
        auto id1 = line.substr(0, space);
        auto id2 = line.substr(space + 1, line.size());
        from_hash_table[id1].insert(id2);
        to_hash_table[id2].insert(id1);
    }
    
    for (auto id: id_list) {
        int cnt = 0;
        for (auto reported: from_hash_table[id]) {
            if (to_hash_table[reported].size() >= k)
                cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}