/**
 * @file 10_find_prime_numbers_upto_n.cpp
 * @author Nirmalya Dhara
 * @brief find all the prime numbers upto n
 * @date 2024-04-03
 */

#include <bits/stdc++.h>

/**
 * Check if a given number is prime.
 *
 * @param n The number to check.
 * @return True if the number is prime, false otherwise.
 */
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
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

/**
 * Finds all prime numbers up to a given number.
 *
 * @param n The upper limit of the range to search for prime numbers.
 * @return None.
 *
 * The function uses the optimized approach known as the sieve of Eratosthenes
 * to find all prime numbers up to the given number 'n'. It initializes a boolean
 * array 'prime' of size 'n+1' and sets all elements to true. Then, it iterates
 * through the array and marks all multiples of each prime number as false. Finally,
 * it prints all the numbers that are marked as prime.
 *
 * Time complexity: O(n*log(log(n)))
 * Space complexity: O(n)
 */
void findAllPrimes(int n)
{
    /* //? Brute force approach: Time complexity O(n*sqrt(n)), Space complexity O(1)
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            std::cout << i << " ";
    }
    std::cout << std::endl; */

    //? Optimized approach (sieve of eratosthenes): Time complexity O(n*log(log(n))), Space complexity O(n)
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            std::cout << p << " ";
    }
}

int main()
{
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    findAllPrimes(n);
    return 0;
}