class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        long long maxmilestone = 0;
        for(int i=0; i<milestones.size(); i++){
            sum += milestones[i];
            if(milestones[i] > maxmilestone){
                maxmilestone = milestones[i];
            }
        }

        if(maxmilestone <= sum - maxmilestone){
            return sum;
        }
        return 2*(sum-maxmilestone) + 1;
    }
};
