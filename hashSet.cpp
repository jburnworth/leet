#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

using namespace std;

class MyHashSet {
private:
    int keyRange;
    vector<list<int>> table;

    int hashin(int key) {
        return key % keyRange;
    }

    list<int>& getBucket(int key) {
        return table[hashin(key)];
    }

    bool bucketContainsKey(list<int>& bucket, int key) {
        for (auto num: bucket) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }

public:
    MyHashSet() {
        keyRange = 541;
        table = vector<list<int>>(keyRange);
    }

    void add(int key) {
        // Get the hash bucket for our key
        list<int> &bucket = getBucket(key);
        // Check if the key is already in the table
        if (!bucketContainsKey(bucket, key)) {
            // Add the key
            bucket.push_back(key);
        }
    }

    void remove(int key) {
        // Get the prospective bucket for our key
        list<int> &bucket = getBucket(key);
        // If the key is in the bucket, remove it.
        if (bucketContainsKey(bucket, key)) {
            bucket.remove(key);
        }

    }

    bool contains(int key) {
        return bucketContainsKey(getBucket(key), key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    MyHashSet* hashTable = new MyHashSet();
    hashTable->add(4);
    hashTable->add(4);
    hashTable->add(545);

    if (hashTable->contains(4)) {
        cout << "Table contains 4" << endl;
    }
    if (hashTable->contains(5)) {
        cout << "Table contains 5" << endl;
    }
}