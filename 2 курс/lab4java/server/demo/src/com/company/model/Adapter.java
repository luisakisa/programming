package com.company.model;

import com.company.model.client.Client;
import com.company.model.client.Movement;
import com.company.model.rendering.Screen;
import javafx.application.Platform;
import javafx.scene.robot.Robot;

public class Adapter {

    private Client client;

    public Adapter(){
        client = new Client();
    }

    public Adapter(String name, String ip, int serverPort, int clientPort){
        client = new Client(name, ip, serverPort, clientPort);
    }

    public void startClient(){
        client.start();
    }

    public boolean isStart(){
        return client.isStart();
    }

    public void stop(){
        client.stop();
    }

    public void pause(boolean pause){
        client.pause(pause);
    }

    public Screen getScreen(){
        return client.getRendering().getScreen();
    }

    public double getHealth(){
        return  client.getCharacter().getHealth();
    }

    public void pressW(){
        client.getMovement().setForth(true);
        client.getMovement().setBackForthEvent(true);
    }

    public void pressWReleased(){
        client.getMovement().setForth(false);
        //client.getMovement().setBackForthEvent(false);
    }

    public void pressS(){
        client.getMovement().setBack(true);
        client.getMovement().setBackForthEvent(true);
    }

    public void pressSReleased(){
        client.getMovement().setBack(false);
        //client.getMovement().setBackForthEvent(false);
    }

    public void pressD(){
        client.getMovement().setRight(true);
        client.getMovement().setRightLeftEvent(true);
    }

    public void pressDReleased() {
        client.getMovement().setRight(false);
        //client.getMovement().setRightLeftEvent(false);
    }

    public void pressA(){
        client.getMovement().setLeft(true);
        client.getMovement().setRightLeftEvent(true);
    }

    public void pressAReleased() {
        client.getMovement().setLeft(false);
        //client.getMovement().setRightLeftEvent(false);
    }

    public void pressRight(){
        client.getMovement().setTurnRight(true);
        client.getMovement().setTurnRightLeftEvent(true);
    }

    public void pressRightReleased(){
        client.getMovement().setTurnRight(false);
        //client.getMovement().setTurnRightLeftEvent(false);
    }

    public void mouseMoving(double deltaX) {
        Movement mov = client.getMovement();
        mov.setMouseMovement(true);
        mov.setMouseMovementEvent(true, deltaX);

        new Thread(() -> {
            try {
                Thread.sleep(1);

            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            Platform.runLater(() -> {

                mov.setMouseMovement(false);
            });
        }).start();
    }


   // public void mouseMovingStop(){
    //    client.getMovement().setMouseMovement(false);
    //}

    public void pressLeft(){
        client.getMovement().setTurnLeft(true);
        client.getMovement().setTurnRightLeftEvent(true);
    }

    public void pressLeftReleased(){
        client.getMovement().setTurnLeft(false);
        //client.getMovement().setTurnRightLeftEvent(false);
    }

    public void pressShot(){
        client.getMovement().setShotEvent(true);
        client.getMovement().setShot(true);
    }

    public void pressShotReleased(){
        client.getMovement().setShot(false);
        client.getMovement().setShotEvent(false);
    }

    public void pressShift(){
        client.getMovement().setShiftEvent(true);
        client.getMovement().setShift(true);
    }

    public void pressShiftReleased(){
        client.getMovement().setShiftEvent(false);
        client.getMovement().setShift(false);
    }

    public void setName(String name){
        System.out.println("com.company.model.Adapter.setName()");
    }

    public void setMode(boolean mode){
        System.out.println("com.company.model.Adapter.setMode()");
    }
}
