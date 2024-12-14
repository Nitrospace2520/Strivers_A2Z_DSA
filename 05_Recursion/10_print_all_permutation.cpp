/**
 * @file 10_print_all_permutation.cpp
 * @author Nirmalya Dhara
 * @brief print all permutation of a array
 * @date 2024-12-14
 */
#include <iostream>
#include <vector>

/**
 * @brief Generates all permutations of the given array.
 *
 * This helper function uses backtracking to generate all possible permutations
 * of the input array. It recursively builds each permutation and stores it in
 * the result vector.
 *
 * @param arr The input array for which permutations are to be generated.
 * @param n The size of the input array.
 * @param result A reference to a vector of vectors where each inner vector is a permutation of the input array.
 * @param row A temporary vector used to build each permutation.
 * @param visited A vector of boolean values to keep track of which elements have been used in the current permutation.
 */
void generate_permutation_helper1(std::vector<int> &arr, int n, std::vector<std::vector<int>> &result, std::vector<int> &row, std::vector<bool> &visited)
{
    if (row.size() == n)
    {
        result.push_back(row);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            row.push_back(arr[i]);
            generate_permutation_helper1(arr, n, result, row, visited);
            row.pop_back();
            visited[i] = false;
        }
    }
}

/**
 * @brief Generates all permutations of the given array starting from the current index.
 *
 * This function uses recursion and backtracking to generate all possible permutations
 * of the input array. It swaps elements to create permutations and backtracks to
 * restore the original array state.
 *
 * @param arr The input array for which permutations are to be generated.
 * @param n The size of the input array.
 * @param result A reference to a vector of vectors where the generated permutations will be stored.
 * @param idx The current index from which to generate permutations.
 */
void generate_permutation_helper2(std::vector<int> &arr, int n, std::vector<std::vector<int>> &result, int idx)
{
    if (idx == n)
    {
        result.push_back(arr);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        std::swap(arr[i], arr[idx]);
        generate_permutation_helper2(arr, n, result, idx + 1);
        std::swap(arr[i], arr[idx]);
    }
}

/**
 * @brief Generates all permutations of the given array and prints them.
 *
 * This function generates all possible permutations of the input array `arr` of size `n`
 * and prints each permutation. It uses a helper function to generate the permutations.
 *
 * @param arr The input array for which permutations are to be generated.
 * @param n The size of the input array.
 *
 * The function uses two different helper functions to generate permutations:
 * - `generate_permutation_helper1`: Uses a temporary array and a visited array to generate permutations.
 * - `generate_permutation_helper2`: Uses swapping to generate permutations.
 *
 * The result is stored in a 2D vector `result`, where each row represents a permutation.
 * The permutations are then printed to the standard output.
 */
void generate_permutation(std::vector<int> &arr, int n)
{
    std::vector<std::vector<int>> result;

    // std::vector<int> temp;
    // std::vector<bool> visited(n, false);
    // generate_permutation_helper1(arr, n, result, temp, visited);
    //! OR
    generate_permutation_helper2(arr, n, result, 0);

    for (auto &row : result)
    {
        for (auto &ele : row)
            std::cout << ele << " ";
        std::cout << std::endl;
    }
}
int main(int argc, char const *argv[])
{
    std::vector<int> arr = {1, 2, 3};
    int n = arr.size();

    generate_permutation(arr, n);
    return 0;
}
