// 4. Median of Two Sorted Arrays (Hard)
// https://leetcode.com/problems/median-of-two-sorted-arrays/

void sorter(int nums[], int numsSize);
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums[nums1Size + nums2Size];
    for(int i = 0 ; i < nums1Size ; i++)
    {
        nums[i] = nums1[i];
    }
    for(int j = 0 ; j < nums2Size ; j++)
    {
        nums[nums1Size + j] = nums2[j];
    }
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    sorter(nums,numsSize);
    float median;
    if(numsSize % 2 == 1)
    {
        median = nums[numsSize/2];
    }
    else
    {
        median = (float)(nums[numsSize/2] + nums[(numsSize/2)-1])/2;
    }
    return median;
}
void sorter(int nums[], int numsSize)
{
    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = 0; j < numsSize - 1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}
