/**
 * @file 08_remove_last_set_bit.cpp
 * @author Nirmalya Dhara
 * @brief set the last set bit of a number to 0. Example: 12 (1100) -> 8 (1000)
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Removes the last set bit from a given number.
 *
 * @param n The number from which to remove the last set bit.
 * @return The number after removing the last set bit.
 */
int removeLastSetBit(int n)
{
    /* //? Bruteforce approach: O(n)
    ///$ transform the number to binary and remove the last set bit
    std::string binary = std::bitset<32>(n).to_string();
    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            binary[i] = '0';
            break;
        }
    }
    return std::stoi(binary, 0, 2); */

    //? Optimized approach: O(1)
    ///$ remove the last set bit by using the formula: n & (n-1)
    return n & (n - 1);
}
int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Number before removing last set bit: " << n << std::endl;
    std::cout << "Number after removing last set bit: " << removeLastSetBit(n) << std::endl;
    return 0;
}