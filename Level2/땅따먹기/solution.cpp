#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = -1;
    int row = land.size();
    int col = land[0].size();
    vector<int> rec;
    vector<int> next;
    for (int c = 0; c < col; c++)
        rec.push_back(land[0][c]);
    int temp;
    for (int r = 1; r < row; r++) {
        next.clear();
        next.assign(land[r].begin(), land[r].end());
        for (int c = 0; c < col; c++) {
            for (int i = 0; i < col; i++) {
                if (i == c)
                    continue;
                temp = land[r][c] + rec[i];
                next[c] = (next[c] < temp) ? temp : next[c];
            }
        }
        rec.clear();
        rec.assign(next.begin(), next.end());
    }
    for (int i = 0; i < col; i++)
        answer = (answer < next[i]) ? next[i] : answer;
    return answer;
}