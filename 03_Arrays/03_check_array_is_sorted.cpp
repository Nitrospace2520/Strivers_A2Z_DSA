#include <bits/stdc++.h>

using namespace std;
bool is_sorted(vector<int> &arr)
{
    //! Optimal Approach
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << (is_sorted(arr) ? "true" : "false") << endl;
    return 0;
}