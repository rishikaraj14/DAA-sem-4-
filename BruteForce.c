#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pattern[50];
    int i, j;
    int textLen, patternLen;
    int found = 0;

    // Input main string
    printf("Enter the main string: ");
    gets(text);

    // Input pattern string
    printf("Enter the pattern string: ");
    gets(pattern);

    textLen = strlen(text);
    patternLen = strlen(pattern);

    // Brute force string matching
    for (i = 0; i <= textLen - patternLen; i++) {
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found in the given text.\n");
    }

    return 0;
}
