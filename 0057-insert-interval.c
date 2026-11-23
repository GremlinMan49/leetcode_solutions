// 57. Insert Interval (Medium)
// https://leetcode.com/problems/insert-interval/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int i = 0, idx = 0;
    
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        res[idx] = (int*)malloc(2 * sizeof(int));
        res[idx][0] = intervals[i][0];
        res[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }
    
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        if (intervals[i][0] < newInterval[0]) newInterval[0] = intervals[i][0];
        if (intervals[i][1] > newInterval[1]) newInterval[1] = intervals[i][1];
        i++;
    }
    
    res[idx] = (int*)malloc(2 * sizeof(int));
    res[idx][0] = newInterval[0];
    res[idx][1] = newInterval[1];
    (*returnColumnSizes)[idx] = 2;
    idx++;
    
    while (i < intervalsSize) {
        res[idx] = (int*)malloc(2 * sizeof(int));
        res[idx][0] = intervals[i][0];
        res[idx][1] = intervals[i][1];
        (*returnColumnSizes)[idx] = 2;
        idx++;
        i++;
    }
    
    *returnSize = idx;
    return res;
}
