#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int bab_len;
    bool flag;
    for (auto bab: babbling) {
        bab_len = bab.size();
        flag = true;
        for (int i = 0; i < bab_len; i++) {
            switch (bab[i]) {
                case 'a':
                    if ((bab_len < i + 3) || (bab[i + 1] != 'y') || (bab[i + 2] != 'a')) {
                        flag = false;
                        break;
                    }
                    i += 2;
                    break;
                case 'y':
                    if ((bab_len < i + 2) || (bab[i + 1] != 'e')) {
                        flag = false;
                        break;
                    }
                    i += 1;
                    break;
                case 'w':
                    if ((bab_len < i + 3) || (bab[i + 1] != 'o') || (bab[i + 2] != 'o')) {
                        flag = false;
                        break;
                    }
                    i += 2;
                    break;
                case 'm':
                    if ((bab_len < i + 2) || (bab[i + 1] != 'a')) {
                        flag = false;
                        break;
                    }
                    i += 1;
                    break;
                default:
                    flag = false;
                    break;
            }
            if (!flag)
                break;
        }
        if (flag)
            answer++;
    }
    return answer;
}