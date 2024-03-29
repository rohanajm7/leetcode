class Solution {
public:
    void f(int index, string s, vector<vector<string>>& output, vector<string>& temp){
        if(index == s.size()){
            output.push_back(temp);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(index, i, s)){
                temp.push_back(s.substr(index, i-index+1));
                f(i+1, s, output, temp);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(int start, int end, string s){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> temp;
        f(0, s, output, temp);

        return output;
    }
};