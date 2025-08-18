class Solution {
public:
    double tolerance = 1e-6;
    bool dfs(vector<double> &nums){
        if(nums.size() == 1){
            return fabs(nums[0] - 24) < tolerance;
        }
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;

                vector<double> next;
                for(int k=0; k<n; k++){
                    if(k != i && k != j) next.push_back(nums[k]);
                }
                double a = nums[i], b = nums[j];
                vector<double> results = {a+b, a-b, b-a, a*b};
                if(fabs(b) > 1e-6) results.push_back(a/b);
                if(fabs(a) > 1e-6) results.push_back(b/a);

                for(double val : results){
                    next.push_back(val);
                    if(dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};
