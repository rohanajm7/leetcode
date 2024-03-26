class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> hashmap;
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]]++;
        }

        int m = nums.size()/3;
        for(auto it : hashmap){
            if(it.second > m){
                output.push_back(it.first);
            }
        }

        return output;
    }
};