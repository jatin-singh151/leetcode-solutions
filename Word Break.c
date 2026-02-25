#include <stdbool.h>
#include <string.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool dp[n + 1];
    
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                int len = i - j;
                for (int k = 0; k < wordDictSize; k++) {
                    if (strlen(wordDict[k]) == len &&
                        strncmp(s + j, wordDict[k], len) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[i]) break;
        }
    }
    return dp[n];
}
