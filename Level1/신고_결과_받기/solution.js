function solution(id_list, report, k) {
    let id_list_len = id_list.length;
    var answer = Array(id_list_len);
    var ht = new Map();
    var flags = Array(id_list_len);
    var counts = Array(id_list_len);
    
    for (var i = 0; i < id_list_len; i++) {
        answer[i] = 0;
        ht[id_list[i]] = i;
        var temp = new Array(id_list_len);
        for (var j = 0; j < id_list_len; j++)
            temp[j] = false;
        flags[i] = temp;
        counts[i] = 0;
    }
    report.forEach((element) => {
        let $rep = element.split(" ");
        let $a = ht[$rep[0]];
        let $b = ht[$rep[1]];
        if (!flags[$b][$a]) {
            flags[$b][$a] = true;
            counts[$b]++;
        }
    });
    for (var i = 0; i < id_list_len; i++) {
        if (counts[i] >= k) {
            for (var j = 0; j < id_list_len; j++) {
                if (flags[i][j])
                    answer[j]++;
            }
        }
    }
    return answer;
}