import (
    "strings"
)

func solution(id_list []string, report []string, k int) []int {
    var ht map[string]int
    ht = make(map[string]int)
    id_list_len := len(id_list)
    flags := [][]bool {}
    counts := []int {}
    answer := []int {}
    for i, id := range id_list {
        ht[id] = i
        temp := []bool {}
        for j := 1; j <= id_list_len; j++ {
            temp = append(temp, false)
        }
        flags = append(flags, temp)
        counts = append(counts, 0)
        answer = append(answer, 0)
    }
    for _, rep := range report {
        rep := strings.Split(rep, " ")
        a := ht[rep[0]]
        b := ht[rep[1]]
        if (!flags[b][a]) {
            flags[b][a] = true
            counts[b]++
        }
    }
    for i, cnt := range counts {
        if (cnt >= k) {
            for j, f := range flags[i] {
                if (f) {
                    answer[j]++
                }
            }
        }
    }
    return answer
}