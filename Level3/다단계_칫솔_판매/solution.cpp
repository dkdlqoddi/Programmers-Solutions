#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define PROFIT  (100)

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int enroll_count = enroll.size();
    int seller_count = seller.size();
    
    unordered_map<string,int> enroll_hash_table;
    unordered_map<string,string> referral_table;
    for (int i = 0; i < enroll_count; i++) {
        enroll_hash_table[enroll[i]] = i;
        referral_table[enroll[i]] = referral[i];
        answer.push_back(0);
    }
    
    
    int profit, tax;
    string name;
    for (int i = 0; i < seller_count; i++) {
        name = seller[i];
        profit = PROFIT * amount[i];
        tax = profit / 10;
        answer[enroll_hash_table[name]] += profit - tax;
        while (((name = referral_table[name]) != "-") && (tax != 0)) {
            profit = tax;
            tax = profit / 10;
            answer[enroll_hash_table[name]] += profit - tax;
        }
    }
    return answer;
}