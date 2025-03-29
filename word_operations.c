#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold word and its length
struct Word {
    char word[100];
    int length;
};

// Comparator function for sorting based on word length
int compare(const void *a, const void *b) {
    return ((struct Word *)a)->length - ((struct Word *)b)->length;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    struct Word words[N];

    // Reading N words and calculating lengths
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i].word);
        words[i].length = strlen(words[i].word);
    }

    // Sorting words based on length
    qsort(words, N, sizeof(struct Word), compare);

    // Calculating operations for each word
    for (int i = 0; i < K; i++) {
        char word[100];
        scanf("%s", word);
        int len = strlen(word);
        int operations = 0;

        // Finding the corresponding word in sorted array
        int j = 0;
        while (j < N && words[j].length < len) {
            operations += words[j].length;
            j++;
        }

        // Calculating operations for current word
        for (int k = 0; k < len; k++) {
            if (j < N && words[j].word[k] == word[k]) {
                j++;
            } else {
                operations++;
                j = N; // Reset j to N to indicate a mismatch
            }
        }

        printf("%d\n", operations);
    }

    return 0;
}
