/**
 * @file 02_binary_to_decimal.cpp
 * @author Nirmalya Dhara
 * @brief convert a binary number to decimal number
 * @date 2024-04-14
 */
#include <bits/stdc++.h>

/**
 * Converts a binary number to its decimal representation.
 *
 * @param binary The binary number to be converted.
 * @return The decimal representation of the binary number.
 */
int binaryToDecimal(std::string binary)
{
    /* //? Brue force approach: Time: O(logN).
    ///$ Take the remainder of the number when divided by 10 and add it to the front of the decimal number and then divide the number by 10
    int decimal = 0;
    int base = 1;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += base;
        base <<= 1;
    }
    return decimal; */

    //? Optimal Approach: Using inbuilt function: Time: O(1)
    //$ std::stoi(binary, 0, 2) is used to convert the binary number to decimal number
    return std::stoi(binary, 0, 2);
}
int main()
{
    std::string binary;
    std::cout << "Enter the binary number: ";
    std::cin >> binary;

    std::cout << "Decimal representation of " << binary << " is: ";
    std::cout << binaryToDecimal(binary) << std::endl;
    return 0;
}