package com.company;

import java.net.*;
import java.io.*;
import java.util.LinkedList;

class Net
{
    public static LinkedList<ServerSomthing> serverList = new LinkedList<>(); // список всех нитей
    public static void main(String args[]) throws IOException {

        ServerSocket ss = new ServerSocket(1111);
        System.out.println("Сервер запущен!");
        try {
            while (true) {
                // Блокируется до возникновения нового соединения:
                Socket socket = ss.accept();
                try {
                    serverList.add(new ServerSomthing(socket)); // добавить новое соединенние в список
                } catch (IOException e) {
                    // Если завершится неудачей, закрывается сокет,
                    // в противном случае, нить закроет его при завершении работы:
                    socket.close();
                }
            }
        } finally {
            ss.close();
        }

    }
}