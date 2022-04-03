package com.company;

class NewThread extends Thread {

    // общий для двух потоков lock
    private Object lock;
    private String name;
    public NewThread(Object object, String n) {
        this.lock = object;
        this.name = n;
    }

    @Override
    public void run() {
        while (true) {
            synchronized (lock) {
                try {
                    System.out.println(name);
                    lock.notify();
                    lock.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

public class Main {
    public static void main(String[] strings) {
        Object lock = new Object();
        new NewThread(lock,"Поток 1").start();
        new NewThread(lock,"Поток 2").start();
    }
}
