class Solution {
public:
    string generateTag(string caption) {
        for(char &c : caption){
            c = tolower(c);
        }
        int first = 1;
        istringstream ss(caption);
        string word;
        string tag = "#";
        while(ss >> word){
            if(first == 1){
                tag += word;
                first++;
            }
            else{
                word[0] = toupper(word[0]);
                tag += word;
            }
        }
        tag = tag.substr(0, 100);
        return tag;
    }
};
