class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ssize = s.length();
        int tsize = t.length();
        unordered_map<char, char> stot;
        unordered_map<char, char> ttos;
        for(int i=0; i<ssize; i++){
            char S = s[i];
            char T = t[i];
            if(stot.find(S) == stot.end()){
                stot[S] = T;
            }
            else{
                if(stot[S] != T){
                    return false;
                }
            }
        }
        for(int i=0; i<tsize; i++){
            char S = s[i];
            char T = t[i];
            if(ttos.find(T) == ttos.end()){
                ttos[T] = S;
            }
            else{
                if(ttos[T] != S){
                    return false;
                }
            }
        }
        return true;
    }
};
