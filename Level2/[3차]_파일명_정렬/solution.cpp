#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct Node {
    string file;
    string head;
    long long n;
} Node;

bool compare(const Node a, const Node b) {
    if (a.head == b.head)
        return a.n < b.n;
    return a.head < b.head;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Node> rec;
    stringstream ss;
    Node temp;
    for (auto f: files) {
        temp.file = f;
        int div = 0;
        for (int i = 0; i < f.length(); i++) {
            if (('0' <= f[i]) && (f[i] <= '9')) {
                div = i;
                break;
            }
        }
        temp.head = f.substr(0, div);
        for (int i = 0; i < temp.head.length(); i++) {
            if (('A' <= temp.head[i]) && (temp.head[i] <= 'Z'))
                temp.head[i] += 'a' - 'A';
        }
        stringstream ss(f.substr(div, f.length() - div));
        ss >> temp.n;
        rec.push_back(temp);
    }
    stable_sort(rec.begin(), rec.end(), compare);
    for (auto r: rec)
        answer.push_back(r.file);
    return answer;
}