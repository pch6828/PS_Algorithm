class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int x = 0, y1 = 0, y2 = mat.size()-1;
        int diagonal1 = 0, diagonal2 = 0, center = mat.size()%2?mat[mat.size()/2][mat.size()/2]:0;
        while(x<mat.size()){
            diagonal1 += mat[x][y1];
            diagonal2 += mat[x][y2];
            x++;
            y1++;
            y2--;
        }
        return diagonal1+diagonal2-center;
    }
};