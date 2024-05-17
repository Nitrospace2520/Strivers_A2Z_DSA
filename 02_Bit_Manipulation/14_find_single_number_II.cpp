/**
 * @file 14_find_single_number_II.cpp
 * @author Nirmalya Dhara
 * @brief find the single number in an array that appears exactly once, while all other numbers appear three times.
 * @date 2024-04-16
 */
#include <bits/stdc++.h>

/**
 * Finds the single number in the array that appears exactly once, while all other numbers appear three times.
 *
 * @param arr The input array of integers.
 * @return The single number that appears exactly once.
 *
 * @note This function uses the optimized approach of bit manipulation and bucket concepts.
 *       The time complexity is O(n) and the space complexity is O(1) as we are using only 2 variables.
 */
int findSingleNumber(std::vector<int> &arr)
{
    /* // ? Bruteforce approach: (sorting the array and then checking the number). Time complexity: O(nlogn)
    std::sort(arr.begin(), arr.end());
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[arr.size() - 1] != arr[arr.size() - 2])
        return arr[arr.size() - 1];

    for (int i = 1; i < arr.size() - 1; i++)
        if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1])
            return arr[i];

    return -1; */

    /* // ? Better approach: (using hash map). Time complexity: O(n), Space complexity: O(n)
    std::unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
        mp[arr[i]]++;

    for (auto it : mp)
    {
        if (it.second == 1)
            return it.first;
    }
    return -1; */

    /* // ? Better approach: (using bit manipulation). Time complexity: O(32 * n), Space complexity: O(1)
    /// $ The idea is to count the number of 1's at each bit position in the array. If the count is not a multiple of 3, then the single number will have that bit set.
    int singleNumber = 0;
    for (int bitIdx = 0; bitIdx < 32; bitIdx++)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] & (1 << bitIdx))
                count++;
        }
        if (count % 3)
            singleNumber |= (1 << bitIdx);
    }
    return singleNumber; */

    /* // ? Optimized approach of Brute force: (using sorting and then checking the number). Time complexity: O(nlogn) and Space complexity: O(1)
    /// $ note: logN < 32 as the array size can be at most 10^4 and 2^15 < 10^4 < 2^16.
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i += 3)
    {
        if (arr[i] != arr[i - 1])
            return arr[i - 1];
    }
    return arr[arr.size() - 1]; */

    // ? Optimized approach of Bit manipulation: (using bit manipulation and bucket concepts). Time complexity: O(n) and Space complexity: O(1) as we are using only 2 variables.
    int ones = 0, twos = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ones = (ones ^ arr[i]) & ~twos;
        twos = (twos ^ arr[i]) & ~ones;
    }
    return ones;
}
int main()
{
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "the single number in the array that appears exactly once, while all other numbers appear three times is: " << findSingleNumber(arr) << std::endl;
    return 0;
}