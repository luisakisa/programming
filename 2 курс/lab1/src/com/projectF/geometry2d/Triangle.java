package com.projectF.geometry2d;

import com.projectF.Exceptions.Exc;

public class Triangle extends Rectangle {
    public double Area() {
        return 0.5 * a * b;
    }

    public Triangle() throws Exc {
        super();
        name = "Triangle";
    }
}
