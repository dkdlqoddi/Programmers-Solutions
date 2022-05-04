#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int nn = n *  2;
    int temp;
    if (n == 1)
        return 1;
    for (int i = 1; i < n; i++) {
        if ((nn % i) == 0) {
            temp = ((nn / i) - i + 1);
            if (temp < 1)
                break;
            else if ((temp % 2) == 1)
                continue;
            answer++;
        }
    }
    return answer;
}