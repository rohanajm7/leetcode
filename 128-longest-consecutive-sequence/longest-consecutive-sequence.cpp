class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> s;

        int longestStreak = 1;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i] - 1) == s.end()){
                int length = 0;
                while(s.find(nums[i] + length) != s.end()){
                    length++;
                }
                longestStreak = max(length, longestStreak);
            }
        }

        return longestStreak;
    }
};