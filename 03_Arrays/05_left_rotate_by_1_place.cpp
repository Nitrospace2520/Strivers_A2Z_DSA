/**
 * @file 05_left_rotate_by_1_place.cpp
 * @author Nirmalya Dhara
 * @brief Given an array, left rotate the array by one position.
 * @date 2024-03-21
 * @copyright Copyright (c) 2024
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Prints all elements of an integer vector to console
 *
 * This function takes a vector of integers and prints each element
 * separated by spaces, followed by a newline character.
 *
 * @param array Reference to the vector of integers to be printed
 */
void printArray(vector<int> &array)
{
    for (auto &&i : array)
        cout << i << " ";
    cout << endl;
}

/**
 * @brief Left rotates an array by one position in-place
 *
 * This function takes an array of integers and shifts all elements
 * one position to the left. The last element is moved to the first
 * position.
 *
 * Time Complexity: O(n) where n is size of input array
 * Space Complexity: O(1)
 *
 * @param array Reference to vector of integers to be rotated
 * @return void Modifies array in-place and prints result
 */
void left_rotate_by_1(vector<int> &array)
{
    /* //! BruteForce Solution (T.C : O(N), S.C : O(N))
    vector<int> temp(array.size());
    int j = 0;
    for (int i = 1; i < array.size(); i++)
        temp[j++] = array[i];
    temp[j] = array[0];

    for (int i = 0; i < temp.size(); i++)
        array[i] = temp[i]; */

    //! Optimal Solution (T.C : O(N), S.C : O(1))
    int temp = array[0];
    for (int i = 1; i < array.size(); i++)
    {
        array[i - 1] = array[i];
    }
    array[array.size() - 1] = temp;
    printArray(array);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    left_rotate_by_1(arr);
    return 0;
}