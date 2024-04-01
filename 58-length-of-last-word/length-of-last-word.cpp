class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int size = s.size();
        int count = 0;
        for(int i = 0; i < size; i++){
            if(isspace(s[i]) && count == 0){
                continue;
            }else if(isspace(s[i]) && count > 0){
                return count;
            }else{
                count++;
            }
        }

        return count;
    }
};