package com.company.model.map;

public class WallPoint {
    protected double distance;
    protected int textureID;
    protected double textureK;

    public WallPoint(){
        distance = 0;
        textureID = 0;
        textureK = 0;
    }

    public WallPoint(double distance, int textureID, double textureK){
        this.distance = distance;
        this.textureID = textureID;
        this.textureK = textureK;
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
}
