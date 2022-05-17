#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<pair<int,int>> Q;
    pair<int,int> temp;
    bool flags[200];
    for (int i = 0; i < n; i++)
        flags[i] = true;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if ((r == c) || (computers[r][c] == 0))
                continue;
            Q.push(make_pair(r, c));
            while (!Q.empty()) {
                temp = Q.front();
                Q.pop();
                computers[temp.first][temp.second] = 0;
                computers[temp.second][temp.first] = 0;
                flags[temp.first] = false;
                flags[temp.second] = false;
                for (int i = 0; i < n; i++) {
                    if ((i == temp.first) || (i == temp.second))
                        continue;
                    if (computers[i][temp.first])
                        Q.push(make_pair(i, temp.first));
                    if (computers[i][temp.second])
                        Q.push(make_pair(i, temp.second));
                }
            }
            answer++;
        }
    }
    for (int i = 0; i < n; i++) {
        answer += flags[i];
    }
    return answer;
}