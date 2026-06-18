class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        for(int i=0; i<n; i++){
            if(s.empty() || asteroids[i] > 0){
                s.push(asteroids[i]);
            } else {
                int incoming = asteroids[i];
                if(s.empty()){
                    s.push(incoming);
                    continue;
                } else if(abs(incoming) < s.top()){
                    continue;
                } else if(abs(incoming) == s.top()){
                    s.pop();
                    continue;
                } else {
                    while(!s.empty() && abs(incoming) > s.top() && s.top() > 0){
                        s.pop();
                    }
                    if(!s.empty() && s.top() == abs(incoming) && s.top() > 0){
                        s.pop();
                        continue;
                    }
                    if(!s.empty() && s.top() > 0 && s.top() > abs(incoming)){
                        continue;
                    }
                    s.push(incoming);
                }
            }
        }
        vector<int> ans;
        while(s.size()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
