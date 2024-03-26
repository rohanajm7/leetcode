class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]]++;
        }

        int m = nums.size()/2;
        for(auto it : hashmap){
            if(it.second > m){
                return it.first;
            }
        }

        return 0;
    }
};