all: derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/DosyaOkuma.cpp -o ./lib/DosyaOkuma.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/YDugum.cpp -o ./lib/YDugum.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
bagla:
	g++ ./lib/main.o ./lib/DosyaOkuma.o ./lib/Dugum.o ./lib/YDugum.o ./lib/SatirListesi.o ./lib/YoneticiListesi.o -o ./bin/program
calistir:
	./bin/program