#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool data[101][101] = { false };
    for (auto r: results)
        data[r[0]][r[1]] = true;
    for (int b = 1; b <= n; b++) {
        for (int a = 1; a <= n; a++) {
            for (int c = 1; c <= n; c++) {
                if ((data[a][c] == true) || ((data[a][b] == true) && (data[b][c] == true))) {
                    data[a][c] = true;
                }
            }
        }
    }
    int count[101] = { 0 };
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (data[a][b]) {
                count[a] += 1;
                count[b] += 1;
            }
        }
    }
    for (int a = 1; a <= n; a++) {
        if (count[a] == n - 1)
            answer++;
    }
    return answer;
}