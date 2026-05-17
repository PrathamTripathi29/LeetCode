class Solution {
public:
    bool isLower(char c){
        return c >= 'a' && c <= 'z';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        int n = chunks.size();
        for(int i=0; i<n; i++){
            s += chunks[i];
        }
        unordered_map<string, int> mp;
        long long l = s.length();
        string curr;
        for(long long i=0; i<l; i++){
            char c = s[i];
            if(isLower(c)){
                curr.push_back(c);
            } else if(c == '-'){
                bool leftCheck = (i > 0 && isLower(s[i-1]));
                bool rightCheck = (i <l-1 && isLower(s[i+1]));
                if(leftCheck && rightCheck){
                    curr.push_back(c);
                } else {
                    if(!curr.empty()){
                        mp[curr]++;
                        curr = "";
                    }
                }
            } else {
                if(!curr.empty()){
                    mp[curr]++;
                    curr = "";
                }
            }
        }
        if(!curr.empty()){
            mp[curr]++;
        }
        vector<int> ans;
        for(auto query : queries){
            int freq = mp[query];
            ans.push_back(freq);
        }   
        return ans;
    }
};
