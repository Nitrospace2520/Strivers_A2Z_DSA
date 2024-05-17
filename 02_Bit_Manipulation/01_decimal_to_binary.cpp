/**
 * @file 01_decimal_to_binary.cpp
 * @author Nirmalya Dhara
 * @brief convert a decimal number to binary number
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Converts a decimal number to its binary representation.
 *
 * @param n The decimal number to be converted.
 * @return The binary representation of the decimal number.
 *
 * @note This function uses an optimal approach to convert the decimal number to binary.
 *       It utilizes the std::bitset<16> function to convert the decimal number to a binary number of 16 bits.
 *       The resulting binary number is returned as a string.
 *       If leading zeros need to be trimmed, the commented line can be used instead.
 *       The time complexity of this function is O(1).
 */
std::string convertToBinary(int n)
{
    /* //? Brue force approach: Time: O(logN).
    ///$ Take the remainder of the number when divided by 2 and add it to the front of the binary string and then divide the number by 2
    std::string binary = "";
    while (n > 0)
    {
        binary = std::to_string(n % 2) + binary;
        n = n / 2;
    }
    return binary; */

    //? Optimal Approach: Using inbuilt function: Time: O(1)
    return std::bitset<16>(n).to_string(); //* std::bitset<16>(n) is used to convert the decimal number to binary number of 16 bits
    // return std::to_string(std::stoi(std::bitset<16>(n).to_string())); //* for trimming the leading zeros
}
int main()
{
    int n;
    std::cout << "Enter the decimal number: ";
    std::cin >> n;

    std::cout << "Binary representation of " << n << " is: ";
    std::cout << convertToBinary(n) << std::endl;
    return 0;
}