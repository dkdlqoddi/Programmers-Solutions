#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct Node {
    long long s, e;
    bool operator<(const Node a) {
        if (e == a.e)
            return s < a.s;
        return e < a.e;
    }
} Node;

int solution(vector<string> lines) {
    int answer = 0;
    int cnt = lines.size();
    vector<Node> rec;
    stringstream ss;
    Node temp;
    double val;
    for (auto l: lines) {
        ss.clear();
        ss.str(l.substr(17, l.length()));
        ss >> val;
        temp.e = 36000000 * (l[11] - '0') + 3600000 * (l[12] - '0') + 600000 * (l[14] - '0') + 60000 * (l[15] - '0') + (1000 * val);
        ss >> val;
        temp.s = temp.e - (1000 * val) + 1;
        rec.push_back(temp);
    }
    sort(rec.begin(), rec.end());
    // for (auto r: rec)
        // printf("(%lld,\t%lld)\n", r.s, r.e);
    int count;
    for (int i = 0; i < cnt; i++) {
        count = 1;
        for (int j = i + 1; j < cnt; j++) {
            if ((rec[j].s < rec[i].e + 1000) && (rec[i].e <= rec[j].e))
                count++;
        }
        answer = (answer < count) ? count : answer;
    }
    return answer;
}