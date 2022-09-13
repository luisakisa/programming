package com.company;

import java.sql.*;

class DB {

    public static void main(String args[]) {

        System.out.println("Testing DB...");

        try {

            //DriverManager.RegisterDriver(new org.postgresql.Driver());
            Class.forName("org.postgresql.Driver");

            String url = "jdbc:postgresql://localhost:5432/Test";
            String login = "postgres";
            String password = "123456";
            System.out.println("Getting connection...");
            System.out.println("Before...");
            Connection con = DriverManager.getConnection(url, login, password);
            System.out.println("After");
            System.out.println("OK");
            try
            {
                Statement stmt = con.createStatement();
                //ResultSet rs = stmt.executeQuery("SELECT * FROM pg_class");
                ResultSet rs = stmt.executeQuery("SELECT * FROM \"Students\"");
                while (rs.next()) {
                    //String str = rs.getString("relname") + " " + rs.getString("reltype");
                    String str = rs.getString("Student_ID") + " " + rs.getString("Student_Name");
                    System.out.println(str);
                }
                rs.close();
                stmt.close();
            } finally {
                con.close();
            }
        }
        catch (Exception e) {
            //e.printStackTrace();
            //System.out.println(e.getMessage());
            System.out.println("Catch");
            System.out.println("Connection error!");

        }
    }
}

