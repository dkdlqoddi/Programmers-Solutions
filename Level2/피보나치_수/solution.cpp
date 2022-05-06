#include <string>
#include <vector>
#define DIV_VAL (1234567)

using namespace std;

int solution(int n) {
    int cur = 1;
    vector<int> fibonacci;
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    while (cur < n) {
        fibonacci.push_back((fibonacci[cur - 1] + fibonacci[cur]) % DIV_VAL);
        cur++;
    }
    return fibonacci[cur];
}