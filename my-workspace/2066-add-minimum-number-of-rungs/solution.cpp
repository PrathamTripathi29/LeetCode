class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int extrarungs = 0;
        int size = rungs.size();
        int curheight = 0;
        for(int i = 0; i<size; i++){
            if(rungs[i] - curheight > dist){
                extrarungs += (rungs[i] - curheight - 1)/dist; 
                curheight = rungs[i];
            }
            else{
                curheight = rungs[i];
            }
        }
        return extrarungs;
    }
};
