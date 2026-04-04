class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n/rows;
        string originalText;
        int r=0;
        int c=0;
        int oriIdx = 0;
        int currIdx = 0;
        while(c < cols){
            while(currIdx < n){
                originalText.push_back(encodedText[currIdx]);
                currIdx += (cols+1);
            }
            currIdx = oriIdx+1;
            oriIdx++;
            c++;
        }
        originalText.erase(originalText.find_last_not_of(" \t\n\r\f\v") + 1);
        return originalText;
    }
};
