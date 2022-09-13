package com.company;

import java.io.*;
import java.net.Socket;

public class ServerSomthing extends Thread {

    public Socket socket; // сокет, через который сервер общается с клиентом,
    // кроме него - клиент и сервер никак не связаны
    public BufferedReader in; // поток чтения из сокета
    public BufferedWriter out; // поток записи в сокет

    public ServerSomthing(Socket socket) throws IOException {
        this.socket = socket;
        // если потоку ввода/вывода приведут к генерированию исключения, оно проброситься дальше
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        start(); // вызываем run()
    }
    @Override
    public void run() {
        int match, m;
        try {

            while (true) {
                match = in.read();
                m = in.read();
                for (ServerSomthing vr : Net.serverList) {
                    vr.send(match-m); // отослать принятое сообщение с
                    // привязанного клиента всем остальным включая его
                }
            }

        } catch (IOException e) {
        }
    }

    private void send(int match) {
        try {
            out.write(match);
            out.flush();
        } catch (IOException ignored) {}
    }

}
