/**
 * @file 07_toggle_ith_bit.cpp
 * @author Nirmalya Dhara
 * @brief toggle the ith bit of a number means if the ith bit is 0 then make it 1 and if it is 1 then make it 0
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Toggles the i-th bit of a given number.
 *
 * @param n The number to toggle the bit in.
 * @param pos The position of the i-th bit to toggle (starting index 0).
 * @return The number after toggling the i-th bit.
 */
int toggleIthBit(int n, int pos)
{
    /* //? Brute force approach: O(logN) time complexity, (N = number of bits in the number)
    ///$ at first convert the number to binary string and then toggle the i-th bit
    std::string binary = std::bitset<32>(n).to_string();
    binary[32 - pos - 1] = (binary[32 - pos - 1] == '0') ? '1' : '0';
    return std::bitset<32>(binary).to_ulong(); */

    //? Efficient approach: O(1) time complexity using bitwise XOR operator and left shift operator
    return n ^ (1 << pos);
}

int main()
{
    int n, pos;
    std::cout << "Enter a number and the position of the i-th bit (starting index 0): ";
    std::cin >> n >> pos;

    std::cout << "The number before toggling the " << pos << "-th bit: " << n << std::endl;
    std::cout << "The number after toggling the " << pos << "-th bit: " << toggleIthBit(n, pos) << std::endl;
    return 0;
}