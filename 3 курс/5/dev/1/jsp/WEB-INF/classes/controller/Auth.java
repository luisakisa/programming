package controller;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Objects;

public class Auth {
    String login;
    String password;
    public Auth(String login,String password) throws SQLException, ClassNotFoundException {
        this.login =login;
        this.password = password;
    }
    public static boolean authorization(String login, String password) throws SQLException, ClassNotFoundException {
        if(DB.selectUsers(login,password)){
            return true;
        }
        return false;
    }
}
