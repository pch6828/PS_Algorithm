class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0]-'a';
        int y = coordinates[1]-'0';
        
        return x%2==y%2;
    }
};