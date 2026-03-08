class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int ans = -1;
        bool flag = true;
        for(int i=n-1; i>=0; i--){
            if(capacity[i] >= itemSize && (flag || capacity[i] <= capacity[ans])){
                ans = i;
                flag = false;
            }
        }
        return ans;
    }
};
