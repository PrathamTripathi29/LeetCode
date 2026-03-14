class Solution {
public:
    string getHappyString(int n, int k) {
        int NoOfStrings = 3*(1<<(n-1));
        if(k > NoOfStrings) return "";
        string ans;
        vector<char> choices = {'a', 'b', 'c'};
        for(int i=0; i<n; i++){
            int block = 1<<(n-1-i);
            for(char ch : choices){
                if(!ans.empty() && ans.back() == ch) continue;
                if(k > block){
                    k -= block;
                } else {
                    ans.push_back(ch);
                    break;
                }
            }
        }
        return ans;
    }
};
