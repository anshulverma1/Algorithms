#include <iostream>
using namespace std;


//Binary Search - Sorted Input
//Time Complexity: O(log(N))
//Space Complexity: Iterative - O(1) || Recursive - O(log(N))

int binarySearchIter(int nums[], int len, int target)
{
    int left = 0, right = len -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}


int binarySearchRecur(int nums[], int start, int end, int target)
{
    if(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) return mid;
        else if (nums[mid] < target) return binarySearchRecur(nums, mid + 1, end, target);
        else return binarySearchRecur(nums, start, mid - 1, target);
    }
    return -1;
}

void print(int ind)
{
    if(ind != -1) cout << "Element Found at index : " << ind << '\n';
    else cout << "Element not found. \n";
}

int main()
{
    int nums[7] = {-144, -11, 0, 33, 67, 109, 122};
    print(binarySearchIter(nums, 7, -144));
    print(binarySearchIter(nums, 7, 112));
    print(binarySearchRecur(nums, 0, 6, 122));
    print(binarySearchRecur(nums, 0, 6, 112));
    print(binarySearchIter(nums, 7, 67));
    print(binarySearchRecur(nums, 0, 6, 33));
    return 0;    
}