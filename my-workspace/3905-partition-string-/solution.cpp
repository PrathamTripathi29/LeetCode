class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string, int> mp;
        vector<string> segments;
        string seg = "";
        for(int i=0; i<s.length(); i++){
            seg += s[i];
            if(mp.find(seg) == mp.end()){
                segments.push_back(seg);
                mp[seg] = 1;
                seg = "";
            }
        }
        return segments;
    }
};
