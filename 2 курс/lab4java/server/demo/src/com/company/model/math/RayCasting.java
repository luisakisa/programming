package com.company.model.math;

import com.company.model.map.Wall;
import com.company.model.game.WallCharacter;
import com.company.model.map.WallPoint;
import com.company.model.game.WallPointCharacter;

import java.util.ArrayList;

public class RayCasting
{
    public static WallPoint rayCasting(Section section, ArrayList<Wall> walls){
        ArrayList<WallPoint> wallPoints = new ArrayList<>();
        for(int i = 0; i < walls.size(); i++){
            Section temp = walls.get(i).getSection();
            double z1 = section.crossProduct(new Section(section.getA(), temp.getA()));
            double z2 = section.crossProduct(new Section(section.getA(), temp.getB()));
            if(Math.signum(z1) != Math.signum(z2)){
                double q1 = temp.getA().getX() + (temp.getB().getX() - temp.getA().getX()) * Math.abs(z1) / Math.abs(z2 - z1);
                double q2 = temp.getA().getY() + (temp.getB().getY() - temp.getA().getY()) * Math.abs(z1) / Math.abs(z2 - z1);
                double lA = section.getA().distance(new Point(q1, q2));
                double lB = section.getB().distance(new Point(q1, q2));
                if(lA > lB) {
                    double l = new Section(temp.getA(), new Point(q1, q2)).length();
                    double k = (l / walls.get(i).getTextureWidth()) - (int)(l / walls.get(i).getTextureWidth());
                    if(walls.get(i).getClass() == WallCharacter.class)
                    {
                        WallCharacter wc = (WallCharacter)walls.get(i);
                        wallPoints.add(new WallPointCharacter(lA, walls.get(i).getTextureID(), k, wc.getCharacter()));
                    }
                    else
                    {
                        wallPoints.add(new WallPoint(lA, walls.get(i).getTextureID(), k));
                    }
                }
            }
        }

        WallPoint min = new WallPoint(1000, 0, 0);
        for(int i = 0; i < wallPoints.size(); i++){
            if(wallPoints.get(i).getDistance() < min.getDistance()){
                min = wallPoints.get(i);
            }

        }

        return min;
    }

}
