#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int l = 1, r = distance;
    int answer = 0;
    
    while(l<=r){
        int cnt = 0;
        int prev = 0;
        
        int mid = (l+r)/2;
        
        for(int i : rocks){
            if(i-prev<mid){
                cnt++;
            }else{
                prev = i;
            }
        }
        if(cnt <= n){
            answer = max(answer, mid);
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return answer;
}