#include <stdio.h>
#include <string.h>
#include <ctype.h>

int bruteForceCount(char text[], char pattern[]) {
    int count = 0;
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            count++;
    }
    return count;
}

int caseSensitive(char text[], char pattern[]) {
    return bruteForceCount(text, pattern);
}

int caseInsensitive(char text[], char pattern[]) {
    char t[200], p[100];

    strcpy(t, text);
    strcpy(p, pattern);

    for (int i = 0; t[i]; i++)
        t[i] = tolower(t[i]);

    for (int i = 0; p[i]; i++)
        p[i] = tolower(p[i]);

    return bruteForceCount(t, p);
}



int spaceSensitive(char text[], char pattern[]) {
    return bruteForceCount(text, pattern);
}

void removeSpaces(char src[], char dest[]) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] != ' ')
            dest[j++] = src[i];
    }
    dest[j] = '\0';
}

int spaceInsensitive(char text[], char pattern[]) {
    char t[200], p[100];
    removeSpaces(text, t);
    removeSpaces(pattern, p);
    return bruteForceCount(t, p);
}


int main() {
    char text[200], pattern[100];

    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern: ");
    gets(pattern);

    printf("\nCase 1: Case Sensitive Count = %d",
           caseSensitive(text, pattern));

    printf("\nCase 2: Case Insensitive Count = %d",
           caseInsensitive(text, pattern));

    printf("\nCase 3: Space Sensitive Count = %d",
           spaceSensitive(text, pattern));

    printf("\nCase 4: Space Insensitive Count = %d",
           spaceInsensitive(text, pattern));

    return 0;
}
