class Solution {
public:
    int maxDifference(string s) {
        int l = s.length();
        vector<char> elements;
        unordered_map<char,int> freq;
        for(int i=0; i<l; i++){
            char a = s[i];
            if(freq.find(a) == freq.end()){
                freq[a] = 1;
                elements.push_back(a);
            }
            else{
                freq[a]++;
            }
        }
        char b = elements[0];
        int oddfreq = INT_MIN;
        int evenfreq = INT_MAX;
        int size = elements.size();
        for(int i=0; i<size; i++){
            char a = elements.at(i);
            if(freq[a]%2 == 0 && freq[a] < evenfreq){
                evenfreq = freq[a];
            }
            if(freq[a]%2 != 0 && freq[a] > oddfreq){
                oddfreq = freq[a];
            }
        }
        return oddfreq-evenfreq;
    }
};
