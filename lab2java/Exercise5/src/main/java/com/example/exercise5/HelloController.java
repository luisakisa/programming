package com.example.exercise5;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;

public class HelloController {
    @FXML
    public RadioButton c1,c2,c3,c4,c5,c6,c7,c8,c9;
    public Label fl;
    ToggleGroup group = new ToggleGroup();
    ToggleGroup group1 = new ToggleGroup();
    ToggleGroup group2 = new ToggleGroup();
    public Button btn;
    int clicks = 0;
    public void onRB() {
        c1.setToggleGroup(group);
        c2.setToggleGroup(group);
        c3.setToggleGroup(group);
        c4.setToggleGroup(group1);
        c5.setToggleGroup(group1);
        c6.setToggleGroup(group1);
        c7.setToggleGroup(group2);
        c8.setToggleGroup(group2);
        c9.setToggleGroup(group2);
    }
    @FXML
    protected void on() {
        if(clicks!=0){ fl.setText("Текстовый флаг:");}
        if (c1.isSelected()){
            fl.setText(fl.getText() + " "+ c1.getText());
        }
        if (c2.isSelected()){
            fl.setText(fl.getText() + " "+ c2.getText());
        }
        if (c3.isSelected()){
            fl.setText(fl.getText() + " "+ c3.getText());
        }

        if (c4.isSelected()){
            fl.setText(fl.getText() + " "+ c4.getText());
        }
        if (c5.isSelected()){
            fl.setText(fl.getText() + " "+ c5.getText());
        }
        if (c6.isSelected()){
            fl.setText(fl.getText() + " "+ c6.getText());
        }
        c7.setToggleGroup(group2);
        c8.setToggleGroup(group2);
        c9.setToggleGroup(group2);
        if (c7.isSelected()){
            fl.setText(fl.getText() + " "+ c7.getText());
        }
        if (c8.isSelected()){
            fl.setText(fl.getText()+ " " + c8.getText());
        }
        if (c9.isSelected()){
            fl.setText(fl.getText() + " "+ c9.getText());
        }
        clicks ++;
    }
}