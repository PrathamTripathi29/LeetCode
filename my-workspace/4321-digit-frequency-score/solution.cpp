class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10, 0);
        int num = n;
        while(num > 0){
            int d = num%10;
            freq[d]++;
            num /= 10;
        }
        long long score = 0;
        for(int i=0; i<10; i++){
            score += (i*freq[i]);
        }
        return score;
    }
};
