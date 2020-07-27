#include <stdlib.h>
#include <stdio.h>

void frequency_count(char *in, int *out){
    for (int i = 0; in[i] != '\0'; i++){
        out[in[i] - 'a']++;
    }
}

char is_anagram(char *a, char *b){
    int freq_a[26] = {0};   /* 26 is the number of letter on the arabic alphabet */
    int freq_b[26] = {0};   /* a b c d e f g h i j k l m n o p q r s t u v w x y z */

    frequency_count(a, freq_a);
    frequency_count(b, freq_b);

    for (int i = 0; i < 26; i++){
        if (freq_a[i] != freq_b[i]){
            return 0;
        }
    }

    return 1;
}

/**
 * How many deletions minimum are required on both strings
 * so that make an anagram of it
 * */
int min_deletions_to_make_anagram(char *a, char *b){
    int freq_a[26] = {0};   /* 26 is the number of letter on the arabic alphabet */
    int freq_b[26] = {0};   /* a b c d e f g h i j k l m n o p q r s t u v w x y z */
    int deletions = 0;

    frequency_count(a, freq_a);
    frequency_count(b, freq_b);

    for (int i = 0; i < 26; i++){
        deletions += abs(freq_a[i] - freq_b[i]);
    }

    return deletions;
}

void main(void){
    char first[] = "abdefgh";
    char second[] = "dbsgaf";
    char third[] = "abcde";
    char fourth[] = "edcba";

    if (is_anagram(first, second)){
        printf("%s and %s : true for anagram\n", first, second);
    } else{
        printf("%s and %s : false for anagram\n", first, second);
    }
    printf("deletions needed to become anagram: %d\n", min_deletions_to_make_anagram(first, second));

    printf("\n");

    if (is_anagram(third, fourth)){
        printf("%s and %s : true for anagram\n", third, fourth);
    } else{
        printf("%s and %s : false for anagram\n", third, fourth);
    }
    printf("deletions needed to become anagram: %d\n", min_deletions_to_make_anagram(third, fourth));

    exit(0);
}
