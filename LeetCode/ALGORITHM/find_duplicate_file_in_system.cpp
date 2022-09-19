class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>>content_filename_map;
        
        for(auto& path: paths){
            istringstream sin(path);
            string dir, filename;
            sin>>dir;
            
            while(sin>>filename){
                for(int i = 0; i < filename.size(); i++){
                    if(filename[i]=='('){
                        content_filename_map[filename.substr(i+1, filename.size()-i-2)].push_back(dir+"/"+filename.substr(0, i));
                    }
                }
            }
        }
        
        vector<vector<string>>ans;
        for(auto& p:content_filename_map){
            if(p.second.size()>=2){
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};