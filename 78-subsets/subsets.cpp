class Solution {
public:
    void f(int index, int size, vector<int>& nums, vector<int>& temp, vector<vector<int>>& output){
        if(index > size){
            output.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        f(index+1, size, nums, temp, output);
        temp.pop_back();
        f(index+1, size, nums, temp, output);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size() - 1;
        vector<vector<int>> output;
        vector<int> temp;
        f(0, size, nums, temp, output);
        return output;
    }
};