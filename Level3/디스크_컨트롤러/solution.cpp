#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Node {
    int s, d;
    bool operator<(Node b) const {
        return d > b.d;
    }
} Node;

int solution(vector<vector<int>> jobs) {
    priority_queue<Node> rec;
    Node temp;
    int answer = 0;
    int length = jobs.size();
    int cnt = jobs.size();
    int start = -1, now = 0, idx = 0;
    while (idx < length) {
        for (int i = 0; i < cnt; i++) {
            if ((start < jobs[i][0]) && (jobs[i][0] <= now)) {
                temp.s = jobs[i][0];
                temp.d = jobs[i][1];
                rec.push(temp);
                jobs.erase(jobs.begin() + i);
                i--;
                cnt--;
            }
        }
        if (rec.empty())
            now += 1;
        else {
            temp = rec.top();
            rec.pop();
            // printf("%d %d\n", temp.s, temp.d);
            start = now;
            now += temp.d;
            answer += now - temp.s;
            idx += 1;
        }
    }
    return answer / length;
}