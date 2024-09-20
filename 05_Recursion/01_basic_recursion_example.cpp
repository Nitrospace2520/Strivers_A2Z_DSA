/**
 * @file 01_basic_recursion_example.cpp
 * @author Nirmalya Dhara
 * @brief In this tutorial, we will learn about recursion in C++ via some basic examples like printing numbers from 1 to n using recursion, calculating factorial of a number using recursion, calculating sum of digits of a number using recursion, calculating power of a number using recursion, calculating nth Fibonacci number using recursion, and calculating GCD of two numbers using recursion.
 * @date 2024-07-27
 */
#include <bits/stdc++.h>

//? Question: 01 (Print Name 3 times using recursion):=
void printName(std::string name, int times = 3)
{
    if (times == 0)
        return;
    std::cout << name << std::endl;
    printName(name, times - 1);
}

//? Question: 02 (Print Numbers from 1 to n using recursion):=
void printNumbers(int n)
{
    if (n == 0)
        return;
    printNumbers(n - 1);
    std::cout << n << " ";
}

//? Question: 03 (Print Numbers from n to 1 using recursion):=
void printNumbersReverse(int n)
{
    if (n == 0)
        return;
    std::cout << n << " ";
    printNumbersReverse(n - 1);
}

//? Question: 04 (Calculate Sum of Numbers from 1 to n using recursion):=
int sumOfNumbers(int n, int sum = 0)
{
    /* //* Approach 1: Using Functional Recursion
    if (n == 0)
        return 0;
    return n + sumOfNumbers(n - 1); */

    //* Approach 2: Using Tail Recursion
    if (n == 0)
        return sum;
    return sumOfNumbers(n - 1, sum + n);
}

//? Question: 05 (Calculate Factorial of a Number using recursion):=
int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

//? Question: 06 (Reverse an Array using recursion):=
void reverseArray(int arr[], int start, int end)
{
    // //* Approach 1:
    // if (start >= end)
    //     return;
    // std::swap(arr[start], arr[end]);
    // reverseArray(arr, start + 1, end - 1);

    //* Approach 2:
    if (start >= (end + 1) / 2)
        return;
    std::swap(arr[start], arr[end - start]);
    reverseArray(arr, start + 1, end);
}

//? Question: 07 (Check if a string is Palindrome or not using recursion):=
bool isPalindrome(std::string str, int start, int end)
{
    /* //* Approach 1:
    if (start >= end)
        return true;
    else if (str[start] != str[end])
        return false;
    return isPalindrome(str, start + 1, end - 1); */

    //* Approach 2:
    if (start >= str.size() / 2)
        return true;
    else if (str[start] != str[str.size() - 1 - start])
        return false;
    return isPalindrome(str, start + 1, end);
}

//? Question: 08 (Calculate nth Fibonacci number using recursion):=
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // //? Example 1: Print Name 5 times using recursion
    // std::string name = "Nirmalya Dhara";
    // int times = 3;
    // printName(name, times);

    // //? Example 2: Print Numbers from 1 to n using recursion
    // int n = 5;
    // printNumbers(n);

    // //? Example 3: Print Numbers from n to 1 using recursion
    // int n = 5;
    // printNumbersReverse(n);

    // //? Example 4: Calculate Sum of Numbers from 1 to n using recursion
    // int n = 5;
    // std::cout << sumOfNumbers(n) << std::endl;

    // //? Example 5: Calculate Factorial of a Number using recursion
    // int n = 5;
    // std::cout << factorial(n) << std::endl;

    // //? Example 6: Reverse an Array using recursion
    // int arr[] = {1, 2, 3, 4, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // reverseArray(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     std::cout << arr[i] << " ";

    // //? Example 7: Check if a string is Palindrome or not using recursion
    // std::string str = "madam";
    // int start = 0, end = str.length() - 1;
    // std::cout << (isPalindrome(str, start, end) ? "Palindrome" : "Not Palindrome") << std::endl;

    // //? Example 8: Calculate nth Fibonacci number using recursion
    // int n = 5;
    // std::cout << fibonacci(n) << std::endl;

    return 0;
}