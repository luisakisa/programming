module com.example.exercise5 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.exercise5 to javafx.fxml;
    exports com.example.exercise5;
}