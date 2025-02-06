#include <stdio.h>
#include <string.h>

int find_prefix_suffix_length(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_len = 0;

    for (int i = 1; i <= len1 && i <= len2; ++i)
        if (strncmp(str1, str2 + len2 - i, i) == 0) {
            max_len = i;
        }

    return max_len;
}

int main() {
    char str1[100], str2[100];

    scanf("%s", str1);
    scanf("%s", str2);

    int prefix_suffix_len = find_prefix_suffix_length(str1, str2);
    int suffix_prefix_len = find_prefix_suffix_length(str2, str1);
    
    printf("%d %d\n", prefix_suffix_len, suffix_prefix_len);

    return 0;
}