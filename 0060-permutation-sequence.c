// 60. Permutation Sequence (Hard)
// https://leetcode.com/problems/permutation-sequence/

char* getPermutation(int n, int k) {
    int* fact = (int*)malloc(n * sizeof(int));
    int* nums = (int*)malloc(n * sizeof(int));
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;
    for (int i = 0; i < n; i++) nums[i] = i + 1;
    
    char* res = (char*)malloc((n + 1) * sizeof(char));
    k--;
    for (int i = 0; i < n; i++) {
        int idx = k / fact[n - 1 - i];
        res[i] = nums[idx] + '0';
        for (int j = idx; j < n - 1 - i; j++) {
            nums[j] = nums[j + 1];
        }
        k %= fact[n - 1 - i];
    }
    res[n] = '\0';
    return res;
}
