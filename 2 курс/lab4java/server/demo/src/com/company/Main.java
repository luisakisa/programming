package com.company;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.fxml.FXMLLoader;
import javafx.stage.StageStyle;

public class Main extends Application{
    public static void main(String[] args) {
        System.out.println("Main.main()");
	    Application.launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception{
        System.out.println("Main.start()");
        Parent root = FXMLLoader.load(getClass().getResource("view/main/MainView.fxml"));
        Scene scene = new Scene(root);
        stage.setScene(scene);

        stage.setTitle("Tvinky");
        stage.setWidth(800);
        stage.setHeight(600);
        stage.setMaxWidth(800);
        stage.setMaxHeight(600);
        stage.setMinWidth(800);
        stage.setMinHeight(600);
        //stage.initStyle(StageStyle.UNDECORATED);

        stage.show();
    }
}
