/**
 * @file 04_check_armstrong_number.cpp
 * @author Nirmalya Dhara
 * @brief check if a number is an Armstrong number
 * @date 2024-04-01
 */

#include <iostream>
#include <cmath>

/**
 * Check if a given number is an Armstrong number.
 *
 * An Armstrong number is a number that is equal to the sum of its digits raised to the power of the number of digits.
 *
 * @param n The number to be checked.
 * @return True if the number is an Armstrong number, False otherwise.
 */
bool isArmstrongNumber(int n)
{
    /* //? BruteForce approach: Calculate the number of digits, then extract each digit and raise it to the power of the number of digits and sum them up. Time complexity: O(log10(n))
    int original = n;
    int digits = (int)std::log10(n) + 1;
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += (int)std::pow(digit, digits);
        n /= 10;
    }
    return original == sum; */

    //? Optimal approach: Convert the number to a string and calculate the sum of its digits raised to the power of the number of digits. Time complexity: O(log10(n))
    std::string str = std::to_string(n);
    int sum = 0;
    for (char c : str)
    {
        int digit = c - '0';
        sum += (int)std::pow(digit, str.size());
    }
    return n == sum;
}
int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (isArmstrongNumber(n))
    {
        std::cout << n << " is an Armstrong number." << std::endl;
    }
    else
    {
        std::cout << n << " is not an Armstrong number." << std::endl;
    }

    return 0;
}