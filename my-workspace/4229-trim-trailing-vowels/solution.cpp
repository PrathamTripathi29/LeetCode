class Solution {
public:
    string trimTrailingVowels(string s) {
        string news;
        int n = s.length();
        bool flag = true;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                if(flag){
                    continue;
                } else{
                    news += s[i];
                }
                
            } else {
                news += s[i];
                flag = false;
            }
        }
        reverse(news.begin(), news.end());
        return news;
    }
};
