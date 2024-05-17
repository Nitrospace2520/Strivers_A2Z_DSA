/**
 * @file 05_set_ith_bit.cpp
 * @author Nirmalya Dhara
 * @brief set the i-th bit of a number
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Sets the i-th bit of a given number to 1.
 *
 * @param n The number to modify.
 * @param pos The position of the i-th bit (starting index 0).
 * @return The modified number with the i-th bit set to 1.
 */
int setIthBit(int n, int pos)
{
    /* //? Approach-01 (using bitset) (Brute force approach)
    ///$ at first convert the number to binary string and then set the i-th bit to 1
    std::string binary = std::bitset<32>(n).to_string();
    binary[32 - pos - 1] = '1';
    return std::bitset<32>(binary).to_ulong(); */

    //? Approach-02 (using left shift)
    return n | (1 << pos);
}

int main()
{
    int n, pos;
    std::cout << "Enter a number and the position of the i-th bit (starting index 0): ";
    std::cin >> n >> pos;

    std::cout << "The number before setting the " << pos << "-th bit: " << n << std::endl;
    std::cout << "The number after setting the " << pos << "-th bit: " << setIthBit(n, pos) << std::endl;
    return 0;
}