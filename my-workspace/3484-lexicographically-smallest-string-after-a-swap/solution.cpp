class Solution {
public:
    bool paritycheck(char a, char b){
        int x = a - '0';
        int y = b - '0';
        if((x%2 == 0 && y%2 == 0) || (x%2 != 0 && y%2 != 0)){
            return true;
        }
        else{
            return false;
        }
    }
    string getSmallestString(string s) {
        int l = s.length();
        for(int i=0; i<l-1; i++){
            char a = s.at(i);
            char b = s.at(i+1);
            if(paritycheck(a,b)){
                if(b < a){
                    swap(s.at(i), s.at(i+1));
                    break;
                }
            }
        }
        return s;
    }
};
