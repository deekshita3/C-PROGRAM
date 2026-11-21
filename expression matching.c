#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    int m = strlen(s);
    int n = strlen(p);

    bool dp[m + 1][n + 1];

    memset(dp, false, sizeof(dp));

    dp[0][0] = true;

    // Handle patterns like a*, a*b*, etc.
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (p[j - 1] == '.' ||
                p[j - 1] == s[i - 1]) {

                dp[i][j] = dp[i - 1][j - 1];
            }

            else if (p[j - 1] == '*') {

                dp[i][j] = dp[i][j - 2];

                if (p[j - 2] == '.' ||
                    p[j - 2] == s[i - 1]) {

                    dp[i][j] = dp[i][j] ||
                               dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    char s[100], p[100];

    printf("Enter string: ");
    scanf("%99s", s);

    printf("Enter pattern: ");
    scanf("%99s", p);

    if (isMatch(s, p)) {
        printf("Match Found\n");
    } else {
        printf("Match Not Found\n");
    }

    return 0;
}
