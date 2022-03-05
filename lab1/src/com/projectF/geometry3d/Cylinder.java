package com.projectF.geometry3d;
import com.projectF.Exceptions.*;
import com.projectF.geometry2d.Figure;

public class Cylinder implements Figure {
    Figure f;
    double v;
    double h;

    public Cylinder(Figure f, double c) throws ExcNegative {
        h = c;
        if (h <= 0) throw new ExcNegative("Значение высоты должно быть больше 0");
    }

    public double Area() {
        return 0;
    }

    public String Show() {
        return null;
    }

    public double volume() {
        v = f.Area() * h;
        return v;
    }
}
