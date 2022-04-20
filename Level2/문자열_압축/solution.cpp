#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int cnt = s.length();
    int answer = cnt;
    int pos = 0;
    string temp;
    string check;
    string result;
    int dup;
    
    for (int i = 1; i <= cnt / 2; i++) {
        result = "";
        pos = 0;
        while (pos + i <= cnt) {
            temp = s.substr(pos, i);
            dup = 1;
            while ((check = s.substr(pos + i, i)) == temp) {
                dup++;
                pos += i;
            }
            if (dup != 1) {
                result += to_string(dup);
                result += temp;
            }
            else
                result += temp;
            pos += i;
        }
        if (pos < cnt)
            result += s.substr(pos, cnt - pos);
        dup = result.length();
        answer = (dup < answer) ? dup : answer;
        //printf("%d %s\n", result.length(), result.c_str());
    }
    return answer;
}