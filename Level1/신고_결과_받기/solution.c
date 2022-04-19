#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN (1000)
#define MAX_ID  (22)
int simple_hash(const char *str, int len) {
    int hash = 0;
    for (int i = 0; i < len; i++)
        hash += str[i];
    return hash;
}
// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * id_list_len);
    char* hash_check[MAX_LEN];
    int hash_index[MAX_LEN] = { 0 };
    int reported[MAX_LEN][MAX_LEN];
    int report_cnt[MAX_LEN];
    int i, j, r;
    for (i = 0; i < id_list_len; i++) {
        for (j = 0; j < id_list_len; j++)
            reported[i][j] = 0;
        report_cnt[i] = 0;
        answer[i] = 0;
        hash_check[i] = NULL;
    }
    for (i = 0; i < id_list_len; i++) {
        j = simple_hash(id_list[i], strlen(id_list[i]));
        while (hash_check[(j % id_list_len)] != NULL)
            j++;
        hash_check[(j % id_list_len)] = id_list[i];
        hash_index[(j % id_list_len)] = i;
    }
    char a[MAX_ID];
    char b[MAX_ID];
    for (r = 0; r < report_len; r++) {
        strcpy(a, report[r]);
        strtok(a, " ");
        strcpy(b, report[r] + strlen(a) + 1);
        
        i = simple_hash(b, strlen(b));
        while ((hash_check[(i % id_list_len)] != NULL) && (strcmp(hash_check[(i % id_list_len)], b) != 0))
            i++;
        i = hash_index[(i % id_list_len)];
        
        j = simple_hash(a, strlen(a));
        while ((hash_check[(j % id_list_len)] != NULL) && (strcmp(hash_check[(j % id_list_len)], a) != 0))
            j++;
        j = hash_index[(j % id_list_len)];
        
        if (reported[i][j] == false) {
            reported[i][j] = true;
            report_cnt[i]++;
        }
    }
    for (i = 0; i < id_list_len; i++) {
        if (report_cnt[i] >= k) {
            for (j = 0; j < id_list_len; j++) {
                if (reported[i][j] == true)
                    answer[j]++;
            }
        }
    }
    return answer;
}