// 58. Length of Last Word (Easy)
// https://leetcode.com/problems/length-of-last-word/

int lengthOfLastWord(char* s) {
    int len = 0;
    int i = strlen(s) - 1;
    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }
    return len;
}
