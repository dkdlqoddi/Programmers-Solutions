#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    int cnt = 0;
    while (answer.length() < t) {
        int temp = num++;
        string str = "";
        if (temp == 0)
            str += '0';
        else {
            while (temp != 0) {
                if ((temp % n) > 9)
                    str += ('A' + (temp % n) - 10);
                else
                    str += ('0' + (temp % n));
                temp /= n;
            }
        }
        reverse(str.begin(), str.end());
        for (int i = cnt; i < cnt + str.length(); i++) {
            if ((i % m) == (p - 1))
                answer += str[i - cnt];
        }
        cnt += str.length();
    }
    if (answer.length() > t)
        answer = answer.substr(0, t);
    return answer;
}