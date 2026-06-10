class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        
        vector<vector<char>> bucket(n+1);

        for(auto it : mp){
            char ch = it.first;
            int freq = it.second;
            bucket[freq].push_back(ch);
        }
        int idx=0;
        for(int i=n; i>=0; i--){
            if(bucket[i].empty()) continue;
            for(char ch : bucket[i]){
                for(int f = 0; f < i; f++){
                    s[idx] = ch;
                    idx++;
                }
            }
        }
        return s;
    }
};
