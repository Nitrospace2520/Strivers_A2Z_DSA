/**
 * @file 02_reverse_number.cpp
 * @author Nirmalya Dhara
 * @brief reverse a number
 * @date 2024-03-10
 */

#include <iostream>

/**
 * Reverses the given number.
 * @param n The number to be reversed.
 * @return The reversed number.
 */
int reverseNumber(int n)
{
    int reverse = 0;

    // ? Approach 1: Using while loop to extract last digit and multiply by 10, Time complexity: O(log10(n))
    // while (n > 0)
    // {
    //     int last_digit = n % 10;
    //     reverse = reverse * 10 + last_digit;
    //     n = n / 10;
    // }

    // ? Approach 2: Using string conversion, Time complexity: O(1)
    std::string str = std::to_string(n);
    std::string reversed_str = std::string(str.rbegin(), str.rend());
    reverse = std::stoi(reversed_str);

    return reverse;
}

/**
 * @brief The main function of the program.
 *
 * This function takes user input for a number, calls the reverseNumber function to reverse the number,
 * and then prints the reversed number to the console.
 *
 * @return int Returns 0 to indicate successful execution of the program.
 */
int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int reverse = reverseNumber(n);

    std::cout << "Reversed number: " << reverse << std::endl;

    return 0;
}