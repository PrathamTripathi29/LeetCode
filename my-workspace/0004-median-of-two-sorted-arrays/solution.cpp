class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int med1, med2, median=0;
        int count = 0, current;
        int size = nums1.size() + nums2.size();
        if(size%2 == 0){
            med1 = (size-1)/2;
            med2 = size/2;
        }
        else{
            med1 = med2 = size/2;
        }
        int i=0, j=0;
        while(count <= med2){
            if(i < nums1.size() && (j>= nums2.size() || nums1[i] <= nums2[j])){
                current = nums1[i];
                i++;
            }
            else{
                current = nums2[j];
                j++;
            }
            if(count == med1){
                median += current;
            }
            if(count == med2){
                median += current;
            }
            count++;
        }
        
        return (double)median/2;
    }
};
