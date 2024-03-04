// COPILOT

#include <stdio.h>

// Function to update the Fenwick Tree
void update(int tree[], int n, int index, int value) {
    while (index <= n) {
        tree[index] += value;
        index += index & (-index);
    }
}

// Function to get the prefix sum from 1 to index
int getPrefixSum(int tree[], int index) {
    int sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

// Function to get the sum in the range [left, right]
int getRangeSum(int tree[], int left, int right) {
    return getPrefixSum(tree, right) - getPrefixSum(tree, left - 1);
}

int main() {
    int n = 10; // Size of the array
    int arr[] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2}; // Input array

    // Create and initialize the Fenwick Tree
    int tree[n + 1];
    for (int i = 1; i <= n; i++) {
        tree[i] = 0;
    }

    // Build the Fenwick Tree
    for (int i = 1; i <= n; i++) {
        update(tree, n, i, arr[i - 1]);
    }

    // Example usage
    int left = 2;
    int right = 7;
    int rangeSum = getRangeSum(tree, left, right);
    printf("Sum in the range [%d, %d] is %d\n", left, right, rangeSum);

    return 0;
}

// C++ implementation of Fenwick Tree (Binary Indexed Tree) for range sum queries and point updates in O(log n) time

class FenwickTree {
private:
    std::vector<int> tree;

public:
    FenwickTree(int size) {
        tree.resize(size + 1, 0);
    }

    void update(int index, int value) {
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};


// GPT
#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> tree;

public:
    FenwickTree(int size) {
        tree.assign(size + 1, 0);
    }

    // Update the value at index i by delta
    void update(int i, int delta) {
        ++i; // Fenwick Tree is 1-indexed
        while (i < tree.size()) {
            tree[i] += delta;
            i += i & -i; // Move to the parent node
        }
    }

    // Get the prefix sum up to index i
    int query(int i) const {
        ++i; // Fenwick Tree is 1-indexed
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i; // Move to the parent node
        }
        return sum;
    }

    // Get the sum in the range [l, r]
    int rangeQuery(int l, int r) const {
        if (l > r || l < 0 || r >= tree.size()) {
            std::cerr << "Invalid range\n";
            return 0;
        }
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};

int main() {
    // Example usage of Fenwick Tree
    int size = 10;
    FenwickTree fenwickTree(size);

    // Update values
    fenwickTree.update(2, 3);
    fenwickTree.update(5, 2);
    fenwickTree.update(8, 1);

    // Query the prefix sum at index 5
    std::cout << "Prefix sum at index 5: " << fenwickTree.query(5) << std::endl;

    // Range query in the range [2, 7]
    std::cout << "Sum in range [2, 7]: " << fenwickTree.rangeQuery(2, 7) << std::endl;

    return 0;
}

// GPT WITH INPUT

#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> BIT;

public:
    FenwickTree(int size) {
        BIT.assign(size + 1, 0);
    }

    // Point update: Adds 'value' to the element at index 'index'
    void update(int index, int value) {
        index++; // Convert 0-based index to 1-based index
        while (index < BIT.size()) {
            BIT[index] += value;
            index += index & -index; // Move to the parent in the tree
        }
    }

    // Range query: Gets the sum of elements in the range [1, index]
    int query(int index) {
        index++; // Convert 0-based index to 1-based index
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index; // Move to the parent in the tree
        }
        return sum;
    }
};

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    FenwickTree fenwickTree(n);

    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        fenwickTree.update(i, element);
    }

    int queryIndex;
    std::cout << "Enter the index for range query (0-based index): ";
    std::cin >> queryIndex;

    int result = fenwickTree.query(queryIndex);

    std::cout << "Sum of elements in the range [0, " << queryIndex << "]: " << result << std::endl;

    return 0;
}
