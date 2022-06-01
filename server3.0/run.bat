rmdir /S /Q .\build\
mkdir build

g++ -c ./source/client/ClientWrapper.cpp    -o ./build/ClientWrapper.o
g++ -c ./source/client/Client.cpp           -o ./build/Client.o

g++ -c ./source/server/Functions.cpp        -o ./build/Functions.o
g++ -c ./source/server/Server.cpp           -o ./build/Server.o
g++ -c ./source/server/Server2.cpp          -o ./build/Server2.o
g++ -c ./source/server/IClassFactory.cpp    -o ./build/IClassFactory.o

g++ -c ./source/manager/Manager.cpp         -o ./build/Manager.o




g++ -shared ./build/Server.o ./build/Server2.o ./build/Functions.o ./build/IClassFactory.o -o ./build/Server.dll
g++ -shared ./build/Manager.o -o ./build/Manager.dll

regsvr32 ./build/Server.dll
