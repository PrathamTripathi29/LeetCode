class Solution {
public:
    string largestGoodInteger(string num) {
        int n =num.length();
        string maxnum = "";
        for(int i=2; i<n; i++){
            if((num[i-2] == num[i-1]) && (num[i-1] == num[i])){
                string substr = num.substr(i-2, 3);
                maxnum = max(maxnum, substr);
            }
        }
        return maxnum;
    }
};
