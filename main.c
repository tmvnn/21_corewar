#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#define PATTERN_NAME_CHAMPS "^ *.name *\".{0,128}\" *[#;].*$"
#define PATTERN_NAME_COMMENT "^ *.comment *\".{0,2048}\" *[#;].*$"
#define PATTERN_COMMENT "^ *#.*$"
#define PATTERN_ALTER_COMMENT "^ *;.*$"
#define PATTERN_EMPTY_LINE "|"
#define djfksljf "*r[0-9]{1,2}$ *[#;].*$"
#define PATTERN_LABEL "^ *[a-z0-9_]+: *((live|zjmp|fork|lfork) *(%-?0*[0-9]+|%:[0-9a-z_]+)|(ld|lld) *(%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+) *, *r[0-9]{1,2}|st *r[0-9]{1,2} *, *(r[0-9]{1,2}|-?[0-9]+|:[0-9a-z_]+)|(add|sub) *r[0-9]{1,2} *, *r[0-9]{1,2} *, *r[0-9]{1,2}|(and|or|xor) *(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+) *, *(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+) *, *r[0-9]{1,2}|(ldi|lldi) *(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+) *, *(r[0-9]{1,2}|%-?0*[0-9]+$|^%:[0-9a-z_]+) *, *r[0-9]{1,2}|sti *r[0-9]{1,2} *, *(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+) *, *(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+)) *([#;].*| *)$"

int main(int ac, char **av){
	int err;
	regex_t reg1;
	if (ac != 2)
		return (0);
	err = regcomp(&reg1, PATTERN_LABEL, REG_EXTENDED);
	if (err != 0){
		printf("error with regex in file interpretation.c\n");
		return (0);
	}
	printf("%lu\n", strlen(*(av + 1)));
	regmatch_t pm;
	if (!regexec(&reg1, *(av + 1), 0, &pm, 0)){
		printf("good match\n");
		return (1);
	} else{
		printf("bad match\n");
	}
	return (0);
}