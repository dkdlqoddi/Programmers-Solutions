#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string aaa = "aaa";
    string::size_type n;
    
    for (int i = 0; i < new_id.length(); i++) {
        if (('a' <= new_id[i]) && (new_id[i] <= 'z'))
            continue;
        else if (('A' <= new_id[i]) && (new_id[i] <= 'Z'))
            new_id[i] += 'a' - 'A';
        else if (('0' <= new_id[i]) && (new_id[i] <= '9'))
            continue;
        else if ((new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.'))
            continue;
        else {
            new_id.erase(new_id.begin() + i--);
        }
    }
    
    while ((n = new_id.find("..")) != string::npos)
        new_id.erase(new_id.begin() + n);
    
    if (new_id[0] == '.')
        new_id.erase(new_id.begin());
    if (new_id.back() == '.')
        new_id.erase(new_id.end() - 1);
    
    if (new_id.length() == 0) {
        answer.append(aaa);
        return answer;
    }
    else if (new_id.length() < 3)
        new_id.append(3 - new_id.length(), new_id.back());
    else if (new_id.length() > 15)
        new_id.erase(new_id.begin() + 15, new_id.end());
    
    if (new_id.back() == '.')
        new_id.erase(new_id.end() - 1);
    
    answer.append(new_id);
    return answer;
}