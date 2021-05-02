class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double sqr = myPow(x, n/2);
        if(n%2){
            if(n<0){
                return sqr*sqr/x;
            }
            return sqr*sqr*x;
        }else{
            return sqr*sqr;
        }
    }
};