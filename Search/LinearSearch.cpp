#include <iostream>
using namespace std;

// Linear Search
// Time Complexity: O(N)
// Space Complexity: O(1)

int LinearSearch(int nums[], int length, int target)
{
    for(int ind = 0; ind < length; ind++)
    {
        if(nums[ind] == target) return ind;
    }
    return -1;
}


int main()
{
    int nums[7] = {62, 17, -14, 99, 1024, -33, -487};
    int target1 = -33, target2 = 1023;
    int result1 = LinearSearch(nums, 7, target1), result2 = LinearSearch(nums, 7, target2);
    if(result1 != -1) cout << target1 << " Found at index " << result1 << '\n';
    else cout << target1 << " Not found" << '\n';
    if(result2 != -1) cout << target2 << " Found at index " << result2 << '\n'; 
    else cout << target2 << " Not found" << '\n';
    return 0;
}