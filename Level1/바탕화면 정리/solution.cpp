#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int rows = wallpaper.size();
    int cols = wallpaper[0].size();
    int rs = -1, rl = -1;
    int cs = -1, cl = -1;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (wallpaper[r][c] == '#') {
                if (rs == -1) {
                    rs = r;
                    rl = r;
                    cs = c;
                    cl = c;
                }
                else {
                    if (r < rs)
                        rs = r;
                    else if (rl < r)
                        rl = r;
                    if (c < cs)
                        cs = c;
                    else if (cl < c)
                        cl = c;
                }
            }
        }
    }
    return {rs, cs, rl + 1, cl + 1};
}