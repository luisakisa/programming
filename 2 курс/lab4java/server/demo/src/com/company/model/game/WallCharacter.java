package com.company.model.game;

import com.company.model.game.Character;
import com.company.model.map.Wall;
import com.company.model.math.Angles;
import com.company.model.math.Point;
import com.company.model.math.Section;

import java.io.Serializable;

public class WallCharacter extends Wall implements Serializable {
    private Character character;
    private int angleA;
    private int angleB;

    public WallCharacter(Character character, int angleA, int angleB, int texture){
        super(character.getX(), character.getY(), character.getX() + 0.5, character.getY(), 1, texture, 0.2);
        this.angleA = angleA;
        this.angleB = angleB;
        this.character = character;
    }

    public Section getSection() {
        section.setA(new Point(character.getX() + Math.cos(Angles.convert(character.getAng() + angleA)) / 7,
                character.getY() + Math.sin(Angles.convert(character.getAng() + angleA)) / 7));
        section.setB(new Point(character.getX() + Math.cos(Angles.convert(character.getAng() + angleB)) / 7,
                character.getY() + Math.sin(Angles.convert(character.getAng() + angleB)) / 7));
        return section;
    }

    public Character getCharacter() {
        return character;
    }

    @Override
    public void setTextureID(int textureID) {
        super.setTextureID(textureID);
    }
}
