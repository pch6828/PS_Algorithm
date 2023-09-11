class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>groupmap;
        vector<vector<int>>group;

        for(int i = 0; i < groupSizes.size(); i++){
            groupmap[groupSizes[i]].push_back(i);
        }
        
        for(auto& p:groupmap){
            int size = p.first;
            vector<int>&people = p.second;

            for(int i = 0; i < people.size(); i+=size){            
                vector<int> temp;
                for(int j = 0; j < size; j++){
                    temp.push_back(people[i+j]);
                }
                group.push_back(temp);
            }
        }

        return group;
    }
};