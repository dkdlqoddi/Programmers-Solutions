#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_CNT (6)

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt = 0;
    int match_cnt = 0;
    bool flag[MAX_CNT] = { 0 };
    
    for (auto l: lottos) {
        if (l == 0) {
            zero_cnt++;
            continue;
        }
        for (int i = 0; i < MAX_CNT; i++) {
            if (flag[i])
                continue;
            else if (l == win_nums[i]) {
                flag[i] = true;
                match_cnt++;
                break;
            }
        }
    }
    
    answer.push_back(((match_cnt + zero_cnt) > 0) ? (7 - match_cnt - zero_cnt) : 6);
    answer.push_back((match_cnt > 0) ? (7 - match_cnt) : 6);
    return answer;
}