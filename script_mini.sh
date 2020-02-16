#!/bin/bash
./asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > my_file
./resources/vm_champs/asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > not_my_file
diff my_file not_my_file