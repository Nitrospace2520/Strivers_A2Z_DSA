/**
 * @file 06_left_rotate_by_k_position.cpp
 * @author Nirmalya Dhara
 * @brief rotate an array by k position to the left
 * @date 2023-12-20
 */
#include <bits/stdc++.h>

using namespace std;
void printArray(vector<int> &arr)
{
    for (auto &&i : arr)
        cout << i << " ";
    cout << endl;
}
void left_rotate_by_1(vector<int> &arr)
{
    int t = arr[0];
    for (int i = 0; i < arr.size(); i++)
        arr[i - 1] = arr[i];
    arr[arr.size() - 1] = t;
}
void reverseArray(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void left_rotate_by_k(vector<int> &arr, int k = 1)
{
    k = k % arr.size();
    /* //! Brute Force Solution (T.C : O(K*N), S.C : O(1))
    for (int i = 0; i < k; i++)
        left_rotate_by_1(arr); */

    /* //! Better Approach (T.C : O(N), S.C : O(K))
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];
    for (int i = k; i < arr.size(); i++)
        arr[i - k] = arr[i];
    for (int i = 0; i < k; i++)
        arr[i + arr.size() - k] = temp[i]; */

    //! Optimal Solution (T.C: O(N), S.C: O(1))
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, arr.size() - 1);
    reverseArray(arr, 0, arr.size() - 1);

    printArray(arr);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    left_rotate_by_k(arr, 5);
    return 0;
}