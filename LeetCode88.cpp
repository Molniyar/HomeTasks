#include <iostream>
#include <vector>
using namespace std;
//easy
void printArray(vector<int> vec, int l) {
    cout << '[';
    int i = 0;
    for (; i < l - 1; i++) { cout << vec[i] << ", "; }
    cout << vec[i];
    cout << ']';
    cout << '\n';
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) { return; }
    vector<int> nums1copy = vector<int>(m);
    for (int i = 0; i < m; i++) {
        nums1copy[i] = nums1[i];
    }
    int l1 = 0;
    int l2 = 0;
    int resultIndex = 0;
    while (l1 < m && l2 < n) {
        if (nums1copy[l1] > nums2[l2]) {
            nums1[resultIndex] = nums2[l2];
            l2++;
        }
        else {
            nums1[resultIndex] = nums1copy[l1];
            l1++;
        }
        resultIndex++;
    }
    if (l2 < n) {
        nums1copy = nums2;
        l1 = l2;
        m = n;
    }
    while (l1 < m) {
        nums1[resultIndex] = nums1copy[l1];
        l1++;
        resultIndex++;
    }
}
/*
int main() {
    std::vector<int> arr0_1 = { 2,0 };
    int l0_1 = 1;
    std::vector<int> arr0_2 = { 1 };
    int l0_2 = 1;

    merge(arr0_1, l0_1, arr0_2, l0_2);

    printArray(arr0_1, l0_1+l0_2);

    return 0;
}
//*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) { return; }
        vector<int> nums1copy = vector<int>(m);
        for (int i = 0; i < m; i++) {
            nums1copy[i] = nums1[i];
        }
        int l1 = 0;
        int l2 = 0;
        int resultIndex = 0;
        while (l1 < m && l2 < n) {
            if (nums1copy[l1] > nums2[l2]) {
                nums1[resultIndex] = nums2[l2];
                l2++;
            }
            else {
                nums1[resultIndex] = nums1copy[l1];
                l1++;
            }
            resultIndex++;
        }
        if (l2 < n) {
            nums1copy = nums2;
            l1 = l2;
            m = n;
        }
        while (l1 < m) {
            nums1[resultIndex] = nums1copy[l1];
            l1++;
            resultIndex++;
        }
    }
};