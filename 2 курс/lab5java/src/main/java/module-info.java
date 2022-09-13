module com.example.db {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens com.example.db to javafx.fxml;
    exports com.example.db;
}