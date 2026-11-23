// 3. Longest Substring Without Repeating Characters (Medium)
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

int lengthOfLongestSubstring(char* s) {
    int last[256];
    for (int i = 0; i < 256; i++)
        last[i] = -1;                 // -1 = not seen yet

    int best = 0, start = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        unsigned char c = s[i];
        if (last[c] >= start)         // seen inside the current window
            start = last[c] + 1;      // move the window past it
        last[c] = i;

        if (i - start + 1 > best)
            best = i - start + 1;
    }
    return best;
}


