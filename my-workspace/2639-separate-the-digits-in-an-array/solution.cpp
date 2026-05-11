class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            int num = nums[i];
            while(num>0){
                int dig = num%10;
                num /= 10;
                answer.push_back(dig);
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
