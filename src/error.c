#include "asm.h"

/* Заглушка под ошибку */

void    error() {
    write(1, "error\n", 6);
    exit(-1);
}