class Solution {
public:
    bool isPrime(long long n){
        if (n <= 1) return false;        
        if (n <= 3) return true;         

        if (n % 2 == 0 || n % 3 == 0) return false;

        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long sum = 0;
        priority_queue<long long> maxheap;
        unordered_set<long long> present;
        for(int i = 1; i<=s.length(); i++){
            for(int j=0; (j+i) <= s.length(); j++){
                string str = s.substr(j, i);
                long long val = stoll(str);
                if(isPrime(val) && present.find(val) == present.end()){
                    maxheap.push(val);
                    present.insert(val);
                }
            }
        }
        int i=0;
        while(!maxheap.empty() && i<3){
            sum += maxheap.top();
            maxheap.pop();
            i++;
        }
        return sum;
    }
};
