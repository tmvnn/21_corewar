#!/bin/bash
rm -rf my_file not_my_file
./asm champions/turtle.s
hexdump -vC champions/turtle.cor > my_file
./resources/vm_champs/asm champions/turtle.s
hexdump -vC champions/turtle.cor > not_my_file
diff my_file not_my_file
