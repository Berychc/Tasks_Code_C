#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicatiesString(char *str);

void removeDuplicatiesString(char *str) {
    int len = strlen(str);
    bool seen[256] = {false};

    char *temp = str;
    char *dst = str;

    while(*temp != '\0') {
        if(!seen[(unsigned char)*temp]) {
            seen[(unsigned char)*temp] = true;
            *dst++ = *temp;
        }
        temp++;
    }
    *dst = '\0';
}

int main() {
    char str[] = "geeksforgeeks";
    printf("Исходная строка: %s\n", str);

    removeDuplicatiesString(str);

    printf("Строка после удаления дубликатов: %s\n", str);

    return 0;
}