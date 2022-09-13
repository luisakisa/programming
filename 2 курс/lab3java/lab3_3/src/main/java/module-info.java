module com.example.lab3_3 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.lab3_3 to javafx.fxml;
    exports com.example.lab3_3;
}