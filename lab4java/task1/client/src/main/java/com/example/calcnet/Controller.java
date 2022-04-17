package com.example.calcnet;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class Controller {
    private Net net;
    @FXML
    private Button btn_plus;
    @FXML
    private Button btn_minus;
    @FXML
    private Button btn_mult;
    @FXML
    private Button btn_div;
    @FXML
    private Button btn_pow;
    @FXML
    private TextField txtf1;
    @FXML
    private TextField txtf2;
    @FXML
    private Label labe;

    public Controller() {
    }

    @FXML
    public void initialize() {
        this.net = new Net();
    }

    @FXML
    private void click_plus(ActionEvent event) {
        this.labe.setText(String.valueOf(Calculator.plus(Integer.valueOf(this.txtf1.getText()), Integer.valueOf(this.txtf2.getText()), this.net)));
    }

    @FXML
    private void click_minus(ActionEvent event) {
        this.labe.setText(String.valueOf(Calculator.minus(Integer.valueOf(this.txtf1.getText()), Integer.valueOf(this.txtf2.getText()), this.net)));
    }

    @FXML
    private void click_mult(ActionEvent event) {
        this.labe.setText(String.valueOf(Calculator.mult(Integer.valueOf(this.txtf1.getText()), Integer.valueOf(this.txtf2.getText()), this.net)));
    }

    @FXML
    private void click_div(ActionEvent event) {
        this.labe.setText(String.valueOf(Calculator.div(Integer.valueOf(this.txtf1.getText()), Integer.valueOf(this.txtf2.getText()), this.net)));
    }

    @FXML
    private void click_pow(ActionEvent event) {
        this.labe.setText(String.valueOf(Calculator.pow(Integer.valueOf(this.txtf1.getText()), Integer.valueOf(this.txtf2.getText()), this.net)));
    }
}
