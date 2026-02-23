class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int size = 1<<k;
        vector<bool> vec(size, false);
        for(int i=0; i<=n-k; i++){
            string subs = s.substr(i, k);
            int num = stoi(subs, nullptr, 2);
            vec[num] = true;
        }
        for(int i=0; i<size; i++){
            if(vec[i] == false) return false;
        }
        return true;
    }
};
