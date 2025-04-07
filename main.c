#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100

void removeDuplicatiesString(char *str);
void returnFirstStr(const char* str);

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

// Структура для хранения слова и его частоты
typedef struct WordInfo {
    char *word;
    int count;
} WordInfo;

void returnFirstStr(const char* str) {
    char *token;
    char buffer[256]; // Буфер для строки
    strcpy(buffer, str); // Копируем строку в буфер

    // Массив для хранения слов и их частот
    WordInfo words[MAX_WORDS];
    int numWords = 0;

    token = strtok(buffer, " "); // Разбиваем строку на токены
    while (token != NULL && numWords < MAX_WORDS) {
        int i;
        // Проверяем, есть ли слово уже в списке
        for (i = 0; i < numWords; ++i) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                break;
            }
        }
        // Если слова еще нет, добавляем его
        if (i == numWords) {
            words[numWords].word = strdup(token);
            words[numWords].count = 1;
            numWords++;
        }
        token = strtok(NULL, " ");
    }
    // Находим первое слово в лексикографическом порядке
    char *firstWord = words[0].word;
    for (int i = 1; i < numWords; ++i) {
        if (strcmp(firstWord, words[i].word) > 0) {
            firstWord = words[i].word;
        }
    }
    printf("first word -> %s\n", firstWord);
}