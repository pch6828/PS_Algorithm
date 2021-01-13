using namespace std;

typedef long long ll;

long long gcd(long long a, long long b){
    if(a%b==0){
        return b;
    }
    return gcd(b, a%b);
}

long long solution(int w,int h) {
    ll area = (long long)w * (long long)h;
    
    ll g = gcd(w, h);
    return area - (w + h - g);
}