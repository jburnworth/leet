#include <iostream>
#include <vector>

bool validMountainArray(std::vector<int>& arr) {
    size_t length = arr.size();
    int i = 0;

    // Walk up the mountain till we find the peak
    while ((i < length) && (arr[i] < arr[i+1])) {
        //std::cout << arr[i] << std::endl;
        //std::cout << arr[i] << " < " << arr[i+1] << " at " << i << std::endl;
        i++;
    }

    //std::cout << "Peak is: :" << arr[i] << std::endl;

    // Check the peak isn't the first or the last element
    if ((i == 0) || (i == (length - 1))) {
        //std::cout << "First or last element NOT VALID" << std::endl;
        return false;
    }

    // Walk down the mountain and hope we make it to the end
    while (((i + 1) < length) && (arr[i] > arr[i+1])) {
        //std::cout << arr[i] << " > " << arr[i+1] << " at " << i << std::endl;
        i++;
    }

    //std::cout << "End is: :" << arr[i] << std::endl;

    return i == (length - 1);
}

int main()
{
    std::vector<int> v = {3, 4, 5, 9, 111, 8, 2, 1};
    validMountainArray(v);
}