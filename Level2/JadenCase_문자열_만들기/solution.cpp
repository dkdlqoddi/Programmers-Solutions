#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, ' ')) {
        if (temp.length() == 0) {
            answer += " ";
            continue;
        }
        if (('a' <= temp[0]) && (temp[0] <= 'z'))
            temp[0] += 'A' - 'a';
        for (int i = 1; i < temp.length(); i++) {
            if (('A' <= temp[i]) && (temp[i] <= 'Z'))
                temp[i] += 'a' - 'A';
        }
        temp += " ";
        answer += temp;
        // printf("%s\n", temp.c_str());
    }
    if (s.back() != ' ')
        answer.pop_back();
    return answer;
}