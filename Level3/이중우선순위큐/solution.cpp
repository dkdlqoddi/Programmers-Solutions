#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int,vector<int>,less<int>> greater_first;
    priority_queue<int,vector<int>,greater<int>> lesser_first;
    int greater_idx = 0;
    int lesser_idx = 0;
    int val;
    char oper;
    for (auto operation: operations) {
        oper = operation[0];
        operation.erase(0, 1);
        val = stoi(operation);
        switch (oper) {
            case 'I':
                greater_first.push(val);
                lesser_first.push(val);
                break;
            case 'D':
                switch (val) {
                    case 1:
                        if (greater_first.size() == greater_idx)
                            break;
                        greater_first.pop();
                        lesser_idx++;
                        break;
                    case -1:
                        if (lesser_first.size() == lesser_idx)
                            break;
                        lesser_first.pop();
                        greater_idx++;
                        break;
                }
                break;
        }
        if (greater_first.size() == greater_idx) {
            while (!greater_first.empty())
                greater_first.pop();
            greater_idx = 0;
            while (!lesser_first.empty())
                lesser_first.pop();
            lesser_idx = 0;
        }
    }
    if (greater_first.size() <= greater_idx) {
        if (lesser_first.size() <= lesser_idx) {
            answer.push_back(0);
            answer.push_back(0);
        }
        else {
            answer.push_back(lesser_first.top());
            while (!lesser_first.empty()) {
                val = lesser_first.top();
                lesser_first.pop();
            }
            answer.push_back(val);
        }
    }
    else {
        answer.push_back(greater_first.top());
        answer.push_back(lesser_first.top());
    }
    return answer;
}