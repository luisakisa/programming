package com.projectF.geometry2d;

import com.projectF.Exceptions.Exc;

public class Oval extends Rectangle {

    public double Area() {

        return (3.14) * a * b;
    }

    public Oval() throws Exc {
        super();
        name = "Oval";
    }

}
