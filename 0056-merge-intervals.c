// 56. Merge Intervals (Medium)
// https://leetcode.com/problems/merge-intervals/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int idx = 0;
    res[idx] = (int*)malloc(2 * sizeof(int));
    res[idx][0] = intervals[0][0];
    res[idx][1] = intervals[0][1];
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= res[idx][1]) {
            if (intervals[i][1] > res[idx][1]) {
                res[idx][1] = intervals[i][1];
            }
        } else {
            idx++;
            res[idx] = (int*)malloc(2 * sizeof(int));
            res[idx][0] = intervals[i][0];
            res[idx][1] = intervals[i][1];
        }
    }
    *returnSize = idx + 1;
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return res;
}
