#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<bool>> map;
    vector<int> dis;
    queue<pair<int,int>> Q;
    for (int i = 0; i <= n; i++) {
        vector<bool> temp;
        for (int j = 0; j <= n; j++)
            temp.push_back(false);
        map.push_back(temp);
        dis.push_back(INT_MAX);
    }
    dis[0] = 0;
    dis[1] = 0;
    for (auto e: edge) {
        map[e[0]][e[1]] = true;
        map[e[1]][e[0]] = true;
        if (e[0] == 1)
            Q.push(make_pair(e[1], 1));
        else if (e[1] == 1)
            Q.push(make_pair(e[0], 1));
    }
    pair<int,int> temp;
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if (dis[temp.first] <= temp.second)
            continue;
        dis[temp.first] = temp.second++;
        for (int i = 2; i <= n; i++) {
            if ((!map[temp.first][i]) || (dis[i] < temp.second))
                continue;
            Q.push(make_pair(i, temp.second));
        }
    }
    int far = 0;
    for (int i = 2; i <= n; i++) {
        if (dis[i] == INT_MAX)
            continue;
        far = (far < dis[i]) ? dis[i] : far;
    }
    for (int i = 2; i <= n; i++) {
        if (dis[i] == far)
            answer++;
    }
    return answer;
}