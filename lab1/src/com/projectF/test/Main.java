package com.projectF.test;
import com.projectF.geometry3d.Cylinder;
import com.projectF.geometry2d.*;

import java.util.Scanner;

class Main {
    public static void main(String[] args)  {
        double h=1;
        Rectangle rectangle = new Rectangle();
        Triangle triangle = new Triangle();
        Square square = new Square();
        Oval oval = new Oval();
        Circle circle = new Circle();
        Figure figures[] = { rectangle, triangle, square, oval, circle };

        for ( int i = 0; i < 5; i++) {
            System.out.println(figures[i].Show()+"\n"+figures[i].Area() +"\n");
        }
        System.out.println("Введите высоту: ");
        try{
            Scanner s = new Scanner(System.in);
            h = s.nextDouble();
        }
        catch(Exception except)
        {
            System.out.println("Неправильное значение высоты");
            return;
        }
        try {
            for (int i = 0; i < 5; i++) {
                Figure cylinder = new Cylinder(figures[i].Area(), h);
                System.out.println(figures[i].Show() + "\n" + figures[i].Area() + "\n");
            }
        }
        catch(Exception except)
        {
            System.out.println("Значение высоты должно быть больше 0");
        }
    }
}