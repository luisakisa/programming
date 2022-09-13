package com.example.calcnet;

public class Calculator{

    public static float plus(int a, int b, Net net){
        try
        {
            int A = a;
            int B = b;
            int sign =1;
            net.getOut().write(sign);
            net.getOut().write(A);
            net.getOut().write(B);
            net.getOut().flush();

            int n = net.getIn().read();

            return n;


        }
        catch (Exception e)
        {
            System.out.println("Error: " + e);
            return 0;
        }

    }
    public static float minus(int a, int b, Net net){
        try
        {
            int A = a;
            int B = b;
            int sign =2;
            net.getOut().write(sign);
            net.getOut().write(A);
            net.getOut().write(B);
            net.getOut().flush();
            int n = net.getIn().read();

            return n;
        }
        catch (Exception e)
        {
            System.out.println("Error: " + e);
            return 0;
        }
    }
    public static float mult(int a,int b, Net net){
        try
        {
            int A = a;
            int B = b;
            int sign =3;
            net.getOut().write(sign);
            net.getOut().write(A);
            net.getOut().write(B);
            net.getOut().flush();
            int n = net.getIn().read();

            return n;
        }
        catch (Exception e)
        {
            System.out.println("Error: " + e);
            return 0;
        }
    }
    public static float div(int a, int b, Net net){
        try
        {
            int A = a;
            int B = b;
            int sign = 4;
            net.getOut().write(sign);
            net.getOut().write(A);
            net.getOut().write(B);
            net.getOut().flush();
            int n = net.getIn().read();

            return n;
        }
        catch (Exception e)
        {
            System.out.println("Error: " + e);
            return 0;
        }
    }
    public static float pow(int a, int b, Net net){
        try
        {
            int A = a;
            int B = b;
            int sign = 5;
            net.getOut().write(sign);
            net.getOut().write(A);
            net.getOut().write(B);
            net.getOut().flush();
            int n = net.getIn().read();

            return n;
        }
        catch (Exception e)
        {
            System.out.println("Error: " + e);
            return 0;
        }
    }
}