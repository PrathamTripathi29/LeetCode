class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int l = s.length();
        unordered_map<char, int> rtoi;
        rtoi['I'] = 1;
        rtoi['V'] = 5;
        rtoi['X'] = 10;
        rtoi['L'] = 50;
        rtoi['C'] = 100;
        rtoi['D'] = 500;
        rtoi['M'] = 1000;
        int i=0;
        for(i=0; i<l-1; i++){
            char a = s[i];
            char b = s[i+1];
            if(rtoi[a] >= rtoi[b]){
                num += rtoi[a];
            }
            else{
                num += rtoi[b] - rtoi[a];
                i++;
            }
        }
        if(i == l-1){
            num += rtoi[s[l-1]];
        }
        return num;
    }
};
