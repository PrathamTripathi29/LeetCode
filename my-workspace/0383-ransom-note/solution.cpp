class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mag;
        for(int i=0; i<magazine.length(); i++){
            char c = magazine[i];
            if(mag.find(c) == mag.end()){
                mag[c] = 1;
            }
            else{
                mag[c]++;
            }
        }

        for(int i=0; i<ransomNote.length(); i++){
            char c = ransomNote[i];
            if(mag.find(c) != mag.end() && mag[c] > 0){
                mag[c]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
