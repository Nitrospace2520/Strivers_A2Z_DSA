/**
 * @file 11_minimum_bit_flips.cpp
 * @author Nirmalya Dhara
 * @brief minimum bit flips to make the number convert to another target number
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Calculates the minimum number of bit flips required to convert one number to another.
 *
 * @param num The original number.
 * @param target The target number.
 * @return The minimum number of bit flips required.
 *
 * @note This function uses an optimized approach with a time complexity of O(log(num ^ target)).
 */
int minFlips(int num, int target)
{
    /* // ? Brute force approach:  Time complexity: O(log(max(num, target)))
    ///$ convert the number to binary and then convert the target number to binary and check the number of bits that are different
    std::string num_bin = std::bitset<32>(num).to_string();
    std::string target_bin = std::bitset<32>(target).to_string();
    int count = 0;
    for (int i = std::max(num_bin.size(), target_bin.size()); i >= 0; i--)
        if (num_bin[i] != target_bin[i])
            count++;
    return count; */

    // ? Optimized approach: Time complexity: O(log(num ^ target))
    //$ count the number of set bits in the XOR of the two numbers
    return __builtin_popcount(num ^ target);
}
int main()
{
    int num, target;
    std::cout << "Enter the number and target number: ";
    std::cin >> num >> target;

    std::cout << "Minimum bit flips required to convert " << num << " to " << target << " is: " << minFlips(num, target) << std::endl;
    return 0;
}