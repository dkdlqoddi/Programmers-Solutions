#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string str_n = "";
    if (n == 0)
        return 0;
    while (n != 0) {
        str_n += ('0' + (n % k));
        n /= k;
    }
    reverse(str_n.begin(), str_n.end());
    stringstream ss(str_n);
    string temp;
    long long val;
    bool flag;
    while (getline(ss, temp, '0')) {
        if ((temp.length() == 0) || (temp == "1"))
            continue;
        val = stoll(temp);
        flag = true;
        for (long long i = 2; i * i <= val; i++) {
            if ((val % i) == 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
    }
    return answer;
}