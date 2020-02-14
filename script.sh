#!/bin/bash
echo ""
echo "batman.s"
./asm champions/batman.s
hexdump -vC champions/batman.cor > my_file
./resources/vm_champs/asm champions/batman.s
hexdump -vC champions/batman.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "bee_gees.s"
./asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > my_file
./resources/vm_champs/asm champions/bee_gees.s
hexdump -vC champions/bee_gees.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "bigzork.s"
./asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > my_file
./resources/vm_champs/asm champions/bigzork.s
hexdump -vC champions/bigzork.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "fluttershy.s"
./asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > my_file
./resources/vm_champs/asm champions/fluttershy.s
hexdump -vC champions/fluttershy.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "helltrain.s"
./asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > my_file
./resources/vm_champs/asm champions/helltrain.s
hexdump -vC champions/helltrain.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "turtle.s"
./asm champions/turtle.s
hexdump -vC champions/turtle.cor > my_file
./resources/vm_champs/asm champions/turtle.s
hexdump -vC champions/turtle.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "zork.s"
./asm champions/zork.s
hexdump -vC champions/zork.cor > my_file
./resources/vm_champs/asm champions/zork.s
hexdump -vC champions/zork.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "42.s"
rm -rf my_file not_my_file champions/*.cor
./asm champions/42.s
hexdump -vC champions/42.cor > my_file
./resources/vm_champs/asm champions/42.s
hexdump -vC champions/42.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Backward.s"
./asm champions/Backward.s
hexdump -vC champions/Backward.cor > my_file
./resources/vm_champs/asm champions/Backward.s
hexdump -vC champions/Backward.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "barriere.s"
./asm champions/barriere.s
hexdump -vC champions/barriere.cor > my_file
./resources/vm_champs/asm champions/barriere.s
hexdump -vC champions/barriere.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Car.s"
./asm champions/Car.s
hexdump -vC champions/Car.cor > my_file
./resources/vm_champs/asm champions/Car.s
hexdump -vC champions/Car.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Death.s"
./asm champions/Death.s
hexdump -vC champions/Death.cor > my_file
./resources/vm_champs/asm champions/Death.s
hexdump -vC champions/Death.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "ex.s"
./asm champions/ex.s
hexdump -vC champions/ex.cor > my_file
./resources/vm_champs/asm champions/ex.s
hexdump -vC champions/ex.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Gagnant.s"
./asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > my_file
./resources/vm_champs/asm champions/Gagnant.s
hexdump -vC champions/Gagnant.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "jumper.s"
./asm champions/jumper.s
hexdump -vC champions/jumper.cor > my_file
./resources/vm_champs/asm champions/jumper.s
hexdump -vC champions/jumper.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "lde.s"
./asm champions/lde.s
hexdump -vC champions/lde.cor > my_file
./resources/vm_champs/asm champions/lde.s
hexdump -vC champions/lde.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "leeloo.s"
./asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > my_file
./resources/vm_champs/asm champions/leeloo.s
hexdump -vC champions/leeloo.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "mat.s"
./asm champions/mat.s
hexdump -vC champions/mat.cor > my_file
./resources/vm_champs/asm champions/mat.s
hexdump -vC champions/mat.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "maxidef.s"
./asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > my_file
./resources/vm_champs/asm champions/maxidef.s
hexdump -vC champions/maxidef.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "mortel.s"
./asm champions/mortel.s
hexdump -vC champions/mortel.cor > my_file
./resources/vm_champs/asm champions/mortel.s
hexdump -vC champions/mortel.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "new.s"
./asm champions/new.s
hexdump -vC champions/new.cor > my_file
./resources/vm_champs/asm champions/new.s
hexdump -vC champions/new.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Octobre_Rouge_V4.2.s"
./asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > my_file
./resources/vm_champs/asm champions/Octobre_Rouge_V4.2.s
hexdump -vC champions/Octobre_Rouge_V4.2.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "sebc.s"
./asm champions/sebc.s
hexdump -vC champions/sebc.cor > my_file
./resources/vm_champs/asm champions/sebc.s
hexdump -vC champions/sebc.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "slider2.s"
./asm champions/slider2.s
hexdump -vC champions/slider2.cor > my_file
./resources/vm_champs/asm champions/slider2.s
hexdump -vC champions/slider2.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Survivor.s"
./asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > my_file
./resources/vm_champs/asm champions/Survivor.s
hexdump -vC champions/Survivor.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "tdc2.s"
./asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > my_file
./resources/vm_champs/asm champions/tdc2.s
hexdump -vC champions/tdc2.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "tdc3.s"
./asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > my_file
./resources/vm_champs/asm champions/tdc3.s
hexdump -vC champions/tdc3.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "tdc4.s"
./asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > my_file
./resources/vm_champs/asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Torpille.s"
./asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > my_file
./resources/vm_champs/asm champions/Torpille.s
hexdump -vC champions/Torpille.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "toto.s"
./asm champions/toto.s
hexdump -vC champions/toto.cor > my_file
./resources/vm_champs/asm champions/toto.s
hexdump -vC champions/toto.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "_.s"
./asm champions/_.s
hexdump -vC champions/_.cor > my_file
./resources/vm_champs/asm champions/_.s
hexdump -vC champions/_.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "_honeybadger.s"
./asm champions/_honeybadger.s
hexdump -vC champions/_honeybadger.cor > my_file
./resources/vm_champs/asm champions/_honeybadger.s
hexdump -vC champions/_honeybadger.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Asombra.s"
./asm champions/Asombra.s
hexdump -vC champions/Asombra.cor > my_file
./resources/vm_champs/asm champions/Asombra.s
hexdump -vC champions/Asombra.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Bazou.s"
./asm champions/Bazou.s
hexdump -vC champions/Bazou.cor > my_file
./resources/vm_champs/asm champions/Bazou.s
hexdump -vC champions/Bazou.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "big_feet.s"
./asm champions/big_feet.s
hexdump -vC champions/big_feet.cor > my_file
./resources/vm_champs/asm champions/big_feet.s
hexdump -vC champions/big_feet.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "casimir.s"
./asm champions/casimir.s
hexdump -vC champions/casimir.cor > my_file
./resources/vm_champs/asm champions/casimir.s
hexdump -vC champions/casimir.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "champ.s"
./asm champions/champ.s
hexdump -vC champions/champ.cor > my_file
./resources/vm_champs/asm champions/champ.s
hexdump -vC champions/champ.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Code_eater.s"
rm -rf my_file not_my_file champions/*.cor
./asm champions/Code_eater.s
hexdump -vC champions/Code_eater.cor > my_file
./resources/vm_champs/asm champions/Code_eater.s
hexdump -vC champions/Code_eater.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "corelol.s"
./asm champions/corelol.s
hexdump -vC champions/corelol.cor > my_file
./resources/vm_champs/asm champions/corelol.s
hexdump -vC champions/corelol.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "darksasuke.s"
./asm champions/darksasuke.s
hexdump -vC champions/darksasuke.cor > my_file
./resources/vm_champs/asm champions/darksasuke.s
hexdump -vC champions/darksasuke.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "doge.s"
./asm champions/doge.s
hexdump -vC champions/doge.cor > my_file
./resources/vm_champs/asm champions/doge.s
hexdump -vC champions/doge.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Douceur_power.s"
./asm champions/Douceur_power.s
hexdump -vC champions/Douceur_power.cor > my_file
./resources/vm_champs/asm champions/Douceur_power.s
hexdump -vC champions/Douceur_power.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "dubo.s"
./asm champions/dubo.s
hexdump -vC champions/dubo.cor > my_file
./resources/vm_champs/asm champions/dubo.s
hexdump -vC champions/dubo.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "echo.s"
./asm champions/echo.s
hexdump -vC champions/echo.cor > my_file
./resources/vm_champs/asm champions/echo.s
hexdump -vC champions/echo.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Eraser.s"
./asm champions/Eraser.s
hexdump -vC champions/Eraser.cor > my_file
./resources/vm_champs/asm champions/Eraser.s
hexdump -vC champions/Eraser.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Explosive_Kitty.s"
./asm champions/Explosive_Kitty.s
hexdump -vC champions/Explosive_Kitty.cor > my_file
./resources/vm_champs/asm champions/Explosive_Kitty.s
hexdump -vC champions/Explosive_Kitty.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "fast.s"
./asm champions/fast.s
hexdump -vC champions/fast.cor > my_file
./resources/vm_champs/asm champions/fast.s
hexdump -vC champions/fast.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "ForgottenOne.s"
./asm champions/ForgottenOne.s
hexdump -vC champions/ForgottenOne.cor > my_file
./resources/vm_champs/asm champions/ForgottenOne.s
hexdump -vC champions/ForgottenOne.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "gateau.s"
./asm champions/gateau.s
hexdump -vC champions/gateau.cor > my_file
./resources/vm_champs/asm champions/gateau.s
hexdump -vC champions/gateau.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "gedeon.s"
./asm champions/gedeon.s
hexdump -vC champions/gedeon.cor > my_file
./resources/vm_champs/asm champions/gedeon.s
hexdump -vC champions/gedeon.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Hidden.s"
./asm champions/Hidden.s
hexdump -vC champions/Hidden.cor > my_file
./resources/vm_champs/asm champions/Hidden.s
hexdump -vC champions/Hidden.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Horace.s"
./asm champions/Horace.s
hexdump -vC champions/Horace.cor > my_file
./resources/vm_champs/asm champions/Horace.s
hexdump -vC champions/Horace.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Izi_Miaou.s"
./asm champions/Izi_Miaou.s
hexdump -vC champions/Izi_Miaou.cor > my_file
./resources/vm_champs/asm champions/Izi_Miaou.s
hexdump -vC champions/Izi_Miaou.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "jinx.s"
./asm champions/jinx.s
hexdump -vC champions/jinx.cor > my_file
./resources/vm_champs/asm champions/jinx.s
hexdump -vC champions/jinx.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "justen_bee.s"
./asm champions/justen_bee.s
hexdump -vC champions/justen_bee.cor > my_file
./resources/vm_champs/asm champions/justen_bee.s
hexdump -vC champions/justen_bee.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "kamelkaze.s"
./asm champions/kamelkaze.s
hexdump -vC champions/kamelkaze.cor > my_file
./resources/vm_champs/asm champions/kamelkaze.s
hexdump -vC champions/kamelkaze.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Kappa.s"
./asm champions/Kappa.s
hexdump -vC champions/Kappa.cor > my_file
./resources/vm_champs/asm champions/Kappa.s
hexdump -vC champions/Kappa.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "katchup.s"
./asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > my_file
./resources/vm_champs/asm champions/tdc4.s
hexdump -vC champions/tdc4.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Kitty_Miaou.s"
./asm champions/Kitty_Miaou.s
hexdump -vC champions/Kitty_Miaou.cor > my_file
./resources/vm_champs/asm champions/Kitty_Miaou.s
hexdump -vC champions/Kitty_Miaou.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Kittystrophic.s"
./asm champions/Kittystrophic.s
hexdump -vC champions/Kittystrophic.cor > my_file
./resources/vm_champs/asm champions/Kittystrophic.s
hexdump -vC champions/Kittystrophic.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "lapsang.s"
./asm champions/lapsang.s
hexdump -vC champions/lapsang.cor > my_file
./resources/vm_champs/asm champions/lapsang.s
hexdump -vC champions/lapsang.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "le_pet_de_nonne.s"
./asm champions/le_pet_de_nonne.s
hexdump -vC champions/le_pet_de_nonne.cor > my_file
./resources/vm_champs/asm champions/le_pet_de_nonne.s
hexdump -vC champions/le_pet_de_nonne.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "littlepuppy.s"
./asm champions/littlepuppy.s
hexdump -vC champions/littlepuppy.cor > my_file
./resources/vm_champs/asm champions/littlepuppy.s
hexdump -vC champions/littlepuppy.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "live.s"
./asm champions/live.s
hexdump -vC champions/live.cor > my_file
./resources/vm_champs/asm champions/live.s
hexdump -vC champions/live.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "loose.s"
./asm champions/loose.s
hexdump -vC champions/loose.cor > my_file
./resources/vm_champs/asm champions/loose.s
hexdump -vC champions/loose.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "lou_forktologue.s"
./asm champions/lou_forktologue.s
hexdump -vC champions/lou_forktologue.cor > my_file
./resources/vm_champs/asm champions/lou_forktologue.s
hexdump -vC champions/lou_forktologue.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Machine-gun.s"
./asm champions/Machine-gun.s
hexdump -vC champions/Machine-gun.cor > my_file
./resources/vm_champs/asm champions/Machine-gun.s
hexdump -vC champions/Machine-gun.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "mandragore.s"
rm -rf my_file not_my_file champions/*.cor
./asm champions/mandragore.s
hexdump -vC champions/mandragore.cor > my_file
./resources/vm_champs/asm champions/mandragore.s
hexdump -vC champions/mandragore.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "MarineKing.s"
./asm champions/MarineKing.s
hexdump -vC champions/MarineKing.cor > my_file
./resources/vm_champs/asm champions/MarineKing.s
hexdump -vC champions/MarineKing.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "master_of_puppets.s"
./asm champions/master_of_puppets.s
hexdump -vC champions/master_of_puppets.cor > my_file
./resources/vm_champs/asm champions/master_of_puppets.s
hexdump -vC champions/master_of_puppets.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "meowluigi.s"
./asm champions/meowluigi.s
hexdump -vC champions/meowluigi.cor > my_file
./resources/vm_champs/asm champions/meowluigi.s
hexdump -vC champions/meowluigi.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Misaka_Mikoto.s"
./asm champions/Misaka_Mikoto.s
hexdump -vC champions/Misaka_Mikoto.cor > my_file
./resources/vm_champs/asm champions/Misaka_Mikoto.s
hexdump -vC champions/Misaka_Mikoto.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "mise_a_jour_windows95.s"
./asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > my_file
./resources/vm_champs/asm champions/mise_a_jour_windows95.s
hexdump -vC champions/mise_a_jour_windows95.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Noidea.s"
./asm champions/Noidea.s
hexdump -vC champions/Noidea.cor > my_file
./resources/vm_champs/asm champions/Noidea.s
hexdump -vC champions/Noidea.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "O-Maley_Miaou.s"
./asm champions/O-Maley_Miaou.s
hexdump -vC champions/O-Maley_Miaou.cor > my_file
./resources/vm_champs/asm champions/O-Maley_Miaou.s
hexdump -vC champions/O-Maley_Miaou.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "overwatch.s"
./asm champions/overwatch.s
hexdump -vC champions/overwatch.cor > my_file
./resources/vm_champs/asm champions/overwatch.s
hexdump -vC champions/overwatch.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "pai_mu_tan.s"
./asm champions/pai_mu_tan.s
hexdump -vC champions/pai_mu_tan.cor > my_file
./resources/vm_champs/asm champions/pai_mu_tan.s
hexdump -vC champions/pai_mu_tan.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Rainbow_dash.s"
./asm champions/Rainbow_dash.s
hexdump -vC champions/Rainbow_dash.cor > my_file
./resources/vm_champs/asm champions/Rainbow_dash.s
hexdump -vC champions/Rainbow_dash.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "run_Kitty_RUN.s"
./asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > my_file
./resources/vm_champs/asm champions/run_Kitty_RUN.s
hexdump -vC champions/run_Kitty_RUN.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "salamahenagalabadoun.s"
./asm champions/salamahenagalabadoun.s
hexdump -vC champions/salamahenagalabadoun.cor > my_file
./resources/vm_champs/asm champions/salamahenagalabadoun.s
hexdump -vC champions/salamahenagalabadoun.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "sam_2.0.s"
./asm champions/sam_2.0.s
hexdump -vC champions/sam_2.0.cor > my_file
./resources/vm_champs/asm champions/sam_2.0.s
hexdump -vC champions/sam_2.0.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "sencha.s"
./asm champions/sencha.s
hexdump -vC champions/sencha.cor > my_file
./resources/vm_champs/asm champions/sencha.s
hexdump -vC champions/sencha.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "skynet.s"
./asm champions/skynet.s
hexdump -vC champions/skynet.cor > my_file
./resources/vm_champs/asm champions/skynet.s
hexdump -vC champions/skynet.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Stargate0_1.s"
./asm champions/Stargate0_1.s
hexdump -vC champions/Stargate0_1.cor > my_file
./resources/vm_champs/asm champions/Stargate0_1.s
hexdump -vC champions/Stargate0_1.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "tchupka.s"
./asm champions/tchupka.s
hexdump -vC champions/tchupka.cor > my_file
./resources/vm_champs/asm champions/tchupka.s
hexdump -vC champions/tchupka.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "terminator.s"
./asm champions/terminator.s
hexdump -vC champions/terminator.cor > my_file
./resources/vm_champs/asm champions/terminator.s
hexdump -vC champions/terminator.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "TheHarvester.s"
./asm champions/TheHarvester.s
hexdump -vC champions/TheHarvester.cor > my_file
./resources/vm_champs/asm champions/TheHarvester.s
hexdump -vC champions/TheHarvester.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "THUNDER.s"
./asm champions/THUNDER.s
hexdump -vC champions/THUNDER.cor > my_file
./resources/vm_champs/asm champions/THUNDER.s
hexdump -vC champions/THUNDER.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "ultima.s"
./asm champions/ultima.s
hexdump -vC champions/ultima.cor > my_file
./resources/vm_champs/asm champions/ultima.s
hexdump -vC champions/ultima.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "ultimate-surrender.s"
./asm champions/ultimate-surrender.s
hexdump -vC champions/ultimate-surrender.cor > my_file
./resources/vm_champs/asm champions/ultimate-surrender.s
hexdump -vC champions/ultimate-surrender.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Varimathras.s"
./asm champions/Varimathras.s
hexdump -vC champions/Varimathras.cor > my_file
./resources/vm_champs/asm champions/Varimathras.s
hexdump -vC champions/Varimathras.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "Wall.s"
./asm champions/Wall.s
hexdump -vC champions/Wall.cor > my_file
./resources/vm_champs/asm champions/Wall.s
hexdump -vC champions/Wall.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "wave.s"
./asm champions/wave.s
hexdump -vC champions/wave.cor > my_file
./resources/vm_champs/asm champions/wave.s
hexdump -vC champions/wave.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor
echo "youforkmytralala.s"
./asm champions/youforkmytralala.s
hexdump -vC champions/youforkmytralala.cor > my_file
./resources/vm_champs/asm champions/youforkmytralala.s
hexdump -vC champions/youforkmytralala.cor > not_my_file
if (diff my_file not_my_file)
then
    echo "OK"
else
    echo "KO"
fi
rm -rf my_file not_my_file champions/*.cor