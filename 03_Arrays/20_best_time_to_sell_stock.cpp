/**
 * @file 20_best_time_to_sell_stock.cpp
 * @author Nirmalya Dhara
 * @brief find the maximum profit that can be obtained by buying and selling a stock at most once
 * @date 2024-09-16
 */
#include <iostream>

/**
 * Finds the maximum profit that can be obtained by buying and selling a stock once
 *
 * This function implements the solution to the "Best Time to Buy and Sell Stock" problem
 * where you are given an array of prices where prices[i] is the price of a given stock
 * on the ith day.
 *
 * @param prices Array containing daily prices of the stock
 * @param n Length of the prices array
 * @return Maximum profit that can be achieved by buying and selling once
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Example:
 *   Input: prices = [7,1,5,3,6,4], n = 6
 *   Output: 5
 *   Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6)
 */
int find_max_profit(int prices[], int n)
{
    int min_price = prices[0];
    int max_profit = 0;
    for (int i = 1; i < n; i++)
    {
        max_profit = std::max(max_profit, prices[i] - min_price);
        min_price = std::min(min_price, prices[i]);
    }
    return max_profit;
}

int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    std::cout << find_max_profit(prices, n) << std::endl;
    return 0;
}