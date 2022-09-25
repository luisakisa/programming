package controller;

import java.sql.*;
import java.util.ArrayList;

/**
 * Simple Java program to connect to MySQL database running on localhost and
 * running SELECT and INSERT query to retrieve and add data.
 * @author Javin Paul
 */
public class  DB {


    private static Connection getDbConnection() throws ClassNotFoundException, SQLException {
        Class.forName("org.postgresql.Driver");
        String url = "jdbc:postgresql://127.0.0.1:5432/postgres";
        String login = "postgres";
        String password = "Qweqweqwe_123";
        System.out.println("Getting connection...");
        Connection con = DriverManager.getConnection(url, login, password);
        System.out.println("OK");
        return con;
    }
    public static void delete(int id) throws SQLException, ClassNotFoundException {
        Statement statement = getDbConnection().createStatement();
        String query = "delete from public.data_lab1 where id= "+id;
        statement.executeUpdate(query);
    }


    public static void insert(People people) throws SQLException, ClassNotFoundException {
        Statement statement = getDbConnection().createStatement();
        String query = "SELECT * FROM public.data_lab1 ORDER BY id DESC LIMIT 1";
        ResultSet rs = statement.executeQuery(query);
        rs.next();
        int id = rs.getInt(4);
        id++;
        query = "INSERT INTO public.data_lab1 (id, name, surname, patronymic) VALUES ("+id+", '"+people.getName()+"', '"+people.getSurname()+"', '"+people.getPatronymic()+"');";
        statement.executeUpdate(query);
    }
    public static ArrayList<People> select() throws SQLException, ClassNotFoundException {
        ArrayList<People> peoples = new ArrayList<People>();
        String query = "select * from public.data_lab1;";

        Statement statement = getDbConnection().createStatement();
        ResultSet rs = statement.executeQuery(query);
        while (rs.next()) {

            int id = rs.getInt(4);
            String name = rs.getString(1);
            String surname = rs.getString(2);
            String patronymic = rs.getString(3);
            People people = new People(id, name, surname, patronymic);
            peoples.add(people);
        }
        return peoples;
    }

    public static boolean selectUsers(String login, String password) throws SQLException, ClassNotFoundException {
        String query = "select * from public.users where login='"+login+"' and password='"+password+"';";
        Statement statement = getDbConnection().createStatement();
        ResultSet rs = statement.executeQuery(query);
 
        if(rs.next()){
        return true;
        }
        return false;
    }


}

