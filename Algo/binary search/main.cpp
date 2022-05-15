#include <stdio.h>
#include <vector>

int binary_search(std::vector<int> nums, int target)
{
    // int left = 0;
    // int right = nums.size() - 1;

    // 當 left + 1 > right 跳出
    // while(left <= right) {
    //     int mid = left + (right - left) / 2;
    //     if(nums[mid] > target)
    //         right = mid - 1;         // 縮小右邊邊界
    //     else if(nums[mid] < target)
    //         left = mid + 1;          // 放大左邊邊界
    //     else if(nums[mid] == target)
    //         return mid;
    // }
    // return -1;


    int left = 0;
    int right = nums.size();

    // 當 left == right 時就跳出
    // 這會導致 left == right 這沒判斷到就結束迴圈
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid - 1;            // 縮小右邊邊界
        else if(nums[mid] < target)
            left = mid + 1;             // 放大左邊邊界
        else if(nums[mid] == target)
            return mid;
    }
    // 因此在最後回傳時做一次判斷
    return nums[left] == target? left: -1;
}


/** @brief 左邊邊界找值
 * 
*/
int left_bound(std::vector<int> nums, int target)
{
    // int left = 0;
    // int right = nums.size() - 1;

    // while(left <= right) {
    //     int mid = left + (right - left) / 2;
    //     if(nums[mid] > target)
    //         right = mid - 1;         // 縮小右邊邊界     
    //     else if(nums[mid] < target)
    //         left = mid + 1;          // 放大左邊邊界
    //     else if(nums[mid] == target)
    //         right = mid - 1;         // 限縮右邊邊界，來找左邊值
    // }

    // 判斷是否超出邊界，如超出或答案不同則返回 -1
    // if(left > nums.size() || nums[left] != target)
    //     return -1;
    // return left;


    // 另一種 左邊界找值方法
    int left = 0;
    int right = nums.size();

    // when left == right break
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid;            
        else if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] == target)
            right = mid;            // 限縮右邊邊界，來找左邊值
    }
    return left;
}

/** @brief 右邊邊界找值
 * 
*/
int right_bound(std::vector<int> nums, int target)
{
    // int left = 0;
    // int right = nums.size() - 1;

    // while(left <= right) {
    //     int mid = left + (right - left) / 2;
    //     if(nums[mid] > target)
    //         right = mid - 1;             // 縮小右邊邊界
    //     else if(nums[mid] < target)
    //         left = mid + 1;              // 放大左邊邊界
    //     else if(nums[mid] == target)
    //         left = mid + 1;              // 限縮左邊邊界，來找右邊值
    // }

    // 判斷是否超出邊界，如超出或答案不同則返回 -1
    // if(right < 0 || nums[right] != target)
    //     return -1;
    // return right;


    int left = 0;
    int right = nums.size();

    // when left == right break
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] < target)
            left = mid;
        else if(nums[mid] == target)
            left = mid;                 // 限縮左邊邊界，來找右邊值
    }

    return right;
}

int main()
{
    std::vector<int> nums = {5, 7, 7, 8, 8, 8, 9};
    int target = 8;
    printf("%d\n", left_bound(nums, 8));
    printf("%d\n", right_bound(nums, 8));
    printf("%d\n", binary_search(nums, 5));
    return 0;
}