#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    string head, filename;
    int number, idx;
}File;

bool compare(File& a, File& b){
    if(a.head==b.head){
        if(a.number==b.number){
            return a.idx<b.idx;
        }
        return a.number<b.number;
    }
    return a.head<b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File>file;
    for(int i = 0; i < files.size(); i++){
        string& filename = files[i];
        File temp;
        temp.filename = filename;
        int idx = 0;
        while(!(filename[idx]>='0'&&filename[idx]<='9')){
            if(filename[idx]>='a'&&filename[idx]<='z'){
                temp.head.push_back(filename[idx]-32);
            }else{
                temp.head.push_back(filename[idx]);
            }
            idx++;
        }
        temp.number = 0;
        while(idx<filename.size()&&filename[idx]>='0'&&filename[idx]<='9'){
            temp.number*=10;
            temp.number+=filename[idx]-'0';
            idx++;
        }
        temp.idx = i;
        file.push_back(temp);
    }
    sort(file.begin(), file.end(), compare);
    for(auto f : file){
        answer.push_back(f.filename);
    }
    return answer;
}