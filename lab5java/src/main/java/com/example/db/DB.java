package com.example.db;

import java.sql.*;
import java.util.ArrayList;

public class DB {
    private int n = 0;

    // Метод для подключения к БД с использованием значений выше
    private Connection getDbConnection() throws ClassNotFoundException, SQLException {
        Class.forName("oracle.jdbc.driver.OracleDriver");
        String url = "jdbc:oracle:thin:@localhost:1521:XE";
        String login = "system";
        String password = "Qweqweqwe_123";
        System.out.println("Getting connection...");
        Connection con = DriverManager.getConnection(url, login, password);
        System.out.println("OK");
        return con;
    }

    // Метод для добавления новых заданий внуть таблицы `todo`
    public void insertTask(String task) throws SQLException, ClassNotFoundException {
        n +=1;
        String sql = "INSERT INTO todo " + "(ID, TASK) " +"VALUES" + "("  + n + ",'" + task + "')";
        Statement statement = getDbConnection().createStatement();
        statement.executeUpdate(sql);

    }

    // Метод для получения всех заданий из таблицы todo
    public ArrayList<String> getTasks() throws SQLException, ClassNotFoundException {
        String sql = "SELECT * FROM todo ORDER BY id";

        Statement statement = getDbConnection().createStatement();
        ResultSet res = statement.executeQuery(sql);

        ArrayList<String> tasks = new ArrayList<>();
        while(res.next())
            tasks.add(res.getString("task"));

        return tasks;
    }

}
