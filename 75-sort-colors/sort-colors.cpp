class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> frequency(4, 0);
        vector<int> output(nums.size());
        for(int i = 0; i < nums.size(); i++){
            frequency[nums[i]]++;
        }

        int zeroes = frequency[0];
        int ones = frequency[1];
        int twos = frequency[2];

        for(int i = 0; i < zeroes; i++){
            nums[i] = 0;
        }
        for(int i = zeroes; i < (zeroes + ones); i++){
            nums[i] = 1;
        }
        for(int i = (zeroes + ones); i < (zeroes + ones + twos); i++){
            nums[i] = 2;
        }
    }
};