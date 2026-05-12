class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int ia = 0;
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int ce = 0;
        for(vector<int>& task : tasks){
            if(ce < task[1]){
                int diff = task[1] - ce;
                ia += diff;
                ce = task[1];
            }
            ce -= task[0];
        }
        return ia;
    }
};
