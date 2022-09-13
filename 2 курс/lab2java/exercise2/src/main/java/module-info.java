module com.example.exercise2 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.exercise2 to javafx.fxml;
    exports com.example.exercise2;
}