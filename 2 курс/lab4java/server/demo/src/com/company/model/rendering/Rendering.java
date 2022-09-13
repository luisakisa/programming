package com.company.model.rendering;

import com.company.model.game.Character;
import com.company.model.map.WallPoint;
import com.company.model.math.Angles;
import com.company.model.math.RayCasting;
import com.company.model.math.Section;
import com.company.model.game.Game;

public class Rendering extends Thread {

    private Character character;
    private Game game;
    private Screen screen;
    private boolean renderingLaunched;
    private boolean renderingOnPause;

    public Rendering(Character character, Game game) {
        this.screen = new Screen();
        this.character = character;
        this.game = game;
        renderingLaunched = false;
        renderingOnPause = false;
    }

    public boolean isRenderingLaunched() {
        return renderingLaunched;
    }

    public void setLaunched(boolean renderingLaunched) {
        this.renderingLaunched = renderingLaunched;
    }

    public void setRenderingOnPause(boolean renderingOnPause) {
        this.renderingOnPause = renderingOnPause;
    }

    public boolean isRenderingOnPause(){
        return renderingOnPause;
    }

    public Screen getScreen() {
        return this.screen;
    }

    @Override
    public void run() {
        renderingLaunched = true;
        double radX, radY, angRad;
        while (renderingLaunched) {
            if(!renderingOnPause){
                try { this.sleep(1); } catch (Exception e) {}

                int[][] temp = new int[800][6];
                double[] width = new double[800];

                angRad = (character.getAng() - Angles.Ang30);

                for (int rad = 0; rad < Angles.Ang60; rad++) {
                    radX = character.getX();
                    radY = character.getY();

                    WallPoint distant = RayCasting.rayCasting(new Section(radX, radY,
                            radX + Math.cos(Angles.convert(character.getAng() + Angles.Ang30 - rad)),
                            radY + Math.sin(Angles.convert(character.getAng() + Angles.Ang30 - rad))),
                            game.getMap().getWalls());

                    int heightWall = (int)(250 / (distant.getDistance() * Math.cos(Angles.convert(angRad) - Angles.convert(character.getAng()))));

                    temp[rad][0] = rad;
                    temp[rad][1] = 300 - heightWall;
                    temp[rad][2] = 300 + heightWall;
                    temp[rad][3] = 600;
                    temp[rad][4] = 0;
                    temp[rad][5] = distant.getTextureID();
                    width[rad] = distant.getTextureK();

                    angRad++;
                }
                temp[400][1] = 250;
                temp[400][2] = 350;
                this.screen.setScreen(temp, width);
            }
            else try { this.sleep(10);} catch (Exception e) {}
        }
    }
}
