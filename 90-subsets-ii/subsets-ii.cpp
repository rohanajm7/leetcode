class Solution {
public:
    void f(int index, int size, vector<int>& nums, vector<int>& temp, vector<vector<int>>& output){
        output.push_back(temp);

        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i - 1]){
                continue;
            }
            temp.push_back(nums[i]);
            f(i + 1, size, nums, temp, output);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size() - 1;
        vector<vector<int>> output;
        vector<int> temp;


        sort(nums.begin(), nums.end());
        f(0, size, nums, temp, output);
        return output;
    }
};