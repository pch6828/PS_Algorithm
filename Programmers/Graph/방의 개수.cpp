#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> arrows) {
    set<pair<int, int>>pos;
    set<pair<pair<int, int>, pair<int, int>>>path;
    int answer = 0;
    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {1,1,0,-1,-1,-1,0,1};
    int x = 0, y = 0;
    pos.insert({x,y});
    for(int i : arrows){
        int px = x;
        int py = y;
        x+=dx[i];
        y+=dy[i];
        if(pos.count({x, y})&&!path.count({{px, py},{x, y}})){
            answer++;
        }
        if((i==1||i==3||i==5||i==7)&&!path.count({{px, py},{x, y}})&&(path.count({{px, y},{x, py}})||path.count({{x, py},{px, y}}))){
            answer++;
        }
        pos.insert({x, y});
        path.insert({{px, py},{x, y}});
        path.insert({{x, y},{px, py}});
    }
    return answer;
}