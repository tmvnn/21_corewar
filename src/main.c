#include "asm.h"

/* 
* Входная точка, проверка на отсутствие файла:
*   Проверка валидности названия
*   Вход в точку начала компиляции
*/

int main(int argc, char **argv) {
    if (argc == 0)
        error();
    if (valid_filename_asm(*(argv + 1)))
        assemble(*(argv + 1));
    else
        error();
    return (0);
}