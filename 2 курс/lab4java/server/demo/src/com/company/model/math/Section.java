package com.company.model.math;

import java.io.Serializable;

public class Section implements Serializable {
    private Point a, b;

    public Section(){
        a = new Point();
        b = new Point();
    }

    public Section(double aX, double aY, double bX, double bY){
        a = new Point(aX, aY);
        b = new Point(bX, bY);
    }

    public Section(Point a, Point b){
        this.a = a;
        this.b = b;
    }

    public double length(){
        return a.distance(b);
    }

    public double crossProduct(Section section){
        return (b.getX() - a.getX()) * (section.b.getY() - section.a.getY()) - (section.b.getX() - section.a.getX()) * (b.getY() - a.getY());
    }

    public Section getNormal(){
        return new Section(0, 0, (-b.getY() + a.getY()) / length(), (b.getX() - a.getX()) / length());
    }

    public Section sum(Section section){
        return new Section(a.getX() + section.a.getX(), a.getY() + section.a.getY(), b.getX() + section.b.getX(), b.getY() + section.b.getY());
    }

    public Point getA() {
        return a;
    }

    public Point getB() {
        return b;
    }

    public void setA(Point a) {
        this.a = a;
    }

    public void setB(Point b) {
        this.b = b;
    }
}
