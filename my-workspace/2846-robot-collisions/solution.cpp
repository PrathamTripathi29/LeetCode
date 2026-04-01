class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int, tuple<int, char, int>> mp;
        for(int i=0; i<n; i++){
            mp[positions[i]] = {healths[i], directions[i], i};
        }
        stack<tuple<int, int, char, int>> s;
        sort(positions.begin(), positions.end());
        int i=0;
        while(i < n){
            if(s.empty() || get<2>(s.top()) == 'L' || get<1>(mp[positions[i]]) == 'R'){
                s.push({positions[i], get<0>(mp[positions[i]]), get<1>(mp[positions[i]]), get<2>(mp[positions[i]])});
                i++;
                continue;
            }
            while(!s.empty() && get<2>(s.top()) == 'R' && i<n && get<1>(mp[positions[i]]) == 'L'){
                if(get<1>(s.top()) < get<0>(mp[positions[i]])){
                    s.pop();
                    get<0>(mp[positions[i]])--;
                } else if(get<1>(s.top()) == get<0>(mp[positions[i]])){
                    s.pop();
                    i++;
                } else {
                    get<1>(s.top())--;
                    i++;
                }
            }
        }
        vector<int> ans(n, -1);
        while(!s.empty()){
            auto [p, h, d, i] = s.top();
            ans[i] = h;
            s.pop();
        }
        vector<int> finalAns;
        for(int i=0; i<n; i++){
            if(ans[i] != -1){
                finalAns.push_back(ans[i]);
            }
        }
        return finalAns;
    }
};
