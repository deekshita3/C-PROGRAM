#include <stdio.h>
#include <string.h>

void longestPalindrome(char str[]) {
    int n = strlen(str);
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        int left = i, right = i;

        // Odd length palindrome
        while (left >= 0 && right < n &&
               str[left] == str[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        // Even length palindrome
        left = i;
        right = i + 1;

        while (left >= 0 && right < n &&
               str[left] == str[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", str[i]);
    }

    printf("\nLength: %d\n", maxLen);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%99s", str);

    longestPalindrome(str);

    return 0;
}
