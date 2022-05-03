@REM pause
@REM exit

g++ -c ./source/client/ClientWrapper.cpp -o ./build/ClientWrapper.o
g++ -c ./source/server/Functions.cpp -o ./build/Functions.o
g++ -c ./source/server/Server.cpp -o ./build/Server.o
g++ -c ./source/client/Client.cpp -o ./build/ClientWrapper.o
g++ -c ./source/manager/Manager.cpp -o ./build/Manager.o


g++ -shared ./build/Server.o -o ./build/Server.dll
g++ -shared ./build/Manager.o -o ./build/Manager.dll
regsvr32 ./build/Server.dll


@REM pause
@REM exit
