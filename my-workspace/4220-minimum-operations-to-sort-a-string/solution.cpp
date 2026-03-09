class Solution {
public:
    int minOperations(string s) {
        char mini, maxi;
        mini = 127;
        maxi = 0;
        int n = s.length();
        if(is_sorted(s.begin(), s.end())) return 0;
        if(n == 2) return -1;
        for(int i=1; i<n-1; i++){
            char ch = s[i];
            mini = min(mini, ch);
            maxi = max(maxi, ch);
        }
        if(s[0] <= s[n-1] && (mini >= s[0] || maxi <= s[n-1])) return 1;
        if(s[0] > maxi && s[n-1] < mini) return 3;
        return 2; 
    }
};
