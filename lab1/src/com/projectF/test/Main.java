package com.projectF.test;
import com.projectF.geometry3d.Cylinder;
import com.projectF.geometry2d.*;
import com.projectF.Exceptions.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) throws Exc {
        double h = 1;
        try {
            Rectangle rectangle = new Rectangle();
            Triangle triangle = new Triangle();
        Square square = new Square();
        Oval oval = new Oval();
        Circle circle = new Circle();
        Figure[] figures = {rectangle, triangle, square, oval, circle};

        for (int i = 0; i < 5; i++) {
            System.out.println(figures[i].Show() + "\n" + figures[i].Area() + "\n");
        }
        System.out.println("Введите высоту: ");
        try {
            Scanner s = new Scanner(System.in);
            h = s.nextDouble();
        } catch (Exception except) {
            System.out.println("Неправильное значение высоты");
            return;
        }
        try {
            for (int i = 0; i < 5; i++) {
                Cylinder cylinder = new Cylinder(figures[i], h);
                System.out.println(figures[i].Show() + "\n" + cylinder.volume() + "\n");
            }
        } catch (ExcNegative except) {
            System.out.println(except.getMessage());
        }
        } catch (Exc except) {
            System.out.println(except.getMessage());
        }
    }
}