#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int pivotIndex(vector<int>& nums) {
    auto length = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    int leftSum = 0;
    for (int i = 0; i < length; i++) {
        if (leftSum == (totalSum - nums[i] - leftSum)) {
            // Right sum (totalSum - nums[i] - leftSum), is the same as left sum.
            // We found our index!
            return i;
        }
        // Otherwise, add element to left sum.
        leftSum += nums[i];
    }
    return -1;
}

int main()
{
    //vector<int> v = {3, 4, 5, 7, 5, 2, 1};
    //vector<int> v = {4, -1, 1};
    vector<int> v = {1,7,3,6,5,6};
    int pivot = pivotIndex(v);

    cout << "Pivot: " << pivot << endl;
}