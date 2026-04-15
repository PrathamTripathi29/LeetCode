class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int i = startIndex;
        int j = startIndex;
        int dist1 = 0;
        int dist2 = 0;
        while(dist1 <= n/2 || dist2 <= n/2){
            if(words[i] == target) return dist1;
            if(words[j] == target) return dist2;
            i = (i-1+n)%n;
            j = (j+1)%n;
            dist1++;
            dist2++;
        }
        return -1;
    }
};
