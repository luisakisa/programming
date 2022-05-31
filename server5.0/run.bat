rmdir /S /Q .\build\
mkdir build

g++ -c ./source/server/Variables.cpp        -o ./build/Variables.o

g++ -c ./source/client/ClientWrapper.cpp    -o ./build/ClientWrapper.o
g++ -c ./source/client/Client.cpp           -o ./build/Client.o
g++ build/ClientWrapper.o build/Client.o ./build/Variables.o -o client.exe -lole32 -loleaut32 -luser32


g++ -c ./source/manager/Manager.cpp         -o ./build/Manager.o
g++ -shared ./build/Manager.o -o ./build/Manager.dll


g++ -c ./source/server/Functions.cpp        -o ./build/Functions.o
g++ -c ./source/server/Server.cpp           -o ./build/Server.o
g++ -c ./source/server/Server2.cpp          -o ./build/Server2.o
g++ -c ./source/server/IClassFactory.cpp    -o ./build/IClassFactory.o
g++ -c ./source/server/main.cpp             -o ./build/mainServer.o
g++ -shared ./build/Server.o ./build/Server2.o ./build/Functions.o ./build/IClassFactory.o ./build/Variables.o ./build/mainServer.o -o ./build/Server.dll -lole32 -loleaut32 -luser32


@REM regsvr32 ./build/Server.dll
