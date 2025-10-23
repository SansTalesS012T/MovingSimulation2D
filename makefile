all: complie run clean

complie:
	g++ move.cpp -o move.exe

run:
	./move.exe

runWithMemory:
	valgrind --leak-check=full ./move.exe 

clean:
	rm move.exe

debugMem: complie runWithMemory clean