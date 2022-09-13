package com.company.model.client.net;

import com.company.model.client.Client;
import com.company.model.game.Character;
import com.company.model.game.Game;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.Iterator;

public class UDPClientRead extends Thread{
    private DatagramSocket socket;
    private int clientPort;
    private Game game;
    private boolean launched;

    public UDPClientRead(Game game, int clientPort) throws Exception{
        this.clientPort = clientPort;
        socket = new DatagramSocket(clientPort);
        this.game = game;
        launched = false;
    }

    @Override
    public void run(){
        launched = true;
        try {
            while (launched){

                Client.timeOut.timeout = 0;
                byte[] buffer = new byte[1000 * 32];
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                socket.receive(packet);
                String msg = new String(packet.getData(), 0, packet.getLength());
                JSONObject json = (JSONObject) JSONValue.parse(msg);

                if(json.get("type").equals("charactersInfo")){
                    Game game = getGame(json);
                    game.getEntityDynamicList().remove(this.game.getCharacter().getName());
                    this.game.updateFrom(game);
                }
                if(json.get("type").equals("changeXY")){
                    JSONObject args = (JSONObject) json.get("args");
                    game.getCharacter().setX((Double) args.get("x"));
                    game.getCharacter().setY((Double) args.get("y"));
                }
                if(json.get("type").equals("changeHP")){
                    JSONObject args = (JSONObject) json.get("args");
                    game.getCharacter().setHealth((Double) args.get("hp"));
                }
                if(json.get("type").equals("kill")){
                    JSONObject args = (JSONObject) json.get("args");
                    game.getCharacter().setHealth((Double) args.get("hp"));
                    game.getCharacter().setX((Double) args.get("x"));
                    game.getCharacter().setY((Double) args.get("y"));
                }
            }
        }
        catch (Exception e){
            System.out.println("Ошибка: " + e.getMessage());
        }
        finally {
            socket.close();
        }
    }

    public boolean isLaunched() {
        return launched;
    }

    public void closeSocket(){
        socket.close();
    }

    public void setLaunched(boolean launched) {
        this.launched = launched;
    }

    private Game getGame(JSONObject json){
        Game game = new Game();
        JSONObject g = (JSONObject)json.get("game");
        JSONObject characters = (JSONObject)g.get("characters");

        for(Iterator i = characters.keySet().iterator(); i.hasNext();){
            String key = (String) i.next();
            JSONObject j = (JSONObject) characters.get(key);
            Character character = new Character(
                    key,
                    (Double)j.get("x"),
                    (Double)j.get("y"),
                    (Double)j.get("angle"),
                    (Double)j.get("hp"));
            game.addCharacter(character);
        }
        return game;
    }
}
