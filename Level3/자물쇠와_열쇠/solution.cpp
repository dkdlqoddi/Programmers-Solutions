#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int key_n = key.size();
    int lock_n = lock.size();
    int diff_n = key_n + lock_n - 1;
    int total = lock_n * lock_n;
    
    for (int r = 0; r < lock_n; r++) {
        for (int c = 0; c < lock_n; c++)
            total -= lock[r][c];
        for (int c = 0; c < key_n - 1; c++)
            lock[r].insert(lock[r].begin(), 2);
        for (int c = 0; c < key_n - 1; c++)
            lock[r].push_back(2);
    }
    
    for (int r = 0; r < key_n - 1; r++) {
        vector<int> temp_front;
        vector<int> temp_back;
        for (int c = 0; c < diff_n + key_n - 1; c++) {
            temp_front.push_back(2);
            temp_back.push_back(2);
        }
        lock.insert(lock.begin(), temp_front);
        lock.push_back(temp_back);
    }
    
    bool flag_up, flag_right, flag_down, flag_left;
    int up, right, down, left;
    for (int r = 0; r < diff_n; r++) {
        for (int c = 0; c < diff_n; c++) {
            flag_up = true; flag_right = true; flag_down = true; flag_left = true;
            up = 0; right = 0; down = 0; left = 0;
            for (int dr = 0; dr < key_n; dr++) {
                for (int dc = 0; dc < key_n; dc++) {
                    if (key[dr][dc] == 1 && lock[r + dr][c + dc] == 1)
                        flag_up = false;
                    up += (key[dr][dc] & !lock[r + dr][c + dc]);
                    
                    if (key[dc][key_n - dr - 1] == 1 && lock[r + dr][c + dc] == 1)
                        flag_right = false;
                    right += (key[dc][key_n - dr - 1] & !lock[r + dr][c + dc]);
                    
                    if (key[key_n - dr - 1][key_n - dc - 1] == 1 && lock[r + dr][c + dc] == 1)
                        flag_down = false;
                    down += (key[key_n - dr - 1][key_n - dc - 1] & !lock[r + dr][c + dc]);
                    
                    if (key[key_n - dc - 1][dr] == 1 && lock[r + dr][c + dc] == 1)
                        flag_left = false;
                    left += (key[key_n - dc - 1][dr] & !lock[r + dr][c + dc]);
                }
            }
            if ((flag_up && up >= total) || (flag_right && right >= total) || (flag_down && down >= total) || (flag_left && left >= total))
                return true;
        }
    }
    return false;
}