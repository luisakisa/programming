package com.projectF.geometry2d;

import com.projectF.Exceptions.Exc;

public class Square extends Rectangle {
    public double Area() {
        return a * a;
    }

    public Square() throws Exc {
        super();
        name = "Square";
    }
}
