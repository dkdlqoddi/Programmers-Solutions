#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<set<int>> rec;
    vector<int> val = { 0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111 };
    if (N == number)
        return 1;
    
    int temp, cnt;
    for (int n = 0; n <= 8; n++) {
        set<int> temp_rec;
        if (N * val[n] == number)
            return n;
        temp_rec.insert(N * val[n]);
        if (n < 2) {
            rec.push_back(temp_rec);
            continue;
        }
        for (int i = 1; i <= (n / 2); i++) {
            for (auto a: rec[i]) {
                for (auto b: rec[n - i]) {
                    temp = a + b;
                    if (temp == number) {
                        // printf("%d + %d\n", a, b);
                        return n;
                    }
                    temp_rec.insert(temp);
                    
                    temp = a * b;
                    if (temp == number) {
                        // printf("%d * %d\n", a, b);
                        return n;
                    }
                    temp_rec.insert(temp);
                    
                    if (b != 0) {
                        temp = a / b;
                        if (temp == number) {
                            // printf("%d / %d\n", a, b);
                            return n;
                        }
                        if (temp != 0)
                            temp_rec.insert(temp);
                    }
                    
                    if (a != 0) {
                        temp = b / a;
                        if (temp == number) {
                            // printf("%d / %d\n", b, a);
                            return n;
                        }
                        if (temp != 0)
                            temp_rec.insert(temp);
                    }
                    
                    temp = a - b;
                    if (temp == number) {
                        // printf("%d - %d\n", a, b);
                        return n;
                    }
                    if (temp != 0)
                        temp_rec.insert(temp);
                    
                    temp = b - a;
                    if (temp == number) {
                        // printf("%d - %d\n", b, a);
                        return n;
                    }
                    if (temp != 0)
                        temp_rec.insert(temp);
                }
            }
        }
        for (auto a: rec[n - 1]) {
            temp = a + N;
            if (temp == number) {
                // printf("%d + %d\n", a, N);
                return n;
            }
            temp_rec.insert(temp);
            
            temp = a * N;
            if (temp == number) {
                // printf("%d * %d\n", a, N);
                return n;
            }
            temp_rec.insert(temp);
            
            temp = a / N;
            if (temp == number) {
                // printf("%d / %d\n", a, N);
                return n;
            }
            if (temp != 0)
                temp_rec.insert(temp);
            
            if (a != 0) {
                temp = N / a;
                if (temp == number) {
                    // printf("%d / %d\n", N, a);
                    return n;
                }
                if (temp != 0)
                    temp_rec.insert(temp);
            }
            
            temp = a - N;
            if (temp == number) {
                // printf("%d - %d\n", a, N);
                return n;
            }
            if (temp != 0)
                temp_rec.insert(temp);
            
            temp = N - a;
            if (temp == number) {
                // printf("%d - %d\n", N, a);
                return n;
            }
            if (temp != 0)
                temp_rec.insert(temp);
        }
        rec.push_back(temp_rec);
    }
    return answer;
}