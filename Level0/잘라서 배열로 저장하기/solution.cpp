#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int len = my_str.size();
    int i;
    for (i = 0; i < len; i += n) {
        answer.push_back(my_str.substr(i, n));
    }
    return answer;
}