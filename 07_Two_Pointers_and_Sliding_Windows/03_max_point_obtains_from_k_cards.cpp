/**
 * @file 03_max_point_obtains_from_k_cards.cpp
 * @author Nirmalya Dhara
 * @brief There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints. In one step,`you can take one card from the beginning or from the end of the row`. You have to take exactly k cards. Your score is the sum of the points of the cards you have taken. Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
 * @date 2024-10-21
 */

#include <iostream>

/**
 * Find the maximum points that can be obtained by selecting k cards from the given array of card points.
 *
 * @param cardPoints An array of integers representing the points on each card.
 * @param n The total number of cards available.
 * @param k The number of cards that can be selected.
 * @return The maximum points achievable by selecting k cards.
 */
int find_max_card_points(int cardPoints[], int n, int k)
{
    /* // * Brute Force Approach => Time Complexity: O(N * K)
    int max_points = 0;

    for (int i = n - k; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
            sum += cardPoints[(i + j) % n];

        max_points = std::max(max_points, sum);
    }
    return max_points; */

    // * Optimized Approach => Time Complexity: O(2*K)
    int total_points = 0;
    int left_sum = 0, right_sum = 0;
    for (int i = 0; i < k; i++)
        left_sum += cardPoints[i];

    total_points = left_sum;
    int left = k - 1, right = n - 1;
    while (left >= 0)
    {
        right_sum += cardPoints[right];
        left_sum -= cardPoints[left];
        total_points = std::max(total_points, (left_sum + right_sum));
        left--;
        right--;
    }
    return total_points;
}

int main(int argc, char const *argv[])
{
    int cardPoints[] = {10, 20, 3, 40, 5, 16, 10};
    int k = 3;
    int n = sizeof(cardPoints) / sizeof(cardPoints[0]);

    std::cout << "Maximum Card Points: " << find_max_card_points(cardPoints, n, k) << std::endl;
    return 0;
}
