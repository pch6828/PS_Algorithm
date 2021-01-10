#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    
    int dir = n-1;
    
    for(int i = 0; i < n; i++){
        answer+=min(name[i]-'A', 26-name[i]+'A');
        int nxt = i+1;
        while(nxt<n&&name[nxt]=='A'){
            nxt++;
        }
        dir = min(dir, i+n-nxt+min(i, n-nxt));
    }
    
    return answer+dir;
}