package com.company.model.game;

import com.company.model.map.Map;
import com.company.model.map.WallPoint;
import com.company.model.math.RayCasting;

import java.io.Serializable;
import java.util.HashMap;

public class Game implements Serializable, Cloneable {
    private Map map;
    private HashMap<String, Character> entityDynamicList;
    private Character character;

    public Game(Character character){
        this.character = character;
        this.map = new Map();
        this.entityDynamicList = new HashMap<>();
        this.entityDynamicList.put(character.getName(), character);
    }

    public Game(){
        character = new Character();
        this.map = new Map();
        this.entityDynamicList = new HashMap<>();
    }

    public HashMap<String, Character> getEntityDynamicList(){
        return entityDynamicList;
    }

    public Map getMap(){return this.map;}

    public Character getCharacter() {
        return character;
    }

    public void addCharacter(Character character){
        entityDynamicList.put(character.getName(), character);
        map.addWall(character.getWallFront());
        map.addWall(character.getWallLeft());
        map.addWall(character.getWallBehind());
        map.addWall(character.getWallRight());
    }

    public void updateCharacters(HashMap<String, Character> characters){
        for(java.util.Map.Entry<String, Character> entry: characters.entrySet()){
            entityDynamicList.get(entry.getKey()).updateFrom(entry.getValue());
        }
    }

    public void updateCharacter(Character character){
        entityDynamicList.get(character.getName()).updateFrom(character);
    }

    public void updateFrom(Game game){
        HashMap<String, Character> temp = (HashMap<String, Character>)entityDynamicList.clone();
        temp.remove(character.getName());
        for(java.util.Map.Entry<String, Character> entry: game.entityDynamicList.entrySet()){
            if(!entityDynamicList.containsKey(entry.getValue().getName())){
                addCharacter(entry.getValue());
            }
            else entityDynamicList.get(entry.getKey()).updateFrom(entry.getValue());
            temp.remove(entry.getKey());
        }
        for(java.util.Map.Entry<String, Character> entry: temp.entrySet()){
            map.getWalls().remove(entityDynamicList.get(entry.getKey()).getWallFront());
            map.getWalls().remove(entityDynamicList.get(entry.getKey()).getWallLeft());
            map.getWalls().remove(entityDynamicList.get(entry.getKey()).getWallRight());
            map.getWalls().remove(entityDynamicList.get(entry.getKey()).getWallBehind());
            entityDynamicList.remove(entry.getKey());
        }
    }

    public Game copy(){
        Game temp = new Game();
        temp.map = map.copy();
        for(java.util.Map.Entry<String, Character> entry: entityDynamicList.entrySet()){
            temp.entityDynamicList.put(entry.getKey(), entry.getValue().copy());
        }
        return temp;
    }

    public Character shotProcessing(Shot shot){
        WallPoint point = RayCasting.rayCasting(shot.getSection(), map.getWalls());
        Character character = null;
        if(point.getClass() == WallPointCharacter.class)
        {
            character = ((WallPointCharacter) point).getCharacter();
            character.setHealth(character.getHealth() - Math.exp((-(point.getDistance())-13)/3) - 10);
            if(character.getHealth() <= 0){
                character.setHealth(100);
                int rnd = (int) (Math.random() * 6);
                switch (rnd){
                    case 0:
                        character.setX(6);
                        character.setY(2);
                        break;
                    case 1:
                        character.setX(-20);
                        character.setY(-2);
                        break;
                    case 2:
                        character.setX(-20);
                        character.setY(12);
                        break;
                    case 3:
                        character.setX(4);
                        character.setY(15);
                        break;
                    case 4:
                        character.setX(-11);
                        character.setY(4);
                        break;
                    case 5:
                        character.setX(7);
                        character.setY(10);
                        break;
                }
            }
        }
        else{

        }
        return character;
    }

    @Override
    public Object clone() throws CloneNotSupportedException{
        return super.clone();
    }
}
