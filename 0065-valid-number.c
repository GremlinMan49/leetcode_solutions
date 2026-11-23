// 65. Valid Number (Hard)
// https://leetcode.com/problems/valid-number/

bool isNumber(char* s) {
    bool seenDigit = false, seenExponent = false, seenDot = false;
    int i = 0;
    if (s[0] == '+' || s[0] == '-') i++;
    
    for (; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            seenDigit = true;
        } else if (c == '.') {
            if (seenDot || seenExponent) return false;
            seenDot = true;
        } else if (c == 'e' || c == 'E') {
            if (seenExponent || !seenDigit) return false;
            seenExponent = true;
            seenDigit = false;
        } else if (c == '+' || c == '-') {
            if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;
        } else {
            return false;
        }
    }
    return seenDigit;
}
