module com.example.calcnet {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.calcnet to javafx.fxml;
    exports com.example.calcnet;
}