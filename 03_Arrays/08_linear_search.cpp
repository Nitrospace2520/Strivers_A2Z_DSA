/**
 * @file 08_linear_search.cpp
 * @author Nirmalya Dhara
 * @brief search an element of an array
 * @date 2023-12-25
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief search an element of an array
 *
 * @details This function takes a vector of integers and a search element
 * and searches the element in the array. If the element is found, it prints
 * the index of the element, otherwise it prints "The element is not found".
 * Time Complexity: O(n), where n is the size of the array
 * Space Complexity: O(1)
 *
 * @param arr Reference to the vector of integers to be searched
 * @param search The element to be searched
 */
void linear_search(const vector<int> &arr, const int &search)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == search)
        {
            cout << "The search element present at index " << i << "\n";
            return;
        }
    }
    cout << "The element is not found\n";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; //* Sorted Array
    // vector<int> arr = {10, 2, 30, 4, 50, 6, 70}; //* Unsorted Array
    int search = 5;
    linear_search(arr, search);
    return 0;
}