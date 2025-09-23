class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;
        string rev = "";
        for(int i=0; i<version1.length(); i++){
            if(version1[i] == '.'){
                v1.push_back(rev);
                rev = "";
            } else
                rev += version1[i];
        }
        v1.push_back(rev);
        rev = "";
        for(int i=0; i<version2.length(); i++){
            if(version2[i] == '.'){
                v2.push_back(rev);
                rev = "";
            } else
                rev += version2[i];
        }
        v2.push_back(rev);
        int n1 = v1.size();
        int n2 = v2.size();
        while(n1 > n2){
            v2.push_back("0");
            n2++;
        }
        while(n2 > n1){
            v1.push_back("0");
            n1++;
        }
        for(int i=0; i<n1; i++){
            int val1, val2;
            val1 = stoi(v1[i]);
            val2 = stoi(v2[i]);
            if(val1 > val2) return 1;
            if(val2 > val1) return -1;
        }
        return 0;
    }
};
