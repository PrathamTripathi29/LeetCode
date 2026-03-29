class EventManager {
    private: map<int, int> mp;
    private: priority_queue<pair<int, int>> pq;
public:
    EventManager(vector<vector<int>>& events) {
        for(int i=0; i<events.size(); i++){
            int eventId = events[i][0];
            int priority = events[i][1];
            mp[eventId] = priority;
            pq.push({priority, -eventId});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [priority, eventId] = pq.top();
            eventId = -eventId;
            pq.pop();
            if(mp.count(eventId) && mp[eventId] == priority){
                mp.erase(eventId);
                return eventId;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
