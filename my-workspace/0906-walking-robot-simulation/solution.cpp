class Solution {
public:
    struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<pair<int, int>, int, PairHash> mp;
        for(auto obs : obstacles){
            int x = obs[0];
            int y = obs[1];
            mp[{x, y}] = 1;
        }
        char dir[4] = {'n', 'e', 's', 'w'};
        int currDir = 0;
        int maxDist = 0;
        pair<int, int> pos = {0, 0};
        for(int i=0; i<commands.size(); i++){
            if(commands[i] == -2){
                currDir = (currDir - 1 + 4)%4;
            } else if (commands[i] == -1){
                currDir = (currDir + 1)%4;
            } else {
                char direc = dir[currDir];
                int dist = commands[i];
                if(direc == 'n'){
                    for(int i=0; i<dist; i++){
                        pos.second++;
                        if(mp.find(pos) != mp.end()){
                            pos.second--;
                            maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                            break;
                        }
                        maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                    }
                } else if(direc == 's'){
                    for(int i=0; i<dist; i++){
                        pos.second--;
                        if(mp.find(pos) != mp.end()){
                            pos.second++;
                            maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                            break;
                        }
                        maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                    }
                } else if(direc == 'e'){
                    for(int i=0; i<dist; i++){
                    pos.first++;
                    if(mp.find(pos) != mp.end()){
                        pos.first--;
                        maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                        break;
                    }
                    maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                    }
                } else if(direc == 'w'){
                    for(int i=0; i<dist; i++){
                    pos.first--;
                    if(mp.find(pos) != mp.end()){
                        pos.first++;
                        maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                        break;
                    }
                    maxDist = max(pos.first*pos.first + pos.second*pos.second, maxDist);
                    }
                }
            }
        }
        return maxDist;
    }
};
