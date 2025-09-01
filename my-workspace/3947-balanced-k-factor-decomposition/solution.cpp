class Solution {
public:
    void f(int n, int k, int start, vector<int> &curr, vector<int> &ans, int &mindiff){
        if(k == 1){
            if(n >= start){
                curr.push_back(n);
                check(curr, ans, mindiff);
                curr.pop_back();
            }
            return;
        }
        for(int i = start; i<=n; i++){
            if(n%i == 0){
                curr.push_back(i);
                f(n/i, k-1, i, curr, ans, mindiff);
                curr.pop_back();
            }
        }
    }

    void check(vector<int> &curr, vector<int> &ans, int &mindiff){
        int mn = *min_element(curr.begin(), curr.end());
        int mx = *max_element(curr.begin(), curr.end());
        if(mx - mn < mindiff){
            mindiff = mx - mn;
            ans = curr;
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> ans;
        vector<int> curr;
        int mindiff = INT_MAX;
        f(n, k, 1, curr, ans, mindiff);
        return ans;
    }
};
