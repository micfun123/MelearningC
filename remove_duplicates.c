#include <stdio.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int uniqueCount = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[uniqueCount - 1]) {
            nums[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }
    return uniqueCount;
}

int main() {
    int nums[] = {1, 1, 2, 3, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int newSize = removeDuplicates(nums, size);
    
    printf("New size: %d\n", newSize);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}