#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(const int& a, const int& b) {
    return (a % 2) < (b % 2);
}

vector<int> sortArrayByParity(vector<int>& nums) {
    sort(nums.begin(), nums.end(), isEven);
    return nums;
}

int main()
{
    //vector<int> v = {3, 4, 5, 7, 5, 2, 1};
    vector<int> v = {3363,4833,290,3381,4227,1711,1253,2984,2212,874,2358,2049,2846,2543,1557,1786,4189,1254,2803,62,3708,1679,228,1404,1200,4766,1761,1439,1796,4735,3169,3106,3578,1940,2072,3254,7,961,1672,1197,3187,1893,4377,2841,2072,2011,3509,2091,3311,233};
    vector<int> missing = sortArrayByParity(v);

    cout << "Missing" << endl;
    for (int m: missing) {
        cout << m << endl;
    }
}