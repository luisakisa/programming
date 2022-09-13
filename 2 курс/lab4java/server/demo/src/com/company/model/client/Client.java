package com.company.model.client;

import com.company.model.client.net.TimeOut;
import com.company.model.client.net.UDPClientRead;
import com.company.model.client.net.UDPClientWrite;
import com.company.model.listeners.Realize;
import com.company.model.rendering.Rendering;
import com.company.model.game.Character;
import com.company.model.game.Game;

public class Client {
    private Game game;
    private Character character;
    private Movement movement;
    private Rendering rendering;
    private boolean isConnection;
    private boolean isStart;
    public static UDPClientWrite udpClientWrite;
    public static UDPClientRead udpClientRead;
    public static TimeOut timeOut;

    public Client(){
        isStart = true;
        isConnection = false;
        character = new Character("player");
        game = new Game(character);
        rendering = new Rendering(character, game);
        movement = new Movement(character, game);
        timeOut = null;
        udpClientRead = null;
        udpClientWrite = null;
    }

    public Client(String name, String serverIP, int serverPort, int clientPort){
        isStart = true;
        isConnection = true;
        character = new Character(name);
        game = new Game(character);
        rendering = new Rendering(character, game);
        try {
            udpClientWrite = new UDPClientWrite(game, serverIP, serverPort);
            udpClientRead = new UDPClientRead(game, clientPort);
        }
        catch (Exception e){
            System.out.println("Ошибка: " + e.getMessage());
        }
        movement = new Movement(character, game);
        timeOut = new TimeOut(new Realize() {
            @Override
            public void make() {
                isStart = false;
            }
        });
    }

    public Game getGame() {
        return game;
    }

    public void setGame(Game game) {
        this.game = game;
    }

    public Character getCharacter() {
        return character;
    }

    public void setCharacter(Character character) {
        this.character = character;
    }

    public Movement getMovement(){
        return movement;
    }

    public Rendering getRendering(){
        return rendering;
    }

    public boolean isStart() {
        return isStart;
    }

    public void start(){
        movement.start();
        rendering.start();
        if(isConnection){
            udpClientWrite.start();
            udpClientRead.start();
            timeOut.start();
        }
    }

    public void pause(boolean pause){
        movement.setPause(pause);
        rendering.setRenderingOnPause(pause);
    }

    public void stop(){
        isStart = false;
        movement.stop();
        rendering.setLaunched(false);
        if(isConnection){
            timeOut.setLaunched(false);
            udpClientWrite.setLaunched(false);
            udpClientRead.setLaunched(false);
            udpClientRead.closeSocket();
        }
    }
}
