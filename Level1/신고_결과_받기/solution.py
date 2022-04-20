def solution(id_list, report, k):
    id_list_len = len(id_list)
    answer = [0] * id_list_len
    ht = dict(zip(id_list, range(id_list_len)))
    flags = [[False for _ in range(id_list_len)] for __ in range(id_list_len)]
    counts = [0] * id_list_len
    
    for rep in report:
        rep = [ht[r] for r in rep.split(" ")]
        if (flags[rep[1]][rep[0]] == False):
            flags[rep[1]][rep[0]] = True
            counts[rep[1]] += 1
    for i in range(id_list_len):
        if (counts[i] >= k):
            for j in range(id_list_len):
                if (flags[i][j] == True):
                    answer[j] += 1
    return answer