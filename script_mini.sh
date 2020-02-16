#!/bin/bash
./asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > my_file
./resources/vm_champs/asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > not_my_file
diff my_file not_my_file
