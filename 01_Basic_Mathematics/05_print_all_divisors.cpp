/**
 * @file 05_print_all_divisors.cpp
 * @author Nirmalya Dhara
 * @brief Print all the divisors of a number
 * @date 2024-04-01
 */
#include <bits/stdc++.h>

/**
 *  Function: printDivisors
 * -----------------------
 * This function takes an integer 'n' as input and prints all the divisors of 'n'.
 * It uses an optimized approach to check all numbers from 1 to sqrt(n) and prints if it is a divisor.
 * The time complexity of this function is O(sqrt(n)).
 *
 * @param n: The integer for which divisors need to be printed.
 * @return: None
 */
void printDivisors(int n)
{
    /* //? Brute force approach: Check all numbers from 1 to n and print if it is a divisor. Time complexity: O(n)
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << " ";
        }
    } */

    //? Optimized approach: Check all numbers from 1 to sqrt(n) and print if it is a divisor. Time complexity: O(sqrt(n)) but doesn't print in sorted order. You can sort the divisors if needed using a vector/list.
    /* for (int i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                std::cout << i << " ";
            else
                std::cout << i << " " << n / i << " ";
        }
    } */
    //$ For Sorted Order:=
    int i = 1;
    for (; i * i < n; i++)
    {
        if (n % i == 0)
            std::cout << i << " ";
    }
    for (; i > 1; i--)
    {
        if (n % i == 0)
            std::cout << n / i << " ";
    }
    std::cout << n << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "The divisors of " << n << " are: ";
    printDivisors(n);
    std::cout << std::endl;
    return 0;
}