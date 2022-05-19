#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    vector<vector<int>> rec;
    int answer = 0;
    int length = jobs.size();
    int cnt = jobs.size();
    int start = -1, now = 0, idx = 0;
    while (idx < length) {
        for (int i = 0; i < cnt; i++) {
            if ((start < jobs[i][0]) && (jobs[i][0] <= now)) {
                rec.push_back(jobs[i]);
                jobs.erase(jobs.begin() + i);
                i--;
                cnt--;
            }
        }
        if (rec.empty())
            now += 1;
        else {
            sort(rec.begin(), rec.end(), compare);
            start = now;
            now += rec[0][1];
            answer += now - rec[0][0];
            idx += 1;
            // printf("[%d] %d %d\n", now, rec[0][0], rec[0][1]);
            rec.erase(rec.begin());
        }
    }
    return answer / length;
}