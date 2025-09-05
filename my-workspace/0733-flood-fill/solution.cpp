class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int stcolor){
        image[sr][sc] = color;
        int d1[4] = {1, 0, -1, 0};
        int d2[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int dr = sr + d1[i];
            int dc = sc + d2[i];
            if(dr >= 0 && dc >= 0 && dr < image.size() && dc < image[0].size()){
                if(image[dr][dc] == stcolor && image[dr][dc] != color){
                    dfs(image, dr, dc, color, stcolor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stcolor = image[sr][sc];
        dfs(image, sr, sc, color, stcolor);
        return image;
    }
};
