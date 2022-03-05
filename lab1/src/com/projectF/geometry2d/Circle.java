package com.projectF.geometry2d;

import com.projectF.Exceptions.Exc;

public class Circle extends Oval {

    public Circle() throws Exc {
        super();
        name = "Circle";
    }

    public double Area() {

        return (3.14) * a * a;
    }
}
