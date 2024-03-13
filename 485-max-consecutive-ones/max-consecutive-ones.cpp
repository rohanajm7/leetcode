class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longest = 0;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                longest++;
                maxi = max(longest, maxi);
            }else{
                longest = 0;
            }
        }

        return maxi;
    }
};