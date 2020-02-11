#!/bin/bash
./asm champions/turtle.s
hexdump -vC champions/turtle.cor > file
resources/vm_champs/./asm champions/turtle.s
hexdump -vC champions/turtle.cor > file2
diff file file2
