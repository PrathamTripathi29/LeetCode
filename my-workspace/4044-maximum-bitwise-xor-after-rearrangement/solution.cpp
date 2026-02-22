class Solution {
public:
    string maximumXor(string s, string t) {
        int count0 = 0, count1 = 0;
        for(char ch : t){
            if(ch == '0') count0++;
            else count1++;
        }
        string ans;
        for(char ch : s){
            if(ch == '0'){
                if(count1 > 0){
                    ans.push_back('1');
                    count1--;
                } else {
                    ans.push_back('0');
                    count0--;
                }
            } else {
                if(count0 > 0){
                    ans.push_back('1');
                    count0--;
                } else{
                    ans.push_back('0');
                    count1--;
                }
            }
        }
        return ans;
    }
};
