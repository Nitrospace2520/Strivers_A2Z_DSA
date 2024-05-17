/**
 * @file 06_check_prime_number.cpp
 * @author Nirmalya Dhara
 * @brief Check if a number is prime or not
 * @date 2024-04-01
 */
#include <bits/stdc++.h>

/**
 * Check if a given number is prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 *
 * @param n The number to be checked.
 * @return True if the number is prime, false otherwise.
 *
 * The function uses an optimized approach to check if a number is prime.
 * It first checks if the number is less than or equal to 1, in which case it returns false.
 * Then it checks if the number is divisible by 2 or 3, in which case it returns false.
 * Finally, it checks all numbers of the form 6k+1 and 6k-1 till the square root of the number.
 * If any of these numbers divides the given number, it returns false.
 * If none of these conditions are met, it returns true.
 *
 * Time complexity: O(sqrt(n))
 */
bool checkPrime(int n)
{
    /* //? Brute force approach: Check all numbers from 2 to n-1 and return false if any number divides n. Time complexity: O(n)
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true; */

    /* //? Better approach: Check all numbers from 2 to sqrt(n) and return false if any number divides n. Time complexity: O(sqrt(n))
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true; */

    //? Optimized approach: Check if n is divisible by 2 or 3. Then check all numbers of the form 6k+1 and 6k-1 till sqrt(n). Time complexity: O(sqrt(n))
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (checkPrime(n))
    {
        std::cout << n << " is a prime number." << std::endl;
    }
    else
    {
        std::cout << n << " is not a prime number." << std::endl;
    }

    return 0;
}