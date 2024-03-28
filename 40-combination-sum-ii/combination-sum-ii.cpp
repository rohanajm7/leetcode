class Solution {
public:
    void f(int index, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& output){
        if(target == 0){
            output.push_back(temp);
        }

        for(int i = index; i < candidates.size(); i++){
            if(i != index && candidates[i] == candidates[i - 1]){
                continue;
            }

            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            f(i + 1, target - candidates[i], candidates, temp, output);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        f(0, target, candidates, temp, output);

        return output;
    }
};