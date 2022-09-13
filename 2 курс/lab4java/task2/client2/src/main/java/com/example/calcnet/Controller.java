package com.example.calcnet;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.io.IOException;

public class Controller {
    private Net net;
    @FXML
    private Button send;
    @FXML
    private TextField in_match;
    @FXML
    private Label current_status, match;


    public Controller() {
    }
    int i =1;
    @FXML
    public void initialize() {
        this.net = new Net();
    }

    @FXML
    private void send_to() throws IOException {

        if(i==2) {
            this.net.getOut().write(Integer.valueOf(match.getText()));
            this.net.getOut().write(Integer.valueOf(in_match.getText()));
            this.net.getOut().flush();
            this.in_match.setText("0");
            this.current_status.setText("Ожидайте соперника");
            this.send.setText("Обновить");
            this.match.setText(String.valueOf(this.net.getIn().read()));
            i++;
        }
        else if(i==3) {
            System.out.println(i);
            this.send.setText("Отправить");

            this.match.setText(String.valueOf(this.net.getIn().read()));
            this.net.getOut().write(Integer.valueOf(match.getText())); this.net.getOut().write(0);
            this.net.getOut().flush();
            i--;
        }
        else if(i==1){
            System.out.println(i);
            this.send.setText("Отправить");

            this.match.setText(String.valueOf(this.net.getIn().read()));
            this.net.getOut().write(Integer.valueOf(match.getText()));
            this.net.getOut().write(0);
            this.net.getOut().flush();
            i++;
        }
        System.out.println(i);

    }
}


