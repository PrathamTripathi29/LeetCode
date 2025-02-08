class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string substring = "";
        
        int l = num.length();
        vector<int> index;
        bool started = false;
        for(int i=0; i<l; i++){
            int digit = num[i]-'0';
            if(digit < change[digit]){
                substring += (char)(change[digit] + '0');
                index.push_back(i);
                started = true;
            }
            else if(digit == change[digit]){
                if(started){
                    substring += num[i];
                    index.push_back(i);
                }
            }
            else{
                if(started) break;
                substring = "";
                index.clear();
            }
        }
        
        for(int i=0; i<index.size(); i++){
            num[index[i]] = substring[i];
        }
        return num;
    }
};
