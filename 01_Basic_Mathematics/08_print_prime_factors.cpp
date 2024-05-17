/**
 * @file 08_print_prime_factors.cpp
 * @author Nirmalya Dhara
 * @brief print prime factors of a number
 * @date 2024-04-02
 */
#include <iostream>

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
void printPrimeFactors(int n)
{
    /* //? Brute force approach: Time Complexity: O(n*sqrt(n))
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0 && isPrime(i))
            std::cout << i << " ";
    }
    std::cout << std::endl; */

    /* //? Better approach: Time Complexity: O(sqrt(n)*sqrt(n))
    if (n <= 1)
        return;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i))
                std::cout << i << " ";
            if (n / i != i && isPrime(n / i))
                std::cout << n / i << " ";
        }
    }
    if (isPrime(n))
        std::cout << n;
    std::cout << std::endl; */

    /* //? Optimized approach: Time Complexity: O(n) [worst case]
    if (n <= 1)
        return;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << " ";
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    std::cout << std::endl; */

    //? Most optimized approach: Time Complexity: O(sqrt(n) * log(n))
    if (n <= 1)
        return;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << " ";
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if (n > 1)
        std::cout << n;
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    printPrimeFactors(n);
    return 0;
}