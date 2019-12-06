final: cheaters.o chunker.o files.o hashTable.o numArray.o
	g++ -otest cheaters.o chunker.o files.o hashTable.o numArray.o
cheaters: cheaters.cpp chunker.h files.h hashTable.h
	g++ -std=c++11 cheaters.cpp
chunker: chunker.cpp chunker.h
	g++ -std=c++11 chunker.cpp
files: files.cpp files.h
	g++ -std=c++11 files.cpp
hashTable: hashTable.cpp hashTable.h numArray.h
	g++ -std=c++11 hashTable.cpp
numArray: numArray.cpp numArray.h
	g++ -std=c++11 numArray.cpp