/**
 * @file 15_find_single_numbers_III.cpp
 * @author Nirmalya Dhara
 * @brief find the single numbers from an array which has multiple elements occured twice
 * @date 2024-04-17
 */

#include <bits/stdc++.h>

/**
 * @brief Find the single numbers from an array which has multiple elements occurred twice.
 *
 * This function takes an array of integers and its size as input and returns a vector of integers
 * containing the single numbers from the array. The array may contain multiple elements that occur twice,
 * and the function finds and returns the numbers that occur only once.
 *
 * The function uses the optimal approach of bit manipulation to find the single numbers.
 * It performs XOR operation on all the elements of the array, which cancels out the duplicate numbers.
 * The result of XOR operation will be the XOR of the two single numbers.
 *
 * Then, the function finds the rightmost set bit in the XOR result, which will be different for the two single numbers.
 * It uses this bit to divide the array elements into two buckets.
 * The elements with the rightmost set bit as 1 are XORed to find the first single number,
 * and the elements with the rightmost set bit as 0 are XORed to find the second single number.
 *
 * The function returns a vector containing the two single numbers.
 *
 * @param nums An array of integers.
 * @param n The size of the array.
 * @return A vector of integers containing the single numbers.
 *
 * @note The function assumes that the array contains at least two single numbers and all other numbers occur twice.
 * @note The function assumes that the array is not empty.
 * @note The function assumes that the array elements are within the range of integer data type.
 * @note The function assumes that the array elements are non-negative.
 * @note The function assumes that the array elements are distinct, except for the single numbers.
 *
 * @see findSingleElements
 */
std::vector<int> findSingleElements(int nums[], int n)
{
    /* // ? Brute Force Approach: (using sort) Time: O(NlogN), Space: O(1)
    if (n < 1)
        return std::vector<int>();

    std::sort(nums, nums + n);
    std::vector<int> res;
    if (nums[0] != nums[1])
        res.push_back(nums[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
            res.push_back(nums[i]);
    }
    if (n > 2 && nums[n - 1] != nums[n - 2])
        res.push_back(nums[n - 1]);

    return res; */

    /* // ? Better Force Approach: (using Hashmap) Time & Space: O(N)
    std::vector<int> res;
    std::unordered_map<int, int> map;
    for(int i=0; i<n; i++)
        map[nums[i]]++;
    for(auto it : map){
        if(it.second == 1)
            res.push_back(it.first);
    }
    return res; */

    // ? Optimal Approach: (using bit manipulation) Time: O(N), Space: O(1)
    // note: if the xorOp is 2^-31 the xorOP-1 creates overflow as it will be 2^-31 -1. Therefore you should take xorOp as long type.
    long xorOp = 0;
    for (int i = 0; i < n; i++)
        xorOp = xorOp ^ nums[i];

    int rightMostSetBit = (xorOp & (xorOp - 1)) ^ xorOp;
    int bucket1 = 0, bucket2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (rightMostSetBit & nums[i])
            bucket1 = bucket1 ^ nums[i];
        else
            bucket2 = bucket2 ^ nums[i];
    }
    return std::vector<int>{bucket1, bucket2};
}

int main()
{
    int n;
    std::cout << "Enter size of the array: ";
    std::cin >> n;

    int nums[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    std::cout << "The single numbers are: ";
    std::vector<int> singleElement = findSingleElements(nums, n);

    for (auto num : singleElement)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}