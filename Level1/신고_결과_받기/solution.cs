using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] id_list, string[] report, int k) {
        int id_cnt = id_list.Length;
        int[] answer = new int[id_cnt];
        Dictionary<string,int> ht = new Dictionary<string,int>();
        for (int i = 0; i < id_cnt; i++) {
            answer[i] = 0;
            ht.Add(id_list[i], i);
        }
        
        bool[,] flags = new bool[id_cnt, id_cnt];
        int[] counts = new int[id_cnt];
        for (int i = 0; i < id_cnt; i++) {
            for (int j = 0; j < id_cnt; j++)
                flags[i,j] = false;
        }
        
        foreach (string rep in report) {
            string[] temp = rep.Split(" ", StringSplitOptions.RemoveEmptyEntries);
            int i = ht[temp[0]];
            int j = ht[temp[1]];
            if (!flags[j,i]) {
                flags[j,i] = true;
                counts[j]++;
            }
        }
        for (int i = 0; i < id_cnt; i++) {
            if (counts[i] >= k) {
                for (int j = 0; j < id_cnt; j++) {
                    if (flags[i,j])
                        answer[j]++;
                }
            }
        }
        return answer;
    }
}