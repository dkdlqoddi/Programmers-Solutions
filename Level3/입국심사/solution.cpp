#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = numeric_limits<long long>::max();
    sort(times.begin(), times.end());
    long long minimum = 0;
    long long maximum = (long long)n * times[0];
    long long medium = maximum / 2;
    long long cnt;
    if (n < times.size())
        return times[n - 1];
    while ((minimum <= medium) && (medium <= maximum)) {
        cnt = 0;
        for (auto t: times)
            cnt += medium / t;
        // printf("%lld %d\n", medium, cnt);
        if (cnt >= n) {
            answer = (medium < answer) ? medium : answer;
            maximum = medium - 1;
        }
        else if (cnt < n)
            minimum = medium + 1;
        medium = (minimum + maximum) / 2;
    }
    return answer;
}