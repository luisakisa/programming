module com.example.exercise3 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.exercise3 to javafx.fxml;
    exports com.example.exercise3;
}