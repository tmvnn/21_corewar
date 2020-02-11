#!/bin/bash
rm -rf my_file not_my_file
./asm champions/batman.s
hexdump -vC champions/batman.cor > my_file
./resources/vm_champs/asm champions/batman.s
hexdump -vC champions/batman.cor > not_my_file
diff my_file not_my_file
