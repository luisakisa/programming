package com.example.demo1;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;

public class HelloController {
    @FXML
    private Button btn;
    public TextField text1;
    public TextField text2;
    @FXML
    protected void onHelloButtonClick() {

        if (text1.getText() != ""){
            text2.setText(text1.getText());
            text1.clear();
            btn.setText("<-");
        }
        else if (text2.getText() != ""){
            text1.setText(text2.getText());
            text2.clear();
            btn.setText("->");
        }

   }
}