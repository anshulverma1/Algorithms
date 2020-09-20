#include <iostream>
using namespace std;


// Returns index of closest element lesser than or equal to the target
int binarySearchLower(int nums[], int len, int target)
{
    int left = 0, right = len - 1;
    if(nums[left] > target) return -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}

// Returns index of closest element greater than or equal to the target
int binarySearchHigher(int nums[], int len, int target)
{
    int left = 0, right = len - 1;
    if(nums[right] < target) return -1; 
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

// Returns index of the element closest to the target
int binSearchClosest(int nums[], int len, int target)
{
    int indLow = binarySearchLower(nums, len, target);
    int indHigh = binarySearchHigher(nums, len, target);
    if(indLow == -1) return indHigh;
    else if(indHigh == -1) return indLow;
    else if(abs(target - nums[indLow]) > abs(target - nums[indHigh])) return indHigh;
    return indLow; 
}

int main()
{
    int nums[7] = {-144, -11, 7, 33, 169, 217, 333};
    cout << nums[binarySearchLower(nums, 7, 216)] << '\n';
    cout << nums[binarySearchLower(nums, 7, 33)] << '\n';
    cout << binarySearchLower(nums, 7, -145) << '\n';
    cout << nums[binarySearchHigher(nums, 7, 216)] << '\n';
    cout << nums[binarySearchHigher(nums, 7, 33)] << '\n';
    cout << binarySearchHigher(nums, 7, 334) << '\n';
    cout << nums[binSearchClosest(nums, 7, 216)] << '\n';
    cout << nums[binSearchClosest(nums, 7, -145)] << '\n';
    cout << nums[binSearchClosest(nums, 7, 334)] << '\n';
    return 0;
}