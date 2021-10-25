clear
sudo rm main
sudo cmake CMakeLists.txt
sudo make
sudo rm input/salida*
sudo rm input/final*

if [ $# = 1 ]; then

sudo ./main input/certo$1.txt input/salida$1.txt
#./main input/salida$1.txt input/final$1.txt

echo "======Diff======"
echo ""
sdiff input/certo$1.txt input/salida$1.txt
#sdiff input/salida$1.txt input/final$1.txt
echo ""
echo ""

else

echo "======test01======"
sudo ./main input/certo01.txt input/salida01.txt
sudo ./main input/salida01.txt input/final01.txt

echo "======test02======"
sudo ./main input/certo02.txt input/salida02.txt
sudo ./main input/salida02.txt input/final02.txt

echo "======test03======"
sudo ./main input/certo03.txt input/salida03.txt
sudo ./main input/salida03.txt input/final03.txt

echo "======test04======"
sudo ./main input/certo04.txt input/salida04.txt
sudo ./main input/salida04.txt input/final04.txt

echo "======test05======"
sudo ./main input/certo05.txt input/salida05.txt
sudo ./main input/salida05.txt input/final05.txt

echo "======test06======"
sudo ./main input/certo06.txt input/salida06.txt
sudo ./main input/salida06.txt input/final06.txt

echo "======test07======"
sudo ./main input/certo07.txt input/salida07.txt
sudo ./main input/salida07.txt input/final07.txt

echo "======test08======"
sudo ./main input/certo08.txt input/salida08.txt
sudo ./main input/salida08.txt input/final08.txt

echo "======test09======"
sudo ./main input/certo09.txt input/salida09.txt
sudo ./main input/salida09.txt input/final09.txt

echo "======test10======"
sudo ./main input/certo10.txt input/salida10.txt
sudo ./main input/salida10.txt input/final10.txt

echo "======test11======"
sudo ./main input/certo11.txt input/salida11.txt
sudo ./main input/salida11.txt input/final11.txt

echo "======test12======"
sudo ./main input/certo12.txt input/salida12.txt
sudo ./main input/salida12.txt input/final12.txt

echo "======test13======"
sudo ./main input/certo13.txt input/salida13.txt
sudo ./main input/salida13.txt input/final13.txt

echo "======test14======"
sudo ./main input/certo14.txt input/salida14.txt
sudo ./main input/salida14.txt input/final14.txt

echo "======test15======"
sudo ./main input/certo15.txt input/salida15.txt
sudo ./main input/salida15.txt input/final15.txt

echo "======test16======"
sudo ./main input/certo16.txt input/salida16.txt
sudo ./main input/salida16.txt input/final16.txt

echo "======test17======"
sudo ./main input/certo17.txt input/salida17.txt
sudo ./main input/salida17.txt input/final17.txt

echo "======test18======"
sudo ./main input/certo18.txt input/salida18.txt
sudo ./main input/salida18.txt input/final18.txt

echo "======test19======"
sudo ./main input/certo19.txt input/salida19.txt
sudo ./main input/salida19.txt input/final19.txt

echo "======test20======"
sudo ./main input/certo20.txt input/salida20.txt
sudo ./main input/salida20.txt input/final20.txt

echo "======Diffs======"
echo "\n1\n"
sdiff input/salida01.txt input/final01.txt
echo "\n2\n"
sdiff input/salida02.txt input/final02.txt
echo "\n3\n"
sdiff input/salida03.txt input/final03.txt
echo "\n4\n"
sdiff input/salida04.txt input/final04.txt
echo "\n5\n"
sdiff input/salida05.txt input/final05.txt
echo "\n6\n"
sdiff input/salida06.txt input/final06.txt
echo "\n7\n"
sdiff input/salida07.txt input/final07.txt
echo "\n8\n"
sdiff input/salida08.txt input/final08.txt
echo "\n9\n"
sdiff input/salida09.txt input/final09.txt
echo "\n10\n"
sdiff input/salida10.txt input/final10.txt
echo "\n11\n"
sdiff input/salida11.txt input/final11.txt
echo "\n12\n"
sdiff input/salida12.txt input/final12.txt
echo "\n13\n"
sdiff input/salida13.txt input/final13.txt
echo "\n14\n"
sdiff input/salida14.txt input/final14.txt
echo "\n15\n"
sdiff input/salida15.txt input/final15.txt
echo "\n16\n"
sdiff input/salida16.txt input/final16.txt
echo "\n17\n"
sdiff input/salida17.txt input/final17.txt
echo "\n18\n"
sdiff input/salida18.txt input/final18.txt
echo "\n19\n"
sdiff input/salida19.txt input/final19.txt
echo "\n20\n"
sdiff input/salida20.txt input/final20.txt

fi
