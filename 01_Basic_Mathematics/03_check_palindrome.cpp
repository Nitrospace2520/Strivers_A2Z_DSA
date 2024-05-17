/**
 * @file 03_check_palindrome.cpp
 * @author Nirmalya Dhara
 * @brief Check if a number is a palindrome
 * @date 2024-04-01
 */

#include <iostream>
#include <string>

/**
 * Check if a given number is a palindrome.
 *
 * @param n The number to check.
 * @return True if the number is a palindrome, false otherwise.
 *
 * @note A number is considered a palindrome if it remains the same when its digits are reversed.
 *       This function uses an optimal approach by converting the number to a string and checking if the string is equal to its reverse.
 *       The time complexity of this approach is O(1).
 */
bool isPalindrome(int n)
{
    /*
    ///? Brute force approach: Reverse the number and check if it is equal to the original number or not using while loop. Time complexity: O(log10(n))
    int reversed = 0;
    int original = n;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed; */

    //? Optimal approach: Convert the number to a string and check if the string is equal to its reverse. Time complexity: O(1)
    std::string str = std::to_string(n);
    std::string reversed_str = std::string(str.rbegin(), str.rend());
    return str == reversed_str;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (isPalindrome(n))
    {
        std::cout << n << " is a palindrome." << std::endl;
    }
    else
    {
        std::cout << n << " is not a palindrome." << std::endl;
    }

    return 0;
}