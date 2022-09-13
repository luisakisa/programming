package com.company.model.math;

import java.io.Serializable;

public class Point implements Serializable {
    private double x;
    private double y;

    public Point(){
        x = 0;
        y = 0;
    }

    public Point(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double distance(Point b){
        return Math.sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public double getX() {
        return x;
    }
}
