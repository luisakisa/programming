package com.company.model.map;

import java.io.Serializable;
import java.util.ArrayList;

public class Map implements Serializable, Cloneable {
    private ArrayList<Wall> walls;

    public Map(){
        walls = new ArrayList<>();

        //при создании визуальных стен ставить координаты 0.55 больше или меньше
        walls.add(new Wall(9, -1, 9, 11.55, 0, 15, 1));// v1

        walls.add(new Wall(3.7, 3.05, 3.7, 5.3, 0, 16, 1));// v2
        walls.add(new Wall(3.7, 3.05, 3.3, 3.05, 0, 0, 0.39));// v2
        walls.add(new Wall(3.3, 3.05, 3.3, 5.725, 0, 16, 1));// v2

        walls.add(new Wall(9, -1, -15.2, -1, 0, 15, 1));// v3

        walls.add(new Wall(4.834, 5.1, 4.834, 8.4, 0, 16, 1.4));// v4
        walls.add(new Wall(4.834, 5.1, 3.7, 5.275 , 0, 16, 1.2));// v4
        walls.add(new Wall(4.834, 8.4, -1, 10.3 , 0, 16, 1.1));// v4
        walls.add(new Wall(3.3, 5.725, -1, 7.11, 0, 16, 1));// v4
        walls.add(new Wall(-1, 7.11, -1, 10.3, 0, 3, 1));// v4

        walls.add(new Wall(-5.768, 5.659, -5.768, 9.058, 0, 3, 1));// v5
        walls.add(new Wall(-5.768, 5.659, -12.494, 5.072, 0, 17, 1));// v5
        walls.add(new Wall(-5.768, 9.058, -12.494, 8.47, 0, 17, 1));// v5
        walls.add(new Wall(-12.494, 5.072, -12.494, 8.47, 0, 17, 1));// v5

        walls.add(new Wall(-8.8, 2.9, -8.8, 5.432, 0, 17, 1));// v6
        walls.add(new Wall(-8.8, 2.9, -9.2, 2.9, 0, 18, 0.45));// v6
        walls.add(new Wall(-9.2, 2.9, -9.2, 5.4, 0, 17, 1));// v6

        walls.add(new Wall(-15.2, -1, -15.2, -3.3, 0, 15, 1));// v7

        walls.add(new Wall(-15.2, -3.3, -22.05, -3.3, 0, 5, 1));// v8

        walls.add(new Wall(-22.05, 4.55, -19.05, 7.55, 0, 9, 1));// v9
        walls.add(new Wall(-21.05, 8.45, -22.05, 9.45, 0, 11, 1));// v9

        walls.add(new Wall(-19.05, 7.55, -17.55, 7.55, 0, 9, 1));// v10
        walls.add(new Wall(-17.55, 7.55, -17.55, 8.45, 0, 23, 1));// v10
        walls.add(new Wall(-17.55, 8.45, -21.05, 8.45, 0, 9, 1));// v10

        walls.add(new Wall(-22.05, -3.3, -22.05, 4.55, 0, 15, 1));// v11
        walls.add(new Wall(-22.05, 9.45, -22.05, 13.05, 0, 11, 1));// v11
        walls.add(new Wall(-19.05, 16.05, -5.95, 16.05, 0, 11, 1));// v11
        walls.add(new Wall(-2.05, 16.05, 6.55, 16.05, 0, 11, 1));// v11

        walls.add(new Wall(6.55, 16.05, 6.55, 11.55, 0, 11, 1));// v12
        walls.add(new Wall(9, 11.55, 6.55, 11.55, 0, 15, 1));// v12

        walls.add(new Wall(-2.05, 16.05, -2.05, 14.05, 0, 13, 1));// v13
        walls.add(new Wall(-2.05, 14.05, -5.95, 14.05, 0, 20, 1));// v13
        walls.add(new Wall(-5.95, 14.05, -5.95, 16.05, 0, 13, 1));// v13

        walls.add(new Wall(-22.05, 13.05, -19.05, 16.05, 0, 22, 1));// v14
    }

    public int isWall(double x, double y){
        double v1 = Math.abs(x-1+y-19) + Math.abs(x+1-y-10) + 1;
        double v2 = Math.abs(2*x-21.5+y+10.5)+Math.abs(2*x-13-y+10);
        double v3 = Math.abs(x-10-2*y)+Math.abs(x+15+2*y)-20;
        double v4 = Math.abs(0.7*x-13-2*y+22+7-2)+Math.abs(1.9*x-36+2*y+19+7-9)-6;
        double v5 = Math.abs(1.3*x+20-2*y+6)+Math.abs(x+15+2*y-20)-6;
        double v6 = Math.abs(2*x-10+11+y+13)+Math.abs(2*x-10+13-y+19);
        double v7 = Math.abs(2*x+y+32)+Math.abs(2*x-y+23);
        double v8 = Math.abs(x+30-2*y-21)+Math.abs(x+15+2*y+14) - 6;
        double v9 = Math.abs(x+21.5)+Math.abs(y-7);
        double v10 = Math.abs(x+3*y-24+20)+Math.abs(x-3*y+24+20);
        double v11 = Math.abs(x+y-3+9)+Math.abs(x-y-3-10);
        double v12 = Math.abs(x+y-15-10)+Math.abs(x-y+15-10);
        double v13 = Math.abs(x+y-16+4)+Math.abs(x-y+16+4);
        double v14 = Math.abs(x+21.5)+Math.abs(y-15.5);

        if(v1 < 13) return 1;
        if(v2<3) return 1;
        if(v3<3) return 1;
        if (v4<3) return 1;
        if(v5<3) return 1;
        if(v6 < 3) return 1;
        if(v7 < 8) return 1;
        if(v8 < 3) return 1;
        if(v9 < 3) return 1;
        if(v10 < 6) return 1;
        if(v11 > 50) return 1;
        if(v12 < 8) return 1;
        if(v13 < 5) return 1;
        if(v14 < 3) return 1;
        return 0;
    }

    public ArrayList<Wall> getWalls() {
        return walls;
    }

    public void addWall(Wall wall){
        walls.add(wall);
    }

    public Map copy(){
        Map temp = new Map();
        temp.walls = (ArrayList<Wall>)walls.clone();
        return temp;
    }

    @Override
    public Object clone() throws CloneNotSupportedException{
        return super.clone();
    }
}
