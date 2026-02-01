class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        int riderId, driverId;
        if(riders.empty() || drivers.empty()){
            return {-1, -1};
        }
        riderId = riders.front();
        driverId = drivers.front();
        riders.pop();
        drivers.pop();
        return {driverId, riderId};
    }
    
    void cancelRider(int riderId) {
        queue<int> temp;
        while(!riders.empty()){
            int rider = riders.front();
            riders.pop();
            if(rider == riderId){
                continue;
            }
            temp.push(rider);
        }
        riders = temp;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
