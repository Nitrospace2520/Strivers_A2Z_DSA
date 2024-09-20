/**
 * @file 03_print_subsequence_whose_sum_is_k.cpp
 * @author Nirmalya Dhara
 * @brief print the subsequence elements of an array whose sum is equal to k
 * @date 2024-09-20
 */

#include <bits/stdc++.h>

/**
 * Recursively prints all possible subsequences of the given array whose sum is equal to k.
 *
 * @param arr The input array of integers
 * @param sequence The current subsequence being formed
 * @param index The current index in the array
 * @param k The sum to be checked
 */
void print_all_subsequence_sum_k(std::vector<int> &arr, std::vector<int> &sequence, int index, int k, std::vector<std::vector<int>> &res)
{
    /* //? Bruteforce approach: O(N * 2^N)
    if (index >= arr.size())
    {
        int sum = 0;
        for (auto &ele : sequence)
            sum += ele;

        if (sum == k)
            res.push_back(sequence);

        return;
    }
    sequence.push_back(arr[index]);
    print_all_subsequence_sum_k(arr, sequence, index + 1, k, res);
    sequence.pop_back();
    print_all_subsequence_sum_k(arr, sequence, index + 1, k, res); */

    //? Better approach: O(2^N)
    if (k < 0)
        return;
    if (k == 0)
    {
        res.push_back(sequence);
        return;
    }
    if (index >= arr.size())
    {
        return;
    }
    sequence.push_back(arr[index]);
    print_all_subsequence_sum_k(arr, sequence, index + 1, k - arr[index], res);
    sequence.pop_back();
    print_all_subsequence_sum_k(arr, sequence, index + 1, k, res);
}

/**
 * Recursively finds a subsequence in the given array 'arr' whose elements sum up to 'k'.
 *
 * @param arr The input array of integers
 * @param sequence The current subsequence being considered
 * @param index The current index in the array 'arr'
 * @param k The target sum to achieve
 * @param res The resultant subsequence that sums up to 'k'
 * @return True if a subsequence with sum 'k' is found, false otherwise
 */
bool print_any_subsequence_sum_k(std::vector<int> &arr, std::vector<int> &sequence, int index, int k, std::vector<int> &res)
{
    if (k < 0)
        return false;
    if (k == 0)
    {
        res = sequence;
        return true;
    }
    if (index >= arr.size())
        return false;

    sequence.push_back(arr[index]);
    if (print_any_subsequence_sum_k(arr, sequence, index + 1, k - arr[index], res))
        return true;

    sequence.pop_back();
    if (print_any_subsequence_sum_k(arr, sequence, index + 1, k, res))
        return true;

    return false;
}

int count_subsequence_sum_k(std::vector<int> &arr, int index, int k)
{
    if (k < 0)
        return 0;
    if (k == 0)
        return 1;
    if (index >= arr.size())
        return 0;

    int left = count_subsequence_sum_k(arr, index + 1, k - arr[index]);
    int right = count_subsequence_sum_k(arr, index + 1, k);

    return left + right;
}
int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k = 10;

    /*  //? Print all subsequence whose sum is k
    std::vector<std::vector<int>> res;
    std::vector<int> sequence;
    print_all_subsequence_sum_k(arr, sequence, 0, k, res);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            std::cout << res[i][j] << " ";
        std::cout << std::endl;
    } */

    /* //? Print any subsequence whose sum is k
    std::vector<int> res;
    std::vector<int> sequence;
    print_any_subsequence_sum_k(arr, sequence, 0, k, res);

    for (int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
    std::cout << std::endl; */

    //? Count the number of subsequences whose sum is k
    std::cout << count_subsequence_sum_k(arr, 0, k) << std::endl;

    return 0;
}