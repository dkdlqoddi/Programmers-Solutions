#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int div_val = 1000000007;
    vector<vector<int>> map;
    
    for (int r = 0; r < n; r++) {
        vector<int> temp;
        for (int c = 0; c < m; c++)
            temp.push_back(0);
        map.push_back(temp);
    }
    map[0][0] = 1;
    for (auto puddle: puddles)
        map[puddle[1] - 1][puddle[0] - 1] = -1;
    
    for (int r = 1; r < n; r++) {
        if (map[r][0] == -1)
            break;
        map[r][0] = 1;
    }
    for (int c = 1; c < m; c++) {
        if (map[0][c] == -1)
            break;
        map[0][c] = 1;
    }
    for (int r = 1; r < n; r++) {
        for (int c = 1; c < m; c++) {
            if (map[r][c] == -1)
                continue;
            if (map[r - 1][c] != -1)
                map[r][c] += map[r - 1][c];
            if (map[r][c - 1] != -1)
                map[r][c] += map[r][c - 1];
            map[r][c] %= div_val;
        }
    }
    return map[n - 1][m - 1] % div_val;
}