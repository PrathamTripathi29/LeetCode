class Solution {
public:
    void f(int sr, int sc, vector<vector<int>>& image, int oriColor, int color, int m, int n){
        image[sr][sc] = color;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        for(int i=0; i<4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                if(image[nr][nc] != color && image[nr][nc] == oriColor){
                    f(nr, nc, image, oriColor, color, m, n);
                }
            }
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oriColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        f(sr, sc, image, oriColor, color, m, n);
        return image;
    }
};
