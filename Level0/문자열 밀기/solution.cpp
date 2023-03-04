#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int A_len = A.size();
    bool flag;
    A += A;
    for (int i = 2 * A_len - 1; i >= A_len; i--) {
        if (A[i] == B[A_len - 1]) {
            flag = true;
            for (int j = 1; j < A_len; j++) {
                if (A[i - j] != B[A_len - 1 - j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return 2 * A_len - i - 1;
        }
    }
    return -1;
}