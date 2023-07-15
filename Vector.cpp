#include <iostream>
#include <vector>
using namespace std;


// A function for merging non-decreasing arrays of sizes m and n,
// In the first array after m elements there are n zeros (task from a Leetcode)
// O(n+m)
void MergeNonDecrasing(vector<int>& FirstArray, int m, vector<int>& SecondArray, int n)
{
    // in these cases, you need to exit the function,
    // otherwise when you get num1[0] or num2[0] pointers,
    // you will get undefined behavior error
    if (!n) return; // in this case (n == 0) nums1 already non-decreasing and full so we can return
    if (!m) // in this case we can just copy this into num1 and also return
    {
        FirstArray = SecondArray;
        return;
    }
    // pointer to pass through nums1 from m-1 to 0, nums1.data() is a pointer to the nums1[0]
    int* Nums1Ptr = FirstArray.data() + m - 1;
    // pointer to pass through nums2 from n-1 to 0, nums2.data() is a pointer to the nums2[0]
    int* Nums2Ptr = SecondArray.data() + n - 1;

    // pointer to pass through nums1 from n+m-1 to 0, through all to be honest.
    // Using prefix "--" for absolute perfomance!
    for (int* ThroughAllPtr = FirstArray.data() + n + m - 1; ThroughAllPtr >= FirstArray.data(); --ThroughAllPtr)
    {
        // Compare values on pointers
        if (Nums1Ptr >= FirstArray.data() && Nums2Ptr >= SecondArray.data())
        {
            // Setting a larger value into ThroughAllPtr,
            // decrementing for the corresponding pointer, using ternary operator
            *ThroughAllPtr = *Nums1Ptr > *Nums2Ptr ? *ThroughAllPtr = *Nums1Ptr-- : *ThroughAllPtr = *Nums2Ptr--;
        }
        // after it becomes impossible to find a pair for comparison,
        // we simply rewrite the remaining values of nums2 if into nums1.
        else if (Nums2Ptr >= SecondArray.data())
        {
            *ThroughAllPtr = *Nums2Ptr--;
        }
        else // remaining nums1 values already in nums1 so we don't have to do anything else
        {
            return;
        }
    }
}

void PrintArray(const vector<int>& Array)
{
    for (int i = 0; i < Array.size(); i++) { cout << Array[i] << " "; }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int m = 3;
    int n = 3;
    vector<int> FirstArray = {1, 2, 3, 0, 0, 0};
    vector<int> SecondArray = {2, 5, 6};

    cout << "1 case: " << endl;
    cout << "Array1: ";
    PrintArray(FirstArray);
    cout << "Array2 ";
    PrintArray(SecondArray);
    MergeNonDecrasing(FirstArray, m, SecondArray, n);
    cout << "Merged: ";
    PrintArray(FirstArray);
    cout << endl;

    m = 0;
    n = 1;
    FirstArray = {0};
    SecondArray = {1};

    cout << "2 case: " << endl;
    cout << "Array1: ";
    PrintArray(FirstArray);
    cout << "Array2 ";
    PrintArray(SecondArray);
    MergeNonDecrasing(FirstArray, m, SecondArray, n);
    cout << "Merged: ";
    PrintArray(FirstArray);
    cout << endl;

    m = 6;
    n = 3;
    FirstArray = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
    SecondArray = {1, 2, 2};
    
    cout << "3 case: " << endl;
    cout << "Array1: ";
    PrintArray(FirstArray);
    cout << "Array2 ";
    PrintArray(SecondArray);
    MergeNonDecrasing(FirstArray, m, SecondArray, n);
    cout << "Merged: ";
    PrintArray(FirstArray);

    return 0;
}

// base function without using pointers
void SimpleMerge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    for (int k = m + j; k >= 0; --k)
    {
        if (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i--];
            }
            else
            {
                nums1[k] = nums2[j--];
            }
        }
        else if (j >= 0) 
        {
            nums1[k] = nums2[j--];
        }
        else
        {
            break;
        }
    }
}
