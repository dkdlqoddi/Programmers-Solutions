#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int row = arr1.size();
    int col = arr2[0].size();
    int cnt = arr1[0].size();
    int val;
    for (int r = 0; r < row; r++) {
        vector<int> temp;
        for (int c = 0; c < col; c++) {
            val = 0;
            for (int i = 0; i < cnt; i++)
                val += arr1[r][i] * arr2[i][c];
            temp.push_back(val);
        }
        answer.push_back(temp);
    }
    return answer;
}