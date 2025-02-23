class Solution {
public:
    bool hasSameDigits(string s) {
        string ns = "";
        do{
            ns = "";
            for(int i=0; i<s.length()-1; i++){
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                char r = (a + b) % 10 + '0';
                ns += r;
            }
            s = ns;
        } while(ns.length() > 2);
        if(ns[0] == ns[1]){
            return true;
        }
        return false;
    }
};
