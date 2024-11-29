class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int j=0,k=0;
        while(j<m && k<n){
            if(nums1.at(j)<nums2.at(k)){
                nums.push_back(nums1.at(j));
                j++;
            }
            else{
                nums.push_back(nums2.at(k));
                k++;
            }
        }
        while(j<m){
            nums.push_back(nums1.at(j));
            j++;
        }
        while(k<n){
            nums.push_back(nums2.at(k));
            k++;
        }
        for(int i=0; i<(m+n); i++){
            nums1.at(i) = nums.at(i);
        }
    }
};
