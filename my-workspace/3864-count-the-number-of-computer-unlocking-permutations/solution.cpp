class Solution {
public:
    typedef long long ll;
    int countPermutations(vector<int>& complexity) {
        int min = complexity[0];
        int size = complexity.size();
        int m = 1e9 + 7;
        for(int i=1; i<size; i++){
            if(complexity[i] < min){
                min = complexity[i];
            }
        }
        if(min != complexity[0]){
            return 0;
        }
        int count = 0;
        for(int i=1; i<size; i++){
            (complexity[i] == min) ? ({return 0;}) : ({continue;});
        }
        ll permutations = 1;
        for(int i=1; i<size; i++){
            permutations = (permutations*i) % m;
        }
        return (int)permutations;
    }
};
