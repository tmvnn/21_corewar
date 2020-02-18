#!/bin/bash
./asm champions/lde.s
valgrind --log-file="check_leak" --leak-check=full ./asm champions/lde.s
hexdump -vC champions/lde.cor > my_file
./resources/vm_champs/asm champions/lde.s
hexdump -vC champions/lde.cor > not_my_file
if (diff my_file not_my_file)
then
echo "[OK]"
else
echo "[KO]"
fi
./check