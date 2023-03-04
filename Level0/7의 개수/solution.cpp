#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for (auto val : array) {
        for (auto c : to_string(val)) {
            if (c == '7')
                answer++;
        }
    }
    return answer;
}