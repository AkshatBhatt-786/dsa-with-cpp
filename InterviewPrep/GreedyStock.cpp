#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:

    /*
    // Greedy Brute Force
    // T(n) = O(n*n)
    // S(n) = O(1)
    
    int maxProfit(int prices[], int n)
    {
        int maxProfit = 0;

        for (int buy = 0; buy < n; buy++)
        {
            for (int sell = buy + 1; sell < n; sell++)
            {
                int profit = prices[sell] - prices[buy];
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
    */

    /*
    int maxProfit(int prices[], int n)
    {
        int minPrice = prices[0];
        int maxPrice = 0;

        for(int i=0; i<n; i++)
        {
            int profit = prices[i] - minPrice;
            maxPrice = max(maxPrice, profit);
            minPrice = min(minPrice, prices[i]);
        }
        return maxPrice;
    }
    */
   
    int maxProfit(int prices[], int n)
    {
        if (n <= 1) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; i++)
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};

int main()
{
    Solution sol;
    int prices[5] = {1, 3, 5, 9, 10};

    cout << "Max profit: " << sol.maxProfit(prices, 5);

    return 0;
}
