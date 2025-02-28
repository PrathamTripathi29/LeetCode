class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        int nsize = needle.length();
        string temp = "";
        i=0;
        j = nsize-1;
        if(needle.length() > haystack.length()){
            return -1;
        }
        while(j < haystack.length()){
            int index = i;
            while(index <= j){
                temp += haystack[index];
                index++;
            }
            if(temp == needle){
                return i;
            }
            else{
                temp = "";
                i++;
                j++;
            }
        }
        return -1;
    }
};
