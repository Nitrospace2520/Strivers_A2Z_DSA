/**
 * @file 06_right_rotate_by_k_position.cpp
 * @author Nirmalya Dhara
 * @brief right rotate an array by k position
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
void right_rotate_by_1(vector<int> &arr)
{
    int temp = arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
}
void reverse_array(vector<int> &arr, int start, int end)
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
void right_rotate_by_k(vector<int> &arr, int k = 1)
{
    k = k % arr.size();
    /* //! BruteForce Solution (T.C: O(K*N), S.C: O(1))
    for (int i = 0; i < k; i++)
        right_rotate_by_1(arr); */

    /* //! Better Solution (T.C: O(N), S.C: 0(K))
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
        temp[i] = arr[arr.size() - k + i];
    for (int i = arr.size() - k - 1, j = 0; i >= 0; i--, j++)
        arr[arr.size() - 1 - j] = arr[i];
    for (int i = k - 1; i >= 0; i--)
        arr[i] = temp[i]; */

    // ! Optimal Solution (T.C: O(N), S.C: O(1))
    reverse_array(arr, 0, (arr.size() - k - 1));
    reverse_array(arr, (arr.size() - k), arr.size() - 1);
    reverse_array(arr, 0, arr.size() - 1);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    right_rotate_by_k(arr, 3); // 7, 8, 9, 1, 2, 3, 4, 5, 6
    printArray(arr);
    return 0;
}