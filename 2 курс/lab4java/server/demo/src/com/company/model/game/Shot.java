package com.company.model.game;

import com.company.model.math.Section;

import java.io.Serializable;

public class Shot implements Serializable {
    private Character character;
    private Section section;

    public Shot(Section section, Character character){
        this.character = character;
        this.section = section;
    }

    public Character getCharacter() {
        return character;
    }

    public Section getSection() {
        return section;
    }
}
