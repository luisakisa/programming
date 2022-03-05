package com.projectF.geometry2d;
import com.projectF.Exceptions.Exc;


public class Rectangle implements Figure {
    String name;
    double a, b;

    public double Area() {
        return a * b;
    }

    int[] coords = {1, 2, 4, 2, 1, 6, 4, 6};

    public String Show() {
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

    public Rectangle() throws Exc {
        a = coords[2] - coords[0];
        b = coords[5] - coords[1];
        name = "Rectangle";
        if (a <= 0 || b<= 0) throw new Exc("Сторона отрицательна или равна 0");
    }

}
