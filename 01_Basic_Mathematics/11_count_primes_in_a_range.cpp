/**
 * @file 11_count_primes_in_a_range.cpp
 * @author Nirmalya Dhara
 * @brief count the number of prime numbers in a given range [L, R]
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

void countPrimes(std::vector<std::pair<int, int>> &queries)
{
    std::vector<int> countedPrimes;

    /* //? BruteForce Approach: O(Q * (R - L) * sqrt(R))
    for (int i = 0; i < queries.size(); i++)
    {
        int count = 0;
        for (int j = queries[i].first; j <= queries[i].second; j++)
        {
            if (isPrime(j))
                count++;
        }
        countedPrimes.push_back(count);
    } */

    /* //? Better Approach: O(Q * (R - L))
    int high = INT_MIN;
    for (int i = 0; i < queries.size(); i++)
        high = std::max(high, queries[i].second);

    //* Sieve of Eratosthenes Algorithm:- Time complexity O(n*log(log(n))), Space complexity O(n)
    std::vector<bool> prime(high + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= high; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= high; j += i)
                prime[j] = false;
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i].first, r = queries[i].second;
        int count = 0;
        for (int j = l; j <= r; j++)
        {
            if (prime[j])
                count++;
        }
        countedPrimes.push_back(count);
    } */

    //? Optimal Approach: O(Q + n*log(log(n)) + n + Q) = O(n*log(log(n)) where n = max(R)
    int high = INT_MIN;
    for (int i = 0; i < queries.size(); i++)
        high = std::max(high, queries[i].second);

    //* Sieve of Eratosthenes Algorithm:- Time complexity O(n*log(log(n))), Space complexity O(n)
    std::vector<int> prime(high + 1, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i * i <= high; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= high; j += i)
                prime[j] = 0;
        }
    }
    int count = 0;
    for (int i = 0; i <= high; i++)
    {
        if (prime[i] == 1)
            count++;
        prime[i] = count;
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i].first, r = queries[i].second;
        int count = prime[r] - prime[l - 1];
        countedPrimes.push_back(count);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        std::cout << "The number of prime numbers in the range [" << queries[i].first << ", " << queries[i].second << "] is: " << countedPrimes[i] << std::endl;
    }
}

int main()
{
    int noOfQueries;
    std::cout << "Enter the number of queries: ";
    std::cin >> noOfQueries;
    std::vector<std::pair<int, int>> queries;
    for (int i = 0; i < noOfQueries; i++)
    {
        int L, R;
        std::cout << "Enter the range [L, R]: ";
        std::cin >> L >> R;
        queries.push_back({L, R});
    }

    countPrimes(queries);

    return 0;
}