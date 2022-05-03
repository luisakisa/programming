g++ -c ./source/dll/main.cpp -o ./build/dll/main.o
g++ -shared ./build/dll/main.o -o ./build/dll/main.dll -Wl,--kill-at

@REM pause
@REM exit

g++ -c ./source/client/ClientWrapper.cpp -o ./build/ClientWrapper.o
g++ -c ./source/server/Functions.cpp -o ./build/Functions.o
g++ -c ./source/server/Server.cpp -o ./build/Server.o
g++ -c ./source/server/Server2.cpp -o ./build/Server2.o
g++ -c ./source/client/Client.cpp -o ./build/ClientWrapper.o


g++ ./build/ClientWrapper.o ./build/Functions.o ./build/Server.o ./build/Server2.o ./build/Client.o -o ./build/test.exe

"build/test.exe"

pause
exit