#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

#define MAX_WORDS   (51)

int solution(string begin, string target, vector<string> words) {
    words.insert(words.begin(), begin);
    int word_cnt = words.size();
    int str_len = words[0].length();
    vector<vector<int>> related;
    unordered_map<string,int> hash_table;
    bool check[MAX_WORDS][MAX_WORDS];
    
    for (int i = 0; i < word_cnt; i++) {
        vector<int> temp;
        related.push_back(temp);
        hash_table[words[i]] = i;
        for (int j = 0; j < word_cnt; j++)
            check[i][j] = false;
    }
    
    int diff;
    for (int i = 0; i < word_cnt; i++) {
        for (int j = i + 1; j < word_cnt; j++) {
            diff = 0;
            for (int k = 0; k < str_len; k++)
                diff += (words[i][k] != words[j][k]);
            if (diff == 1) {
                related[i].push_back(hash_table[words[j]]);
                related[j].push_back(hash_table[words[i]]);
            }
        }
    }
    
    if (begin == target)
        return 0;
    int begin_idx = hash_table[begin];
    if (hash_table.find(target) == hash_table.end())
        return 0;
    int target_idx = hash_table[target];
    check[0][begin_idx] = true;
    for (int answer = 0; answer <= word_cnt; answer++) {
        for (int i = 0; i < word_cnt; i++) {
            if (check[answer][i]) {
                for (auto related_word_idx: related[i]) {
                    if (target_idx == related_word_idx)
                        return answer + 1;
                    check[answer + 1][related_word_idx] = true;
                }
            }
        }
    }
    return 0;
}