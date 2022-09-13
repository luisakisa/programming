package com.company.view.option;

import com.company.view.Info;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.event.ActionEvent;

public class OptionController{

    @FXML
    private Button backBtn;

    @FXML
    private Button changeRenderingBtn;

    @FXML
    private void clickBackBtn(ActionEvent event) throws Exception{
        System.out.println("gui.OptionController.clickBackBtn()");
        Scene theScene = backBtn.getScene();
        Parent theRoot = FXMLLoader.load(getClass().getResource("../main/MainView.fxml"));
        theScene.setRoot(theRoot);
    }
}
