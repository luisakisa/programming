package com.company.model.client;

import com.company.model.listeners.Event;
import com.company.model.listeners.Listener;
import com.company.model.listeners.MouseEvent;
import com.company.model.listeners.Realize;
import com.company.model.map.*;
import com.company.model.math.Angles;
import com.company.model.game.Character;
import com.company.model.game.Game;
import org.json.simple.JSONObject;

public class Movement {
    private Character character;
    private Map map;
    private Game game;

    private Listener backForthListener;
    private Listener rightLeftListiner;
    private Listener turnRightLeftListiner;
    private Listener shotListener;
    private Listener mouseMovementListener;
    private Listener shiftListener;

    private Event backForthEvent;
    private Event rightLeftEvent;
    private Event turnRightLeftEvent;
    private Event shotEvent;
    private Event mouseMovementEvent;
    private Event shiftEvent;

    private boolean launched;
    private boolean pause;

    private boolean back;
    private boolean forth;
    private boolean right;
    private boolean left;
    private boolean turnRight;
    private boolean turnLeft;
    private boolean mouseMovement;
    private boolean shift;
    private boolean shot;

    public Movement(Character character, Game game){
        back = false;
        forth = false;
        right = false;
        left = false;
        turnLeft = false;
        turnRight = false;
        mouseMovement = false;
        shift = false;
        shot = false;

        this.character = character;
        this.map = game.getMap();
        this.game = game;

        backForthEvent = new Event();
        rightLeftEvent = new Event();
        turnRightLeftEvent = new Event();
        mouseMovementEvent = new MouseEvent();
        shiftEvent = new Event();
        shotEvent = new Event();

        launched = false;
        pause = false;

        this.backForthListener = new Listener(backForthEvent, new Realize() {
            @Override
            public void make() {
                backForth();
            }
        });

        this.shiftListener = new Listener(shiftEvent, new Realize() {
            @Override
            public void make() {
                backForth();
            }
        });

        this.rightLeftListiner = new Listener(rightLeftEvent, new Realize() {
            @Override
            public void make() {
                rightLeft();
            }
        });

        this.turnRightLeftListiner = new Listener(turnRightLeftEvent, new Realize() {
            @Override
            public void make() {
                turnRightLeft();
            }
        });

        this.mouseMovementListener = new Listener(mouseMovementEvent, new Realize() {
            @Override
            public void make() { turnWithMouse(); }
        });

        this.shotListener = new Listener(shotEvent, new Realize() {
            @Override
            public void make() {
                shot();
            }
        });
    }

    public void backForth(){

        if(forth && (left || right)){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() + Math.cos(Angles.convert(character.getAng())) /380);
            character.setY(character.getY() + Math.sin(Angles.convert(character.getAng())) /380);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }
        else if(forth){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() + Math.cos(Angles.convert(character.getAng())) /360);
            character.setY(character.getY() + Math.sin(Angles.convert(character.getAng())) /360);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }

        if(forth && shift){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() + 3 * Math.cos(Angles.convert(character.getAng())) /360);
            character.setY(character.getY() + 3 * Math.sin(Angles.convert(character.getAng())) /360);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }

        if(back && (left || right)){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() - Math.cos(Angles.convert(character.getAng())) /380);
            character.setY(character.getY() - Math.sin(Angles.convert(character.getAng())) /380);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }
        else if(back){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() - Math.cos(Angles.convert(character.getAng())) /360);
            character.setY(character.getY() - Math.sin(Angles.convert(character.getAng())) /360);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }

    }

    public void rightLeft(){
        if(left && (back || forth)){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() - Math.cos(Angles.convert(character.getAng() - Angles.Ang90)) /380);
            character.setY(character.getY() - Math.sin(Angles.convert(character.getAng() - Angles.Ang90)) /380);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }
        else if(left){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() - Math.cos(Angles.convert(character.getAng() - Angles.Ang90)) /360);
            character.setY(character.getY() - Math.sin(Angles.convert(character.getAng() - Angles.Ang90)) /360);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }

        if(right && (back || forth)){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() + Math.cos(Angles.convert(character.getAng()  - Angles.Ang90)) /380);
            character.setY(character.getY() + Math.sin(Angles.convert(character.getAng() - Angles.Ang90)) /380);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }
        else if(right){
            double posCharacterXPrev = character.getX();
            double posCharacterYPrev = character.getY();
            character.setX(character.getX() + Math.cos(Angles.convert(character.getAng()  - Angles.Ang90)) /360);
            character.setY(character.getY() + Math.sin(Angles.convert(character.getAng() - Angles.Ang90)) /360);
            if(map.isWall(character.getX(), character.getY()) > 0){
                character.setX(posCharacterXPrev);
                character.setY(posCharacterYPrev);
            }
        }
    }

    public void turnRightLeft(){
        if(turnLeft){
            character.setAng(character.getAng() + 0.3 * (Angles.Ang6/8));
        }
        if(turnRight){
            character.setAng(character.getAng() - 0.3 * (Angles.Ang6/8));
        }
    }

    public void turnWithMouse(){
        if(mouseMovement){
           double deltaX = ((MouseEvent) mouseMovementEvent).getDeltaX();
            character.setAng(character.getAng() + deltaX * 0.4 * (Angles.Ang6/10));
        }

    }

    public void shot(){
        try {
            System.out.println("Выстрел");
            JSONObject json = Client.udpClientWrite.getInfo();
            json.put("type", "shot");
            Client.udpClientWrite.write(json.toJSONString());
        }
        catch (Exception e){
            System.out.println("Ошибка при отправке выстрела на сервер: " + e.getMessage());
        }
        finally {
            try {
                Thread.currentThread().sleep(300);
            }
            catch (Exception e){}
        }
    }

    public boolean isLaunched() {
        return launched;
    }

    public void setLaunched(boolean launched) {
        this.launched = launched;
    }

    public void stop(){
        this.launched = false;
        mouseMovementListener.setLaunched(false);
        backForthListener.setLaunched(false);
        rightLeftListiner.setLaunched(false);
        turnRightLeftListiner.setLaunched(false);
        shotListener.setLaunched(false);
    }

    public boolean isPause() {
        return pause;
    }

    public void setPause(boolean pause) {
        this.pause = pause;
        mouseMovementListener.setPause(pause);
        backForthListener.setPause(pause);
        rightLeftListiner.setPause(pause);
        turnRightLeftListiner.setPause(pause);
        shotListener.setPause(pause);
    }

    public void setBackForthEvent(boolean event){
        backForthEvent.setEvent(event);
    }

    public void setShiftEvent(boolean event){
        shiftEvent.setEvent(event);
    }

    public void setRightLeftEvent(boolean event){
        rightLeftEvent.setEvent(event);
    }

    public void setTurnRightLeftEvent(boolean event){
        turnRightLeftEvent.setEvent(event);
    }

    public void setMouseMovementEvent(boolean event, double deltaX){
        ((MouseEvent) mouseMovementEvent).setDeltaX(deltaX);
        mouseMovementEvent.setEvent(event);
    }

    public void setShotEvent(boolean event){
        shotEvent.setEvent(event);
    }

    public void setBack(boolean back) {
        this.back = back;
    }

    public void setForth(boolean forth) {
        this.forth = forth;
    }

    public void setShift(boolean shift){
        this.shift = shift;
    }

    public void setShot(boolean shot) {
        this.shot = shot;
    }

    public void setLeft(boolean left) {
        this.left = left;
    }

    public void setRight(boolean right) {
        this.right = right;
    }

    public void setTurnLeft(boolean turnLeft) {
        this.turnLeft = turnLeft;
    }

    public void setTurnRight(boolean turnRight) { this.turnRight = turnRight; }

    public void setMouseMovement(boolean mouseMovement) {this.mouseMovement = mouseMovement; }

    public void start(){
        launched = true;
        mouseMovementListener.start();
        backForthListener.start();
        rightLeftListiner.start();
        turnRightLeftListiner.start();
        shotListener.start();
    }
}
