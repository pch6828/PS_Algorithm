class Solution {
public
    void dfs(vectorvectorint& image, int x, int y, int newColor){
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int prevColor = image[x][y];
        image[x][y] = newColor;
        for(int i = 0; i  4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            if(tx=0&&tximage.size()&&ty=0&&tyimage[0].size()&&image[tx][ty]==prevColor){
                dfs(image, tx, ty, newColor);
            }
        }
    }
    
    vectorvectorint floodFill(vectorvectorint& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor){
            dfs(image, sr, sc, newColor);
        }
        return image;
    }
};