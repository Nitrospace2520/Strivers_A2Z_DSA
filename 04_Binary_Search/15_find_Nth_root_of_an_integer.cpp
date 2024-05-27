/**
 * @file 15_find_Nth_root_of_an_integer.cpp
 * @author Nirmalya Dhara
 * @brief find the Nth root of an integer without using any library function
 * @date 2024-05-27
 */

#include <bits/stdc++.h>

int power(int num, int root, int mid)
{
    long long ans = 1;
    for (int i = 1; i <= root; i++)
    {
        ans *= num;
        if (ans > mid)
            return -1;
    }
    if (ans == mid)
        return 1;
    return 0;
}

/**
 * @brief Calculate the Nth root of an integer using binary search.
 *
 * This function calculates the Nth root of a given integer using binary search algorithm.
 * It takes two integers as input - the number and the root.
 * If the root is not found, it returns -1.
 *
 * @param num The integer for which the Nth root needs to be calculated.
 * @param root The root value for which the Nth root needs to be calculated.
 * @return int The Nth root of the integer 'num', or -1 if not found.
 */
int find_nth_root(int num, int root)
{
    /* //?> Brute force approach: Time Complexity: O(N) and Space Complexity: O(1)
    if (num == 0 || num == 1)
        return num;

    for (int i = 1; i <= num; i++)
    {
        long long int pow = std::pow(i, root);
        if (num == pow)
            return i;
        else if (num < pow)
            return -1;
    }
    return -1; */

    //?> Optimal Approach (by using Binary Search): Time Complexity: O(log(N)) and Space Complexity: O(1)
    if (num == 0 || num == 1)
        return num;
    int low = 1, high = num;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long int pow = power(mid, root, num);
        if (pow == 1)
            return mid;
        else if (pow == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int num, root;
    std::cout << "Enter the number and n-th root: ";
    std::cin >> num >> root;

    std::cout << "The " << root << "-th root of " << num << " is : " << find_nth_root(num, root) << std::endl;
    return 0;
}
