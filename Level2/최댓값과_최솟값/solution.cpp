#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string temp;
    long long val;
    long long min = numeric_limits<long long>::max();
    long long max = numeric_limits<long long>::min();
    while (getline(ss, temp, ' ')) {
        val = stoll(temp);
        min = (val < min) ? val : min;
        max = (max < val) ? val : max;
    }
    // printf("%lld %lld\n", min, max);
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    return answer;
}