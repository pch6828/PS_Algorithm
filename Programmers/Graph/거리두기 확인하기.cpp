#include <string>
#include <vector>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool one_or_two_hop(vector<string>& place, int x, int y){
    for(int i = 0; i < 4; i++){
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx>=0&&tx<place.size()&&ty>=0&&ty<place[0].size()){
            if(place[tx][ty]=='P'){
                return true;
            }else if(place[tx][ty]=='X'){
                continue;
            }else{
                for(int j = 0; j < 4; j++){
                    int ttx = tx+dx[j];
                    int tty = ty+dy[j];
                    if(ttx>=0&&ttx<place.size()&&tty>=0&&tty<place[0].size()&&(x!=ttx||y!=tty)&&place[ttx][tty]=='P'){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int is_isolated(vector<string>& place){
    for(int i = 0; i < place.size(); i++){
        for(int j = 0; j < place[i].size(); j++){
            if(place[i][j]=='P'){
                if(one_or_two_hop(place, i, j)){
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& place : places){
        answer.push_back(is_isolated(place));
    }
    return answer;
}