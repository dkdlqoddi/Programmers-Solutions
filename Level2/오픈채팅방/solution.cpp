#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string op;
    string id;
    string name;
    size_t pos;
    size_t it;
    unordered_map<string, string> hash_table;
    string enter = "Enter";
    string leave = "Leave";
    string change = "Change";
    vector<pair<string,string>> result;
    for (auto i: record) {
        pos = 0;
        it = i.find(' ', pos);
        op = i.substr(pos, it);
        pos = it + 1;
        
        if (op == enter) {
            it = i.find(' ', pos);
            id = i.substr(pos, it - pos);
            pos = it + 1;
            name = i.substr(pos);
            
            hash_table[id] = name;
        }
        else if (op == change) {
            it = i.find(' ', pos);
            id = i.substr(pos, it - pos);
            pos = it + 1;
            name = i.substr(pos);
            
            hash_table[id] = name;
        }
        else
            id = i.substr(pos);
        result.push_back(make_pair(op, id));
    }
    for (auto i: result) {
        op = hash_table[i.second];
        op += "님이 ";
        if (i.first == enter)
            op += "들어왔습니다.";
        else if (i.first == leave)
            op += "나갔습니다.";
        else
            continue;
        answer.push_back(op);
    }
    return answer;
}