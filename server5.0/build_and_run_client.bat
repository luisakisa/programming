g++ -c ./source/server/Variables.cpp        -o ./build/Variables.o

g++ -c ./source/client/ClientWrapper.cpp    -o ./build/ClientWrapper.o
g++ -c ./source/client/Client.cpp           -o ./build/Client.o
g++ build/ClientWrapper.o build/Client.o ./build/Variables.o -o client.exe -lole32 -loleaut32 -luser32

.\client.exe