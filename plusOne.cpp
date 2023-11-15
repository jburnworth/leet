#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void recursiveCarryOne(vector<int>& digits, int currentIndex) {
    cout << "Going recursive..." << endl;
    // Set current index to 0 while we carry the 1.
    digits[currentIndex] = 0;
    // Check if we can increment an existing element or need to push on a new 1.
    int nextIndex = currentIndex - 1;
    if (nextIndex >= 0) {
        if (digits[nextIndex] < 9) {
            digits[nextIndex] += 1;
        } else {
            // Carry the one
            recursiveCarryOne(digits, nextIndex);
        }
    } else {
        // We are at the left most digit, push a new one on!
        digits.insert(digits.begin(), 1);
    }

    return;
}

vector<int> plusOneRecursive(vector<int>& digits) {
    auto currentIndex = digits.size() - 1;

    // Simple case first, the right most digit is less than 9 and there's no carry over.
    if (digits[currentIndex] < 9) {
        digits[currentIndex] += 1;
    } else {
        // Otherwise we need to carry the one
        recursiveCarryOne(digits, currentIndex);
    }

    return digits;
}

vector<int> plusOne(vector<int>& digits) {
    for (int i = (digits.size() - 1); i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
            }
            continue;
        } else {
            digits[i] += 1;
            break;
        }
    }

    return digits;
}

int main()
{
    vector<int> v = {1, 2};
    auto result = plusOne(v);

    //cout << "Pivot: " << result << endl;
    for (auto n: result) {
        cout << n;
    }
    cout << endl;
}