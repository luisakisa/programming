package com.projectF.Figures;


public class Rectangle implements Figure {
    String name;
    double a, b;

    public double Area() {
        return a * b;
    }

    int[] coords = {1, 2, 4, 2, 1, 6, 4, 6};

    public String toString() {
        String a;
        a = "Name: " + name + "; ";
        for (int i = 0; i < 8; i += 2) {
            a += "Coords: x = " + coords[i] + ", y = " + coords[i + 1] + "; ";
        }
        return a;
    }

    public double volume() {
        return 0;
    }

    public Rectangle() {
        a = coords[2] - coords[0];
        b = coords[5] - coords[1];
        name = "Rectangle";
    }

}
