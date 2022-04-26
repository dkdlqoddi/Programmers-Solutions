#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CNT (6)

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int zero_cnt = 0;
    int match_cnt = 0;
    bool flags[MAX_CNT] = { false };
    
    for (int i = 0; i < MAX_CNT; i++) {
        if (lottos[i] == 0) {
            zero_cnt++;
            continue;
        }
        for (int j = 0; j < MAX_CNT; j++) {
            if (flags[j])
                continue;
            else if (lottos[i] == win_nums[j]) {
                flags[j] = true;
                match_cnt++;
                break;
            }
        }
    }
    answer[0] = (match_cnt + zero_cnt) > 0 ? (7 - match_cnt - zero_cnt) : 6;
    answer[1] = (match_cnt > 0) ? (7 - match_cnt) : 6;
    return answer;
}