class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        vector<int> zeroes;
        int product = 1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zeroes.push_back(i);
            }
            else{
                product = product*nums[i];
            }
        }
        if(zeroes.size() > 1){
            for(int i=0; i<n; i++){
                answer.push_back(0);
            }
            return answer;
        }
        if(zeroes.size() == 1){
            for(int i=0; i<n; i++){
                answer.push_back(0);
            }
            answer[zeroes[0]] = product;
            return answer;
        }
        for(int i=0; i<n; i++){
            float k = pow(nums[i], -1);
            answer.push_back(product*k);
        }
        return answer;
    }
};
