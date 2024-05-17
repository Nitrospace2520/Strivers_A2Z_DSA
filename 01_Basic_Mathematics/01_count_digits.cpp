/**
 * @file 01_count_digits.cpp
 * @author Nirmalya Dhra
 * @brief count the number of digits in a number
 * @date 2024-03-10
 */

#include <iostream>
#include <cmath>

/**
 * Counts the number of digits in an integer.
 * @param n The integer to count the digits of.
 * @return The number of digits in the integer.
 */
int countDigits(int n)
{
    int count = 0;

    // ? Approach 1: Using while loop to divide by 10, Time complexity: O(log10(n))
    // while (n > 0)
    // {
    //     n = n / 10;
    //     count++;
    // }

    // ? Approach 2: Using log10 function, Time complexity: O(1)
    // count = (int)log10(n) + 1;

    // ? Approach 3: Using string conversion, Time complexity: O(1)
    std::string str = std::to_string(n);
    count = str.length();

    return count;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int count = countDigits(n);
    std::cout << "Number of digits: " << count << std::endl;

    return 0;
}