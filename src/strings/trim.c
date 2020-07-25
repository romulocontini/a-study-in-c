#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_SPACECHAR(x) isspace(x)      /* based on your desire, you could use:
                                        ** isspace (ctype.h)
                                        **      checks for white-space characters. In the "C" and "POSIX" locales,
                                        **      these are: space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
                                        **      horizontal tab ('\t'), and vertical tab ('\v').
                                        **
                                        ** isblank (ctype.h)
                                        **      checks for a blank character; that is, a space or a tab.
                                        ** 
                                        ** or, create your own macro or inline functions as:
                                        ** #define IS_SPACECHAR(x) ((x) == ' ' || (x) == '\t')
                                        ** #define IS_SPACECHAR(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z')) */

/* Given the input, it returns the reference of the same
** string where it's not a space (e.g. left trim) */
char *ltrim(char *in){
    while (IS_SPACECHAR(*in)) ++in;
    return in;
}

/* Given the input, it shift the contents where the
** first position is not a space, modifying the origina string */
void ltrim_modify(char *in){
    char *out;

    for (out = in; IS_SPACECHAR(*in); in++);
    if (in == out) return;

    while(*out++ = *in++);
}

/* Given the input, it set \0 char after the last 
** non-space character */
char *rtrim(char *in){
    char *p = in;

    while (*p) p++;
    while (IS_SPACECHAR(*(--p)));
    p[1] = '\0';

    return in;
}

char *trim(char *in){
    return rtrim(ltrim(in));
}

void main(void){
    char str_ltrim[] = {"  t es ts    "};
    char str_rtrim[] = {"  bla bla bla    "};
    char str_trim[] = {"  ha hu he haha    "};

    printf("** 1. ltrim\n");
    printf("*  original string: |%s|\n", str_ltrim);
    printf("*  ltrimmed string (by reference - does not modify the original string): |%s|\n\n", ltrim(str_ltrim));

    printf("*  original string: |%s|\n", str_ltrim);
    ltrim_modify(str_ltrim);
    printf("*  modified string after ltrim_modify call: |%s|\n", str_ltrim);

    printf("\n\n");

    printf("** 2. rtrim\n");
    printf("*  original string: |%s|\n", str_rtrim);
    printf("*  rtrimmed string: |%s|\n\n", rtrim(str_rtrim));

    printf("\n\n");

    printf("** 3. trim\n");
    printf("*  original string: |%s|\n", str_trim);
    printf("*  trimmed string: |%s|\n\n", trim(str_trim));
    printf("*  string after trim call (as we call ltrim by referente, it does not modify on the left): |%s|\n\n", str_trim);

    exit(0);
}
