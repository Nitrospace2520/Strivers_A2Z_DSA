/**
 * @file 12_power_set.cpp
 * @author Nirmalya Dhara
 * @brief Generate the power set of a given set. The power set of a set is the set of all possible subsets of the set. For example, the power set of {1, 2} is {{}, {1}, {2}, {1, 2}}. The power set of a set with n elements has 2^n elements. For example, the power set of {1, 2, 3} is {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Generates the power set of a given set.
 *
 * This function takes an array of integers and its size as input and returns the power set of the given set.
 * The power set is a set that contains all possible subsets of the given set, including the empty set and the set itself.
 *
 * Parameters:
 * @param arr: A pointer to an array of integers representing the set.
 * @param n: An integer representing the size of the set.
 *
 * @return A vector of vectors of integers representing the power set of the given set.
 *
 * @note
 * Time Complexity:
 * The time complexity of this function is O(n * 2^n), where n is the size of the set.
 *
 * Space Complexity:
 * The space complexity of this function is O(n * 2^n), where n is the size of the set.
 *
 * @example
 * Example:
 * int arr[] = {1, 2, 3};
 * int n = sizeof(arr) / sizeof(arr[0]);
 * std::vector<std::vector<int>> power_set = generatePowerSet(arr, n);
 * power_set = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}
 */
std::vector<std::vector<int>> generatePowerSet(int *arr, int n)
{
    /* // ? Recursive Approach : Time complexity: O(n * 2^n), Space complexity: O(n * 2^n)
    std::vector<std::vector<int>> power_set;
    if (n == 0)
    {
        power_set.push_back({});
        return power_set;
    }
    int element = arr[0];
    std::vector<std::vector<int>> sub_power_set = generatePowerSet(arr + 1, n - 1);
    for (int i = 0; i < sub_power_set.size(); i++)
    {
        std::vector<int> temp = sub_power_set[i];
        power_set.push_back(temp);
        temp.push_back(element);
        power_set.push_back(temp);
    }
    return power_set; */

    // ? Iterative Approach : Time complexity: O(n * 2^n), Space complexity: O(n * 2^n) using bit manipulation
    std::vector<std::vector<int>> power_set;
    for (int num = 0; num < (1 << n); num++)
    {
        std::vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
                temp.push_back(arr[i]);
        }
        power_set.push_back(temp);
    }
    return power_set;
}
int main()
{
    int n;
    std::cout << "Enter the number of elements in the set: ";
    std::cin >> n;
    int *arr = new int[n];
    std::cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::cout << "The power set of the given set is: " << std::endl;
    std::vector<std::vector<int>> power_set = generatePowerSet(arr, n);

    // * Printing the power set:
    for (int i = 0; i < power_set.size(); i++)
    {
        std::cout << "{";
        for (int j = 0; j < power_set[i].size(); j++)
            std::cout << power_set[i][j] << (j == power_set[i].size() - 1 ? "" : ", ");
        std::cout << "}" << std::endl;
    }

    delete[] arr;
    return 0;
}