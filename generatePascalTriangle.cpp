#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++) {
        // Build a triangle of 1's.
        vector<int> tempRow((i + 1), 1);
        res.push_back(tempRow);
        // Turn it into Pascal's Triangle
        // First and last elements in each row are always 1, so no need to iterate over them.
        for (int j = 1; j < i; j++) {
            //cout << j;
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        //cout << endl;
    }

    return res;
}

int main()
{
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    auto result = generatePascalTriangle(5);

    //cout << "Pivot: " << result << endl;
    //for (auto n: result) {
        //cout << n;
    //}
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}