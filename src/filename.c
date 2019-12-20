#include "asm.h"

int     valid_filename_asm(const char *filename) {
    int filename_len;

    if (!filename || (filename_len = ft_strlen(filename)) == 0 ||
    ft_strcmp((filename + filename_len - EXP_ASM_LEN), EXP_ASM)) // проверка расширения файла
        error();
    return (1);
}