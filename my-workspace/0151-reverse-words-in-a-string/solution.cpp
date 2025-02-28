class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word;
        istringstream stream(s);
        while(stream >> word){
            ans = word + " " + ans;
        }
        ans.pop_back();
        return ans;
    }
};
