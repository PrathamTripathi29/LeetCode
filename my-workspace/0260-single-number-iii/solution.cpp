class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xr = 0;
        // let a and b be the unique numbers
        for(auto num : nums){
            xr = xr^num;
        }
        //xr is now = a^b
        //if a bit is set in xr, that bit was different in a and b

        xr = xr&(-xr);

        //xr is now the lowest set bit a^b
        //for eg if x = 12, 12&(-12) (1100*0100) = 4(100) -> position 2
        
        vector<int> ans(2, 0);

        //divide nums into two parts, one part has all the numbers that have this bit set, others dont
        // a and b must lie in different parts
        // taking the xor of both these parts separately leaves us with a and b, as others occur twice

        for(auto num : nums){
            if(num&xr){
                ans[0] = ans[0]^num;
            } else {
                ans[1] = ans[1]^num;
            }
        }
        return ans;
    }
};
