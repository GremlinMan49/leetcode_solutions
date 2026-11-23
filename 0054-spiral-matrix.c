// 54. Spiral Matrix (Medium)
// https://leetcode.com/problems/spiral-matrix/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int* res = (int*)malloc(rows * cols * sizeof(int));
    *returnSize = 0;
    
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) res[(*returnSize)++] = matrix[top][i];
        top++;
        for (int i = top; i <= bottom; i++) res[(*returnSize)++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) res[(*returnSize)++] = matrix[bottom][i];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) res[(*returnSize)++] = matrix[i][left];
            left++;
        }
    }
    return res;
}
