package com.company.model.map;

import com.company.model.math.Point;
import com.company.model.math.Section;

import java.io.Serializable;

public class Wall implements Serializable {
    protected Section section;
    private int textureID;
    private double textureWidth;

    public Wall(){
        section = new Section(0, 0, 0, 0);
        textureID = 0;
        textureWidth = 0;
    }

    public Wall(Section section, int color, int textureID, double textureWidth){
        this.section = section;
        this.textureID = textureID;
        this.textureWidth = textureWidth;
    }

    public Wall(double aX, double aY, double bX, double bY, int color, int textureID, double textureWidth){
        section = new Section(aX, aY, bX, bY);
        this.textureID = textureID;
        this.textureWidth = textureWidth;
    }

    public double getTextureWidth() {
        return textureWidth;
    }

    public int getTextureID() {
        return textureID;
    }

    public void setTextureID(int textureID) {
        this.textureID = textureID;
    }

    public void setTextureWidth(double textureWidth) {
        this.textureWidth = textureWidth;
    }

    public void setB(Point b){this.section.setB(b);}

    public Section getSection() {
        return section;
    }

    public void setSection(Section section) {
        this.section = section;
    }
}
