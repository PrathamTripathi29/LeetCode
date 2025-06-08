class Solution {
    public boolean check(int[] nums, int k, int val){
        int[] temp = nums.clone();
        for(int i=0; i< nums.length -1; i++){
            if(temp[i] != val){
                temp[i] = -temp[i];
                temp[i+1] = -temp[i+1];
                k--;
            }
            if(k<0){
                return false;
            }
        }
        if(temp[temp.length-1] == val){
            return true;
        }
        return false;
    }
    public boolean canMakeEqual(int[] nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }
}
