/**
 * @file 06_clear_ith_bit.cpp
 * @author Nirmalya Dhara
 * @brief clear the i-th bit of a number means set the i-th bit to 0
 * @date 2024-04-14
 */
#include <bits/stdc++.h>

/**
 * Function: clearIthBit
 * ---------------------
 * Clears the i-th bit of a given number.
 *
 * @param n: The number to clear the i-th bit from.
 * @param pos: The position of the i-th bit (starting index 0).
 * @return: The number after clearing the i-th bit.
 */
int clearIthBit(int n, int pos)
{
    /* //? Brute force approach: O(logN) time complexity, (N = number of bits in the number)
    ///$ at first convert the number to binary string and then set the i-th bit to 0
    std::string binary = std::bitset<32>(n).to_string();
    binary[32 - pos - 1] = '0';
    return std::bitset<32>(binary).to_ulong(); */

    //? Approach-02 (using left shift) O(1) time complexity
    return n & ~(1 << pos);
}
int main()
{
    int n, pos;
    std::cout << "Enter a number and the position of the i-th bit (starting index 0): ";
    std::cin >> n >> pos;

    std::cout << "The number before clearing the " << pos << "-th bit: " << n << std::endl;
    std::cout << "The number after clearing the " << pos << "-th bit: " << clearIthBit(n, pos) << std::endl;
    return 0;
}