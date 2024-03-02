class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int maxprofit = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minimum){
                minimum = prices[i];
            }

            maxprofit = max(prices[i] - minimum, maxprofit);
        }

        return maxprofit;
    }
};