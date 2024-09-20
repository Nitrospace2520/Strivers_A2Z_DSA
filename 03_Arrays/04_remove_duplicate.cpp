// TODO: Remove Duplicate inplace from a sorted array:-
#include <bits/stdc++.h>

using namespace std;
void printArray(vector<int> &arr)
{
    for (auto &&i : arr)
        cout << i << " ";
    cout << endl;
}
void removeDuplicate(vector<int> &arr)
{
    /* //! Brute Force Approach
    unordered_set<int> st;
    int start = 0;
    for (auto i = 0; i < arr.size(); i++)
    {
        if (st.find(arr[i]) == st.end())
        {
            arr[start++] = arr[i];
        }
        st.insert(arr[i]);
    } */

    //! Optimal Approach (Two Pointer)
    int start = 0, end = 1;
    while (end < arr.size())
    {
        if (arr[start] == arr[end])
            end++;
        else
            arr[++start] = arr[end];
    }
    printArray(arr);
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 6, 6, 7};
    removeDuplicate(arr);
    return 0;
}