package com.projectF.Cylinder;

import com.projectF.Figures.Figure;

public class Cylinder implements Figure {
    double v;
    double a;
    double h;

    public Cylinder(double b, double c) throws Exception {
        h = c;
        if (h <= 0) throw new Exception();
        a = b;

    }

    public double Area() {
        return 0;
    }

    public double volume() {
        v = a * h;
        return v;
    }
}
