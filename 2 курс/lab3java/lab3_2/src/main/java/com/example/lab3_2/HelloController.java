package com.example.lab3_2;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.application.Platform;

public class HelloController {
    @FXML
    private Label welcomeText;

    @FXML
    protected void onHelloButtonClick() {
//        Thread thread = new MyThread1("Мой поток", welcomeText); через Thread
//        thread.start();
        new MyThread("МойПоток",welcomeText );

    }
}


class MyThread1 extends Thread {
    Label l;
    MyThread1(String name, Label welcomeText){
        super(name);
        this.l= welcomeText;

    }
    public void run() {
        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                l.setText("Welcome to JavaFX Application!");
            }
        });
        while(true){
            System.out.println(MyThread1.this.getName());
            try {MyThread1.this.sleep(1000);} catch (Exception e) {}
        }
    }
}
class MyThread implements Runnable {
    Label l;

    MyThread(String name, Label welcomeText) {
        this.l = welcomeText;
        Thread t = new Thread(this, name);
        t.start();
    }

    public void run() {
        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                l.setText("Welcome to JavaFX Application!");
            }
        });
        while (true) {
            System.out.println(Thread.currentThread().getName());
            try {
                Thread.currentThread().sleep(1000);
            } catch (Exception e) {
            }
        }
    }
}
