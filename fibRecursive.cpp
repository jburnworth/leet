#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int fib(int n) {
    if (n < 2) {
        return n;
    }
    static unordered_map<int, int> fibMap;
    //cout << "print the map" << endl;
    for (auto i: fibMap) {
        //cout << i.first << ", " << i.second << endl;
    }
    //cout << "map printed" << endl;

    if (fibMap.count(n) > 0) {
        //cout << "Found previously calculated value for " << n << endl;
    } else {
        //cout << "Need to calculate value for " << n << endl;
        fibMap[n] = fib(n - 1) + fib(n - 2);
    }
    return fibMap[n];
}

int main()
{
    int fibNum = fib(4);

    cout << endl << "The fibonacci number is: " << fibNum;
    //for (auto i: pascalRow) {
        //cout << i << " ";
    //}
    cout << endl;
    if (__cplusplus == 202002L) cout << "20\n";
    if (__cplusplus == 201703L) cout << "17\n";
    if (__cplusplus == 202002L) cout << "14\n";
    if (__cplusplus == 202002L) cout << "11\n";
    if (__cplusplus == 202002L) cout << "20\n";
}