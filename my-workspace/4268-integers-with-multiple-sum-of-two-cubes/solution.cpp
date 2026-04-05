class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long, int> mp;
        for(int a=1; a<=1000; a++){
            int a3 = a*a*a;
            if(a3 > n) break;
            for(int b=a; b<=1000; b++){
                int sum = a3 + b*b*b;
                if(sum > n) break;
                mp[sum]++;
            }
        }
        vector<int> ans;
        for(auto it : mp){
            if(it.second > 1) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
