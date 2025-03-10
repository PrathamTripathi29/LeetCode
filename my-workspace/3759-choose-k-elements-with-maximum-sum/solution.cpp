class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);
        vector<pair<int, int>> num1idx;
        for(int i=0; i<n; i++){
            num1idx.push_back({nums1[i], i});
        }
        sort(num1idx.begin(), num1idx.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, long long> mp;
        long long sum = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            int index = num1idx[i].second;
        
        while(j < i){
            int prev = num1idx[j].second;
            if(num1idx[j].first >= num1idx[i].first) break;
            pq.push(nums2[prev]);
            sum += nums2[prev];
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            j++;
        }
        mp[index] = sum;
    }
    for(int i=0; i<n; i++){
        ans[i] = mp[i];
    }
    return ans;
}
};
