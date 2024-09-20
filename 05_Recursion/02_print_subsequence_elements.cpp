/**
 * @file 02_print_subsequence_elements.cpp
 * @author Nirmalya Dhara
 * @brief print all the subsequence elements of an array
 * @date 2024-09-01
 */
#include <bits/stdc++.h>

/**
 * Recursively prints all possible subsequences of the given array.
 *
 * @param arr The input array of integers
 * @param sequence The current subsequence being formed
 * @param index The current index in the array
 */
void print_subsequence_recursion(std::vector<int> &arr, std::vector<int> &sequence, int index)
{
    if (index >= arr.size())
    {
        for (auto &ele : sequence)
        {
            std::cout << ele << " ";
        }
        std::cout << std::endl;
        return;
    }
    sequence.push_back(arr[index]);
    print_subsequence_recursion(arr, sequence, index + 1);
    sequence.pop_back();
    print_subsequence_recursion(arr, sequence, index + 1);
}

/**
 * Print all possible subsequences of the input array using the power set method.
 *
 * @param arr A reference to a vector of integers representing the input array
 */
void print_subsequence_power_set(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                std::cout << arr[j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 3};
    // print_subsequence_power_set(arr);

    std::vector<int> sequence;
    print_subsequence_recursion(arr, sequence, 0);

    return 0;
}