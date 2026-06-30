class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0;
        int mx = 0;
        for(char ch : s){
            if(ch == '('){
                mx++;
                mn++;
            } else if(ch == ')'){
                mx--;
                mn--;
            } else {
                mx++;
                mn--;
            }
            if(mx < 0) return false;
            mn = max(mn, 0);
        }
        return mn == 0;
    }
};
