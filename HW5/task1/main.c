#include <stdio.h>
#include <string.h>

int count_unique_numbers(const char *s, int len) {
    if (len < 3) {
        return 0;
    }

    int flags[900] = {0};

    for (int i = 0; i <= len - 3; ++i) {
        if (s[i] == '0') continue;

        for (int j = i + 1; j <= len - 2; ++j) {
            for (int k = j + 1; k <= len - 1; ++k) {
                int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                flags[num - 100] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 900; ++i) {
        if (flags[i]) ++count;
    }

    return count;
}

int main() {
    char s[1000];
    scanf("%s", s);
    int len = strlen(s);

    int result = count_unique_numbers(s, len);
    printf("%d\n", result);

    return 0;
}