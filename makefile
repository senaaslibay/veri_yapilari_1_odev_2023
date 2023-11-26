Tum: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/Basamak.o -c ./src/Basamak.cpp
	g++ -I ./include/ -o ./bin/Program .lib/Basamak.o .src/Program.cpp


calistirma:
	cls
	./bin/Program