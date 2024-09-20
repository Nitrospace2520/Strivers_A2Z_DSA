/**
 * @file 08_linear_search.cpp
 * @author Nirmalya Dhara
 * @brief search an element of an array
 * @date 2023-12-25
 */
#include <bits/stdc++.h>

using namespace std;
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