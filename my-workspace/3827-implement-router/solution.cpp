class Router {
public:
    map <vector<int>, int> mp;
    queue<vector<int>> q;
    unordered_map<int, vector<int>> timestamps;
    unordered_map<int,int> fororrem;
    int size = 0;
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> pack = {source, destination, timestamp};
        if(mp.count(pack)){
            return false;
        }
        if(q.size() == size){
            fororrem[q.front()[1]]++;
            mp.erase(q.front());
            q.pop();
        }
        q.push(pack);
        mp[pack]++;
        timestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {};
        }
        vector<int> res = q.front();
        q.pop();
        mp.erase(res);
        fororrem[res[1]]++;
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(timestamps.find(destination) == timestamps.end()){
            return 0;
        }
        auto &p = timestamps[destination];
        int temp = fororrem[destination];
        auto right = lower_bound(p.begin() + temp, p.end(), startTime);
        auto left = upper_bound(p.begin() + temp, p.end(), endTime);
        return int(left-right);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
