/**
 * @file 10_count_set_bit.cpp
 * @author Nirmalya Dhara
 * @brief count the number of set bits in a number
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Calculates the number of set bits in a given integer.
 *
 * @param n The integer for which to count the set bits.
 * @return The number of set bits in the given integer.
 *
 * @note This function uses an optimized approach to count the set bits in the given integer.
 * The time complexity of this approach is O(number of set bits).
 */
int countSetBit(int n)
{
    /* //? Brute force approach:- O(logN)
    int count = 0;
    while (n)
    {
        ///$ Method: 1
        /// count += n % 2;
        /// n /= 2;

        ///$ Method: 2 (Optimized approach of method 1)
        count += n & 1;
        n >>= 1;
    }
    return count; */

    //? Optimized approach:- O(number of set bits)
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;

    /* //? Optimized approach: c++ stl O(1)
    ///$ __builtin_popcount(n) is a c++ stl function which returns the number of set bits in a number n time complexity is O(1)
    return __builtin_popcount(n); */
}
int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Number of set bits in " << n << " is: " << countSetBit(n) << std::endl;
    return 0;
}