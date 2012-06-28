#ifndef __country_code__
#define __country_code__

struct country{
    char *alias,*name;/* diminutif,nom */
};
extern struct country country_code[263]; /* extern car c'est une variable global */

int country_alias2code(char *alias);
const char *country_alias2name(char *alias);
int country_name2code(char *name);
const char *country_name2alias(char *name);
const char *country_code2name(int code);
const char *country_code2alias(int code);

#endif
