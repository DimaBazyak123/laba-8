#include <stdio.h>
#include <string.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int countAnagrams(char* word) {
    int length = strlen(word);
    int counts[26] = {0}; // Масив для підрахунку кількості кожної букви

    // Підрахунок кількості кожної букви у слові
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'A'; // Індекс букви у масиві counts
        counts[index]++;
    }

    // Обчислення кількості анаграм за формулою факторіала
    int totalAnagrams = factorial(length);
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 1) {
            totalAnagrams /= factorial(counts[i]);
        }
    }

    return totalAnagrams;
}

int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);
    
    int anagramCount = countAnagrams(word);
    printf("Кількість анаграм: %d\n", anagramCount);
    
    return 0;
}