/**
 * @file 03_swap_two_numbers.cpp
 * @author Nirmalya Dhara
 * @brief swap two numbers
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Swaps the values of two integers.
 *
 * This function takes two integer references as input and swaps their values.
 * It uses the XOR bitwise operator to perform the swap, which is considered the best approach.
 *
 * @param n1 The first integer to be swapped.
 * @param n2 The second integer to be swapped.
 */
void swap(int &n1, int &n2)
{
    /* // ? Approach-01 :with temporary variable
    int temp = n1;
    n1 = n2;
    n2 = temp; */

    /* // ? Approach-02 : without temporary variable
    n1 = n1 + n2;
    n2 = n1 - n2;
    n1 = n1 - n2; */

    // ? Approach-03 : using XOR (bitwise operator) best approach
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
}
int main()
{
    int n1, n2;
    std::cout << "Enter two numbers: ";
    std::cin >> n1 >> n2;

    std::cout << "Before swapping: n1 = " << n1 << " n2 = " << n2 << std::endl;
    swap(n1, n2);
    std::cout << "After swapping: n1 = " << n1 << " n2 = " << n2 << std::endl;
    return 0;
}