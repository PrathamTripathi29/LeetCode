class Solution {
public:
    int vowelConsonantScore(string s) {
        int score = 0;
        int v = 0;
        int c = 0;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                v++;
            } else if(ch == ' ' || (ch >= '0' && ch <= '9')){
                continue;
            } else {
                c++;
            }
        }
        if(c == 0) return 0;
        return (int)floor(v/c);
    }
};
