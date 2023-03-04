#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int average = total / num;
    int offset = (num / 2);
    if ((num % 2) == 0)
        offset -= 1;
    for (int i = 0; i < num; i++)
        answer.push_back(average - offset + i);
    return answer;
}