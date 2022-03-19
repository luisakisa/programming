module com.example.exercise4 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.exercise4 to javafx.fxml;
    exports com.example.exercise4;
}