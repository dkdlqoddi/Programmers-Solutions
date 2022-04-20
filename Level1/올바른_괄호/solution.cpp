#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int cnt = 0;
    for (auto c: s) {
        switch (c) {
            case '(':
                cnt++;
                break;
            case ')':
                if (cnt == 0)
                    return false;
                cnt--;
                break;
        }
    }
    if (cnt > 0)
        return false;
    return true;
}