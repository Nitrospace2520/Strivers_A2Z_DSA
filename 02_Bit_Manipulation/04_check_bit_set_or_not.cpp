/**
 * @file 04_check_bit_set_or_not.cpp
 * @author Nirmalya Dhara
 * @brief check whether a bit is set or not
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Function: checkIthBit
 * ---------------------
 * Determines whether the i-th bit of a given number is set or not.
 *
 * @param n: the number to check the i-th bit of
 * @param pos: the position of the i-th bit (starting index 0)
 * @return: true if the i-th bit is set, false otherwise
 */
bool checkIthBit(int n, int pos)
{
    /* // ? Approach-01 (using bitset) and reverse the string
    std::string binary = std::bitset<32>(n).to_string();
    return binary[32 - pos - 1] == '1';
     */

    // ? Approach-02 (using left shift)
    // return (n & (1 << pos)) != 0;

    // ? Approach-03 (using right shift)
    //$ (n >> pos) will give 0 or 1 (if the bit is set or not
    return (n >> pos) & 1;
}

int main()
{
    int n, pos;
    std::cout << "Enter a number and the position of the i-th bit (starting index 0): ";
    std::cin >> n >> pos;

    std::cout << "The " << pos << "-th bit is: " << (checkIthBit(n, pos) ? "" : "not ") << "set" << std::endl;
    return 0;
}