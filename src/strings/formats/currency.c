#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum location {pt_BR, en_US, LOC_MAX};

char *format_currency(char *in, enum location loc){
    static const char decimalChar[LOC_MAX] = {',', '.'};
    static const char thousandsChar[LOC_MAX] = {'.', ','};

    int len_in, len_out;
    int idx_in, idx_out;
    int amount_points;
    char *tmp;

    len_in = strlen(in);
    idx_in = len_in;
    if (len_in < 3){
        len_in = 3;
    }

    amount_points = ((len_in - 3 )/ 3);
    len_out = len_in + amount_points + 2; // 1 for decimalChar and 1 for '\0'
    tmp = (char *) malloc(len_out);
    sprintf(&tmp[len_out - 5], "0%c00", decimalChar[loc]);

    idx_out = len_out - 1;

    tmp[--idx_out] = in[--idx_in];
    if (idx_in > 0)
        tmp[--idx_out] = in[--idx_in];
    --idx_out;  // the decimal char

    for (int i = 0; i < amount_points; i++){
        idx_out -= 3;
        idx_in -= 3;
        memcpy(&tmp[idx_out], &in[idx_in], 3);
        tmp[--idx_out] = thousandsChar[loc];
    }

    if (idx_in > 0)
        memcpy(tmp, in, idx_in);

    memcpy(in, tmp, len_out);

    free(tmp);
    return in;
}

void main(void){
    char *money_str[] = {
        "10010",
        "230055",
        "23340084",
        "54638488824",
        "123777720000002",
        "32",
        "1"
    };
    char buffer[100];

    for (int i = 0; i < (sizeof(money_str) / sizeof(money_str[0])); i++){
        sprintf(buffer, money_str[i]);
        printf("Formatted value [pt_BR]: %s\n", format_currency(buffer, pt_BR));

        sprintf(buffer, money_str[i]);
        printf("Formatted value [en_US]: %s\n", format_currency(buffer, en_US));
    }

    exit(0);
}
