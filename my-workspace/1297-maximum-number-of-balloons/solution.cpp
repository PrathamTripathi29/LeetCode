class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        mp['b'] = 0;
        mp['a'] = 0;
        mp['l'] = 0;
        mp['o'] = 0;
        mp['n'] = 0;
        for(char ch : text){
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n'){
                mp[ch]++;
            }
        }
        mp['l'] = mp['l']/2;
        mp['o'] = mp['o']/2;
        return min({mp['b'], mp['a'], mp['l'], mp['o'], mp['n']});
    }
};
