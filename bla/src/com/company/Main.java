package com.company;
import java.util.Scanner;
interface Figure {
    double Area();
    String toString();
    double volume();
}
class Rectangle implements Figure
{
    String name;
    double a, b;
    public double Area() {
        return a * b;
    }
    int[] coords={1,2,4,2,1,6,4,6};
    public String toString(){
        String a;
        a = "Name: " + name + "; ";
        for (int i = 0; i < 8; i+=2) {
            a += "Coords: x = " + coords[i] + ", y = " + coords[i+1] + "; ";
        }
        return a;
    }

    public double volume() {
        return 0;
    }

    Rectangle() {
        a = coords[2] - coords[0];
        b = coords[5] - coords[1];
        name = "Rectangle";
    }

};
class Square extends Rectangle
{
    public double Area() {
        return a * a;
    }
    Square() {
        name = "Square";
    }
};
class Oval extends Rectangle {

    public double Area(){

        return  (3.14) * a*b;
    }
    Oval() {
        name = "Oval";
    }

};
class Circle extends Oval {

    Circle() {
        name = "Circle";
    }
    public double Area() {

        return  (3.14)* a*a;
    }
};

class Triangle extends Rectangle
{

    public double Area() {
        return 0.5 * a*b;
    }
    Triangle() {
        name = "Triangle";
    }
};class Cylinder implements Figure{
    double v;
    double a;double h;
    Cylinder(double b, double c) throws Exception {
        h = c;
        if (h<=0) throw new Exception();
        a = b;

    }
    public double Area() {
        return 0;
    }

    public double volume(){
        v= a*h;
        return v;
    }
}
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
            System.out.println(figures[i].toString()+"\n"+figures[i].Area() +"\n");
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
                System.out.println(figures[i].toString() + "\n" + figures[i].Area() + "\n");
            }
        }
        catch(Exception except)
        {
            System.out.println("Значение высоты должно быть больше 0");
        }
    }
}