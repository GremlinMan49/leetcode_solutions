// 71. Simplify Path (Medium)
// https://leetcode.com/problems/simplify-path/

char* simplifyPath(char* path) {
    int len = strlen(path);
    char** stack = (char**)malloc(len * sizeof(char*));
    int top = 0;
    
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top > 0) top--;
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }
    
    char* res = (char*)malloc((len + 1) * sizeof(char));
    res[0] = '\0';
    for (int i = 0; i < top; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    if (top == 0) {
        strcat(res, "/");
    }
    return res;
}
