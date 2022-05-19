#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int length = triangle.size();
    int num[length][length];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++)
            num[i][j] = 0;
    }
    int temp;
    num[0][0] = triangle[0][0];
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= i; j++) {
            temp = num[i][j] + triangle[i + 1][j];
            num[i + 1][j] = (num[i + 1][j] < temp) ? temp : num[i + 1][j];
            temp = num[i][j] + triangle[i + 1][j + 1];
            num[i + 1][j + 1] = (num[i + 1][j + 1] < temp) ? temp : num[i + 1][j + 1];
        }
    }
    for (int i = 0; i < length; i++)
        answer = (answer < num[length - 1][i]) ? num[length - 1][i] : answer;
    return answer;
}