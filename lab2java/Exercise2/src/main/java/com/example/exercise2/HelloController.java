package com.example.exercise2;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class HelloController {
    @FXML
    public CheckBox check1;
    public CheckBox check2;
    public CheckBox check3;
    public Button btn;
    public TextField tx;
    public Slider sld;

    @FXML
    public void click() {
        if (check1.isSelected()) {
            btn.setVisible(false);
        } else {
            btn.setVisible(true);
        }

        if (check2.isSelected()) {
            sld.setVisible(false);
        } else {
            sld.setVisible(true);
        }
        if (check3.isSelected()) {
            tx.setVisible(false);
        } else {
            tx.setVisible(true);
        }
    }
}