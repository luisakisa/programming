package com.company.model.math;

public class Angles {
    public static final int Ang360 = 4800;
    public static final int Ang315 = 4200;
    public static final int Ang225 = 3000;
    public static final int Ang180 = 2400;
    public static final int Ang135 = 1800;
    public static final int Ang90 = 1200;
    public static final int Ang60 = 800;
    public static final int Ang45 = 600;
    public static final int Ang30 = 400;
    public static final int Ang6 = 80;

    public static double convert(double angle){
        return angle * (Math.PI / Ang180);
    }
}
