#include <string>
#include <vector>

using namespace std;
string binary_string(int n) {
    string str_n = "";
    while (n != 0) {
        str_n += ('0' + (n % 2));
        n /= 2;
    }
    return str_n;
}
int binary_count(string str_n) {
    int result = 0;
    for (int i = 0; i < str_n.length(); i++)
        result += (str_n[i] - '0');
    return result;
}
int solution(int n) {
    int answer = n + 1;
    string str_n = binary_string(n);
    int cnt = binary_count(str_n);
    while (cnt != binary_count(binary_string(answer)))
        answer++;
    return answer;
}