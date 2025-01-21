#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    //save lengths of both strings
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    //allocate space for merged word and check that malloc worked
    //size of word is size of both words +1
    char *mergedWord = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (!mergedWord) return NULL;

    //init counters for each string
    int i = 0, j = 0, k = 0;

    //append letters while word counters aren't at word length
    while (i < len1 && j < len2) {
        mergedWord[k++] = word1[i++];
        mergedWord[k++] = word2[j++];
    }

    //append the rest of the longer word
    while (i < len1) {
        mergedWord[k++] = word1[i++];
    }
    while (j < len2) {
        mergedWord[k++] = word2[j++];
    }

    //null terminate merged string
    mergedWord[k] = '\0';

    return mergedWord;
}

int main() {
    char word1[] = "abc";
    char word2[] = "uvwxyz";

    //char word3[20] = mergeAlternately(word1, word2);

    printf("Merged Word: %s\n", mergeAlternately(word1, word2));


    return 0;
}