all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/DugumAgac.cpp -o ./lib/DugumAgac.o
	g++ -c -I "./include" ./src/DugumOrganizma.cpp -o ./lib/DugumOrganizma.o
	g++ -c -I "./include" ./src/DugumSistem.cpp -o ./lib/DugumSistem.o
	g++ -c -I "./include" ./src/DugumOrgan.cpp -o ./lib/DugumOrgan.o
	g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/Test.cpp -o ./lib/Test.o
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o	
	g++ -c -I "./include" ./src/DosyaOkuma.cpp -o ./lib/DosyaOkuma.o
bagla:
	g++ ./lib/Dugum.o ./lib/Radix.o ./lib/Queue.o ./lib/DosyaOkuma.o ./lib/Kontrol.o ./lib/main.o ./lib/Test.o ./lib/Organizma.o ./lib/Sistem.o ./lib/Organ.o ./lib/IkiliAramaAgaci.o ./lib/DugumOrgan.o ./lib/DugumSistem.o ./lib/DugumOrganizma.o ./lib/DugumAgac.o ./lib/Doku.o ./lib/Hucre.o -o ./bin/program
calistir:
	./bin/program.exe