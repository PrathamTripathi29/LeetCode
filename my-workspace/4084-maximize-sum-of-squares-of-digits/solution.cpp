class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum == 0){
            return (num == 1) ? "0" : "";
        }
        if(sum > num*9){
            return "";
        }
        vector<int> ans;
        int noof9s = sum/9;
        int remdigit = sum%9;
        for(int i=0; i<noof9s; i++){
            ans.push_back(9);
        }
        if(ans.size() < num && remdigit > 0){
            ans.push_back(remdigit);
        }
        while(ans.size() < num){
            ans.push_back(0);
        }
        sort(ans.rbegin(), ans.rend());
        string str = "";
        for(int i=0; i<ans.size(); i++){
            str.push_back(char('0' + ans[i]));
        }
        return str;
    }
};
