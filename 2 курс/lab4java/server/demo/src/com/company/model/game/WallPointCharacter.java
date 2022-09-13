package com.company.model.game;

import com.company.model.game.Character;
import com.company.model.map.WallPoint;

public class WallPointCharacter extends WallPoint {
    private Character character;

    public WallPointCharacter(){
        this.distance = 0;
        this.textureID = 0;
        this.textureK = 0;
    }

    public WallPointCharacter(double distance, int textureID, double textureK, Character character){
        this.distance = distance;
        this.textureID = textureID;
        this.textureK = textureK;
        this.character = character;
    }

    public void setTextureID(int textureID) {
        this.textureID = textureID;
    }

    public int getTextureID() {
        return textureID;
    }

    public double getTextureK() {
        return textureK;
    }

    public void setTextureK(double textureK) {
        this.textureK = textureK;
    }

    public double getDistance() {
        return distance;
    }

    public void setDistance(double distance) {
        this.distance = distance;
    }

    public Character getCharacter() { return character; }
}
