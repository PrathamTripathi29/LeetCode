class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> reqind;
        int s = 0;
        int l = numbers.size()-1;
        while(l>s){
            if(numbers[s] + numbers[l] == target){
                reqind.push_back(s+1);
                reqind.push_back(l+1);
                return reqind;
            }
            if(numbers[s] + numbers[l] > target){
                l--;
            }
            if(numbers[s] + numbers[l] < target){
                s++;
            }
        }
        return reqind;

    }
};
