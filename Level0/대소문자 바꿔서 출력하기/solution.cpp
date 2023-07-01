#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (auto s: str)
    {
        if (('a' <= s) && (s <= 'z'))
        {
            printf("%c", s - 'a' + 'A');
        }
        else
        {
            printf("%c", s - 'A' + 'a');
        }
    }
    return 0;
}