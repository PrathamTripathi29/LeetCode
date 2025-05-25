class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mpsame;
        vector<string> samerec;
        bool check = false;
        int palindrome_length = 0;
        for(auto str : words){
            if(str[0] == str[1]){
                if(mpsame.find(str) == mpsame.end()){
                    mpsame[str] = 1;
                    samerec.push_back(str);
                }
                else{
                    mpsame[str]++;
                }
                continue;
            }
            string rev = str;
            reverse(rev.begin(), rev.end());
            if(mp.find(str) == mp.end()){
                if(mp.find(rev) == mp.end()){
                    mp[rev] = 1;
                }
                else{
                    mp[rev]++;
                }
            }
            else{
                palindrome_length += 4;
                mp[str]--;
                if(mp[str] == 0){
                    mp.erase(str);
                }
            }
        }
        for(auto str : samerec){
            if(mpsame[str]%2 == 0){
                palindrome_length += 2*mpsame[str];
            }
            else{
                palindrome_length += 2*(mpsame[str]-1);
                if(check == false){
                    palindrome_length += 2;
                    check = true;
                }
            }
        }
        return palindrome_length;
    }
};
