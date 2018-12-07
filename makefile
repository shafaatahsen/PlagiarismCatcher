final: main.o plagiarismCatcher.o hashMap.o
	g++ -o plagiarismCatcher main.o plagiarismCatcher.o hashMap.o
main.o: main.cpp hashMap.h plagiarismCatcher.h
	g++ -c main.cpp
plagiarismCatcher.o: plagiarismCatcher.cpp plagiarismCatcher.h
	g++ -c plagiarismCatcher.cpp
hashMap.o: hashMap.cpp hashMap.h
	g++ -c hashMap.cpp