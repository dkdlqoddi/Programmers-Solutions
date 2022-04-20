import java.util.HashMap;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int id_list_len = id_list.length;
        int[] answer = new int[id_list_len];
        HashMap<String,Integer> ht = new HashMap<String,Integer>();
        boolean[][] flags = new boolean[id_list_len][id_list_len];
        int[] counts = new int[id_list_len];
        
        for (int i = 0; i < id_list_len; i++) {
            answer[i] = 0;
            ht.put(id_list[i], i);
            for (int j = 0; j < id_list_len; j++)
                flags[i][j] = false;
            counts[i] = 0;
        }
        for (String rep: report) {
            String[] r = rep.split(" ");
            int i = ht.get(r[0]);
            int j = ht.get(r[1]);
            if (!flags[j][i]) {
                flags[j][i] = true;
                counts[j]++;
            }
        }
        for (int i = 0; i < id_list_len; i++) {
            if (counts[i] >= k) {
                for (int j = 0; j < id_list_len; j++) {
                    if (flags[i][j])
                        answer[j]++;
                }
            }
        }
        return answer;
    }
}