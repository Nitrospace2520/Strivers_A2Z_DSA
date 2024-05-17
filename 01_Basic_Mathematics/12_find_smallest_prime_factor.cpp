/**
 * @file 12_find_smallest_prime_factor.cpp
 * @author Nirmalya Dhara
 * @brief Program to find the smallest prime factor of a number. Prime Factorization is the process of finding the prime factors that multiply together to give the original number.
 * @date 2024-04-04
 */

#include <bits/stdc++.h>

/**
 * @brief Calculates the prime factorization of a given number.
 *
 * This function takes an integer 'n' as input and returns a vector of integers representing the prime factors of 'n'.
 *
 * @param n The number for which prime factorization needs to be calculated.
 * @return A vector of integers representing the prime factors of 'n'.
 */
std::vector<int> getPrimeFactorisation(int n)
{
    std::vector<int> primeFactors;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            primeFactors.push_back(i);
            n = n / i;
        }
    }
    if (n > 1)
        primeFactors.push_back(n);

    return primeFactors;
}

void printPrimeFactors(std::vector<int> &queries)
{
    /* //? Bruteforce approach: O(Q * sqrt(N))
    for (int i = 0; i < queries.size(); i++)
    {
        std::vector<int> primeFactors = getPrimeFactorisation(queries[i]);
        std::cout << "Prime factors of " << queries[i] << " are: ";
        for (int j = 0; j < primeFactors.size(); j++)
            std::cout << primeFactors[j] << " ";
        std::cout << std::endl;
    } */

    //? Optimized approach: O((Q * log(N)) + (N * log(log(N))))
    int highestNumber = *std::max_element(queries.begin(), queries.end());
    std::vector<int> spf(highestNumber + 1);
    for (int i = 0; i < highestNumber + 1; i++)
        spf[i] = i;

    for (int i = 2; i * i <= highestNumber; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= highestNumber; j += i)
                spf[j] = i;
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        std::cout << "Prime factors of " << queries[i] << " are: ";
        while (queries[i] != 1)
        {
            std::cout << spf[queries[i]] << " ";
            queries[i] = queries[i] / spf[queries[i]];
        }
        std::cout << std::endl;
    }
}
int main()
{
    int noOfQueries;
    std::cout << "Enter the number of queries: ";
    std::cin >> noOfQueries;

    std::vector<int> queries(noOfQueries);
    for (int i = 0; i < noOfQueries; i++)
    {
        std::cout << "Enter the number: ";
        std::cin >> queries[i];
    }

    printPrimeFactors(queries);

    return 0;
}