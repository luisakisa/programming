package com.example.lab3_3;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ProgressBar;

public class HelloController{
    public static boolean isSuspend = false;
    @FXML
    Button start, pause, stop;
    @FXML
    ProgressBar progress;

    @FXML
    private void startProgress(ActionEvent event){
        if (!isSuspend){
            new NewThread( progress, start, stop);
        }
    }

    @FXML
    private void pauseProgress(ActionEvent event){
        if (!isSuspend){
            pause.setText("Продолжить");
        }
        else{
            pause.setText("Пауза");
        }
        isSuspend = !isSuspend;
    }


}

class NewThread implements Runnable{
    ProgressBar progress;
    Button start, stop;

    NewThread( ProgressBar progress, Button start, Button stop){
        this.start = start;
        this.stop = stop;
        this.progress = progress;
        Thread t = new Thread(this);
        t.start();
    }

    public void run(){
        Thread t =  Thread.currentThread();

        for(int i = 1; i<=1000; i++){

            if (start.isPressed() || stop.isPressed()){
                progress.setProgress(0);
                t.interrupt();
                break;
            }

            while(HelloController.isSuspend){
                try {
                    wait(0);
                } catch (Exception e) {}
            }

            final double j = i;
            Platform.runLater(new Runnable() {
                @Override
                public void run() {
                    progress.setProgress(j/1000);
                }
            });
            try {t.sleep(20);} catch (Exception e) {}
        }

        t.interrupt();
    }
}