package DB;
import java.sql.SQLException;


public class Auth {
    String login;
    String password;
    public Auth(String login,String password) throws SQLException, ClassNotFoundException {
        this.login =login;
        this.password = password;
    }
    public static boolean auth(String login, String password) throws SQLException, ClassNotFoundException {
        if(DB.selectUsers(login,password)){
            return true;
        }
        return false;
    }
}
