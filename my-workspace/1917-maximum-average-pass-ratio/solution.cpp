class Solution {
public:
    struct comparator{
        bool operator()(const vector<int> &a, const vector<int> &b) const {
            return (double(a[0]) + 1)/((double)a[1] + 1) - ((double)a[0]/a[1]) < (double(b[0]) + 1)/((double)b[1] + 1) - ((double)b[0]/b[1]);
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, comparator> minheap;
        
        for(auto &cl : classes){
            minheap.push(cl);
        }

        while(extraStudents > 0){
            vector<int> top = minheap.top();
            minheap.pop();
            top[0]++;
            top[1]++;
            minheap.push(top);
            extraStudents--;
        }

        double avgpassratio;
        double totalpassratio = 0;

        while(!minheap.empty()){
            vector<int> v = minheap.top();
            minheap.pop();
            double ratio = (double)v[0]/v[1];
            totalpassratio += ratio;
        }

        avgpassratio = totalpassratio/classes.size();
        return avgpassratio;
    }
};
