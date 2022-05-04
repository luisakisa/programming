@REM pause
@REM exit

g++ -c ./source/client/ClientWrapper.cpp -o ./build/ClientWrapper.o
g++ -c ./source/server/Functions.cpp -o ./build/Functions.o
g++ -c ./source/server/Server.cpp -o ./build/Server.o
g++ -c ./source/server/Server2.cpp -o ./build/Server2.o
g++ -c ./source/client/Client.cpp -o ./build/ClientWrapper.o
g++ -c ./source/manager/Manager.cpp -o ./build/Manager.o


g++ -shared ./build/ClientWrapper.o ./build/Functions.o ./build/Server.o ./build/Server2.o ./build/Client.o -o ./Server.dll -Wl,--kill-at
g++ -shared ./build/dll/Manager.o -o ./build/dll/Manager.dll -Wl,--kill-at


@REM pause
@REM exit
