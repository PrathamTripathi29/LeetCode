class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        string ans = "";
        for(int i = 0; i < num.size(); i++){
            while(!s.empty() && (k > 0) && (s.top() - '0') > (num[i] - '0')){
                    s.pop();
                    k--;
            }
            s.push(num[i]);
        }
        while(!s.empty() &&k>0){
            s.pop();
            k--;
        }
        if(s.empty())return "0";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        while(ans.size() > 0 && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.empty()){
            return "0";
        }
        return ans;

    }
};
