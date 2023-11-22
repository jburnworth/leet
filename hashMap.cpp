#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

using namespace std;

class MyHashMap {
private:
    int keyRange;
    vector<list<pair<int, int>>> table;

    int hashin(int key) {
        return key % keyRange;
    }

    list<pair<int, int>>& getBucket(int key) {
        return table[hashin(key)];
    }

public:
    MyHashMap() {
        keyRange = 541;
        table = vector<list<pair<int, int>>>(keyRange);
    }

    void put(int key, int value) {
        // Get the hash bucket for our key
        list<pair<int, int>> &bucket = getBucket(key);
        // Look through bucket for the key
        for (pair<int, int> &p : bucket) {
            // If the key exists, update the value.
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        // Otherwise add the new key value pair.
        bucket.push_back(make_pair(key, value));
    }

    int get(int key) {
        // Get the hash bucket for our key
        list<pair<int, int>> &bucket = getBucket(key);
        // Look through bucket for the key
        for (pair<int, int> &p : bucket) {
            // If the key exists, return the value.
            if (p.first == key) {
                return p.second;
            }
        }
        // Key not found
        return -1;
    }

    void remove(int key) {
        // Get the hash bucket for our key
        list<pair<int, int>> &bucket = getBucket(key);
        // Look through bucket for the key
        for (pair<int, int> &p : bucket) {
            // If the key exists, return the value.
            if (p.first == key) {
                bucket.remove(p);
                return;
            }
        }
    }

    void printBucket(int key) {
        list<pair<int, int>> &bucket = getBucket(key);

        cout << "Printing bucket for key " << key << " -> ";
        for (pair<int, int> p : bucket) {
            cout << p.first << ":" << p.second << endl;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    MyHashMap* hashMap = new MyHashMap();
    hashMap->put(1, 4);
    hashMap->put(542, 4);
    hashMap->printBucket(1);
    cout << hashMap->get(1) << endl;
    hashMap->put(1, 5);
    hashMap->printBucket(1);
    cout << hashMap->get(1) << endl;
    hashMap->remove(1);
    cout << hashMap->get(1) << endl;
}