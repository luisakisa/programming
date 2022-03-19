package com.example.exercise3;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HelloController {
    @FXML
    public Button btn;
    public Label pricePizza;
    public Label priceCola;
    public Label priceRolls;
    public Label priceTom;
    public Label cheque;
    public TextField quantity1;
    public TextField quantity2;
    public TextField quantity3;
    public TextField quantity4;
    public CheckBox c1;
    public CheckBox c2;
    public CheckBox c3;
    public CheckBox c4;

    @FXML
    protected void onButtonClick() {
        int p = Integer.parseInt (quantity1.getText());
        int c = Integer.parseInt (quantity2.getText());
        if (c2.isSelected()) {
            c = c * 100;
        } else c=0;
        priceCola.setText(String.valueOf(c));
        int r = Integer.parseInt (quantity3.getText());
        if(c3.isSelected()) {
            r = r * 900;
        }else r=0;
        priceRolls.setText(String.valueOf(r));
        int t = Integer.parseInt (quantity4.getText());
        if(c4.isSelected()) {
            t = t * 400;
        }else t=0;
        priceTom.setText(String.valueOf(t));

        if (c1.isSelected()){

            p = p *500;
        }
        else { p= 0;}
        pricePizza.setText(String.valueOf(p));
        cheque.setText(String.valueOf(p+c+r+t));
    }
}
