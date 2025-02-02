class Solution {
public:
    int maximum69Number (int num) {
        string ans;
        int n;
        ans = to_string(num);
        int l = ans.length();
        for(int i=0; i<l; i++){
            if(ans.at(i) == '6'){
                ans.at(i) = '9';
                break;
            }
        }
        n = stoi(ans);
        return n;
    }
};
