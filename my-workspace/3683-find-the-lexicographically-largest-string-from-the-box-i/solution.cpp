class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }
        string ans="";
        int maxlength = word.length() - numFriends + 1;
        for(int i=0; i<word.length(); i++){
            ans = max(ans, word.substr(i, maxlength));
        }
        return ans;
    }
};
