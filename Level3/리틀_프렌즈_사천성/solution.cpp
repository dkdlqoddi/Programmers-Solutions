#include <string>
#include <vector>

using namespace std;

#define ALPHABET    (26)

typedef struct Pos {
    int row, col;
    Pos(int _row, int _col) : row(_row), col(_col) {};
} Pos;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string impossible = "IMPOSSIBLE";
    string answer = "";
    vector<vector<Pos>> location;
    for (int idx = 0; idx < ALPHABET; idx++) {
        vector<Pos> temp;
        location.push_back(temp);
    }
    
    int target_cnt = 0;
    int rows = board.size();
    int cols = board[0].size();
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if ((board[row][col] == '.') || (board[row][col] == '*'))
                continue;
            location[board[row][col] - 'A'].push_back(Pos(row, col));
            target_cnt++;
        }
    }
    
    int next_cnt = 0;
    while ((target_cnt != 0) && (target_cnt != next_cnt)) {
        next_cnt = target_cnt;
        for (int idx = 0; idx < ALPHABET; idx++) {
            if (location[idx].size() == 0)
                continue;
            Pos sp = location[idx][0];
            Pos ep = location[idx][1];
            bool connected;
            
            if (sp.col > ep.col) {
                // flipped-ㄱ
                connected = true;
                for (int col = sp.col - 1; col >= ep.col; col--) {
                    if (board[sp.row][col] != '.') {
                        connected = false;
                        break;
                    }
                }
                for (int row = sp.row + 1; row < ep.row; row++) {
                    if (board[row][ep.col] != '.') {
                        connected = false;
                        break;
                    }
                }
                if (connected) {
                    answer += idx + 'A';
                    board[sp.row][sp.col] = '.';
                    board[ep.row][ep.col] = '.';
                    location[idx].clear();
                    target_cnt -= 2;
                    break;
                }
                
                // flipped-ㄴ
                connected = true;
                for (int row = sp.row + 1; row <= ep.row; row++) {
                    if (board[row][sp.col] != '.') {
                        connected = false;
                        break;
                    }
                }
                for (int col = sp.col - 1; col > ep.col; col--) {
                    if (board[ep.row][col] != '.') {
                        connected = false;
                        break;
                    }
                }
                if (connected) {
                    answer += idx + 'A';
                    board[sp.row][sp.col] = '.';
                    board[ep.row][ep.col] = '.';
                    location[idx].clear();
                    target_cnt -= 2;
                    break;
                }
            }
            else {
                // ㄱ
                connected = true;
                for (int col = sp.col + 1; col <= ep.col; col++) {
                    if (board[sp.row][col] != '.') {
                        connected = false;
                        break;
                    }
                }
                for (int row = sp.row + 1; row < ep.row; row++) {
                    if (board[row][ep.col] != '.') {
                        connected = false;
                        break;
                    }
                }
                if (connected) {
                    answer += idx + 'A';
                    board[sp.row][sp.col] = '.';
                    board[ep.row][ep.col] = '.';
                    location[idx].clear();
                    target_cnt -= 2;
                    break;
                }
                
                // ㄴ
                connected = true;
                for (int row = sp.row + 1; row <= ep.row; row++) {
                    if (board[row][sp.col] != '.') {
                        connected = false;
                        break;
                    }
                }
                for (int col = sp.col + 1; col < ep.col; col++) {
                    if (board[ep.row][col] != '.') {
                        connected = false;
                        break;
                    }
                }
                if (connected) {
                    answer += idx + 'A';
                    board[sp.row][sp.col] = '.';
                    board[ep.row][ep.col] = '.';
                    location[idx].clear();
                    target_cnt -= 2;
                    break;
                }
            }
        }
    }
    if (target_cnt != 0)
        return impossible;
    return answer;
}