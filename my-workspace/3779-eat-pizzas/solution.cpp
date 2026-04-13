class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        int days = n/4;
        long long ans = 0;
        int odd = (days+1)/2;
        int even = days/2;
        sort(pizzas.rbegin(), pizzas.rend());
        int idx = 0;
        for(int i=0; i<odd; i++){
            ans += pizzas[idx];
            idx++;
        }
        idx++;
        for(int i=0; i<even; i++){
            ans += pizzas[idx];
            idx += 2;
        }
        return ans;
    }
};
