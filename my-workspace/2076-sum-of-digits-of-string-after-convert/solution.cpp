class Solution {
public:
    int getLucky(string s, int k) {
        string trans;
        int ans;
        for(char ch : s){
            int num = ch-'a'+1;
            trans += to_string(num);
        }
        while(k--){
            int sum = 0;
            for(char ch : trans){
                sum += ch-'0';
            }
            trans = to_string(sum);
        }
        ans = stoi(trans);
        return ans;
    }
};
