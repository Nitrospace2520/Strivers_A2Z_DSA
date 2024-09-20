/**
 * @file 20_best_time_to_sell_stock.cpp
 * @author Nirmalya Dhara
 * @brief find the maximum profit that can be obtained by buying and selling a stock at most once
 * @date 2024-09-16
 */
#include <iostream>

/**
 * Find the maximum profit that can be achieved by buying and selling a stock.
 *
 * @param prices An array of stock prices
 * @param n The number of elements in the prices array
 * @return The maximum profit that can be achieved
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