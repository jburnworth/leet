#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }
        // Initialize a vector for our answer.
        vector<int> pascalRow(rowIndex + 1);
        // The first and last values are 1.
        pascalRow[0] = 1, pascalRow[rowIndex] = 1;

        // Get the row above.
        vector<int> rowAbove = getRow(rowIndex - 1);
        // Fill in the middle values
        for (int i = 1; i < rowIndex; i++) {
            pascalRow[i] = rowAbove[i - 1] + rowAbove[i];
        }

        return pascalRow;
    }

int main()
{
    vector<int> pascalRow = getRow(3);

    cout << endl << "The row is: ";
    for (auto i: pascalRow) {
        cout << i << " ";
    }
    cout << endl;
}