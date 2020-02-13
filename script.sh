#!/bin/bash
echo ""
echo "batman.s"
rm -rf my_file not_my_file champions/*.cor
./asm champions/batman.s
hexdump -vC champions/batman.cor > my_file
./resources/vm_champs/asm champions/batman.s
hexdump -vC champions/batman.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "bee_gees.s"
./asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > my_file
./resources/vm_champs/asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "bigzork.s"
./asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > my_file
./resources/vm_champs/asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "fluttershy.s"
./asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > my_file
./resources/vm_champs/asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "helltrain.s"
./asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > my_file
./resources/vm_champs/asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "turtle.s"
./asm champions/turtle.s
hexdump -vC champions/turtle.cor > my_file
./resources/vm_champs/asm champions/turtle.s
hexdump -vC champions/turtle.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "zork.s"
./asm champions/zork.s
hexdump -vC champions/zork.cor > my_file
./resources/vm_champs/asm champions/zork.s
hexdump -vC champions/zork.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "42.s"
rm -rf my_file not_my_file champions/*.cor
./asm champions/42.s
hexdump -vC champions/42.cor > my_file
./resources/vm_champs/asm champions/42.s
hexdump -vC champions/42.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "Backward.s"
./asm champions/Backward.s
hexdump -vC champions/Backward.cor > my_file
./resources/vm_champs/asm champions/Backward.s
hexdump -vC champions/Backward.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "barriere.s"
./asm champions/barriere.s
hexdump -vC champions/barriere.cor > my_file
./resources/vm_champs/asm champions/barriere.s
hexdump -vC champions/barriere.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "Car.s"
./asm champions/Car.s
hexdump -vC champions/Car.cor > my_file
./resources/vm_champs/asm champions/Car.s
hexdump -vC champions/Car.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "Death.s"
./asm champions/Death.s
hexdump -vC champions/Death.cor > my_file
./resources/vm_champs/asm champions/Death.s
hexdump -vC champions/Death.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "ex.s"
./asm champions/ex.s
hexdump -vC champions/ex.cor > my_file
./resources/vm_champs/asm champions/ex.s
hexdump -vC champions/ex.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "Gagnant.s"
./asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > my_file
./resources/vm_champs/asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "jumper.s"
./asm champions/jumper.s
hexdump -vC champions/jumper.cor > my_file
./resources/vm_champs/asm champions/jumper.s
hexdump -vC champions/jumper.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "lde.s"
./asm champions/lde.s
hexdump -vC champions/lde.cor > my_file
./resources/vm_champs/asm champions/lde.s
hexdump -vC champions/lde.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "leeloo.s"
./asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > my_file
./resources/vm_champs/asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "mat.s"
./asm champions/mat.s
hexdump -vC champions/mat.cor > my_file
./resources/vm_champs/asm champions/mat.s
hexdump -vC champions/mat.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "maxidef.s"
./asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > my_file
./resources/vm_champs/asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "mortel.s"
./asm champions/mortel.s
hexdump -vC champions/mortel.cor > my_file
./resources/vm_champs/asm champions/mortel.s
hexdump -vC champions/mortel.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "new.s"
./asm champions/new.s
hexdump -vC champions/new.cor > my_file
./resources/vm_champs/asm champions/new.s
hexdump -vC champions/new.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "Octobre_Rouge_V4.2.s"
./asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > my_file
./resources/vm_champs/asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "sebc.s"
./asm champions/sebc.s
hexdump -vC champions/sebc.cor > my_file
./resources/vm_champs/asm champions/sebc.s
hexdump -vC champions/sebc.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "slider2.s"
./asm champions/slider2.s
hexdump -vC champions/slider2.cor > my_file
./resources/vm_champs/asm champions/slider2.s
hexdump -vC champions/slider2.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "Survivor.s"
./asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > my_file
./resources/vm_champs/asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "tdc2.s"
./asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > my_file
./resources/vm_champs/asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "tdc3.s"
./asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > my_file
./resources/vm_champs/asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "tdc4.s"
./asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > my_file
./resources/vm_champs/asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "Torpille.s"
./asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > my_file
./resources/vm_champs/asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
echo "toto.s"
./asm champions/toto.s
hexdump -vC champions/toto.cor > my_file
./resources/vm_champs/asm champions/toto.s
hexdump -vC champions/toto.cor > not_my_file
diff my_file not_my_file
rm -rf my_file not_my_file champions/*.cor
