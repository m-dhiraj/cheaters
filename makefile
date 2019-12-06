final: cheaters.o chunker.o files.o hashTable.o
	g++ -otest cheaters.o chunker.o files.o hashTable.o
cheaters: cheaters.cpp chunker.h files.h hashTable.h
	g++ -std=c++11 cheaters.cpp
chunker: chunker.cpp chunker.h
	g++ -std=c++11 chunker.cpp
files: files.cpp files.h
	g++ -std=c++11 files.cpp
hashTable: hashTable.cpp hashTable.h
	g++ -std=c++11 hashTable.cpp