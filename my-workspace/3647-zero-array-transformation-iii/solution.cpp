class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> ongoing;
        priority_queue<int, vector<int>, greater<int>> passed;
        int count = 0;

        for(int index=0, k=0; index<nums.size(); index++){
            while(!passed.empty() && passed.top() < index){
                passed.pop();
            }
            while(k<queries.size() && queries[k][0] <= index){
                ongoing.push(queries[k++][1]);
            }
            while(passed.size() <nums[index] && !ongoing.empty() && ongoing.top() >= index){
                passed.push(ongoing.top());
                ongoing.pop();
                count++;
            }
            if(passed.size() < nums[index]){
                return -1;
            }
        }
        return queries.size() - count;
    }
};
