// 59. Spiral Matrix II (Medium)
// https://leetcode.com/problems/spiral-matrix-ii/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int** res = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) res[top][i] = num++;
        top++;
        for (int i = top; i <= bottom; i++) res[i][right] = num++;
        right--;
        for (int i = right; i >= left; i--) res[bottom][i] = num++;
        bottom--;
        for (int i = bottom; i >= top; i--) res[i][left] = num++;
        left++;
    }
    return res;
}
