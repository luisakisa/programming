package DB;

import java.sql.SQLException;
import java.util.ArrayList;

import model.objects.People;

public interface  IDB {
    ArrayList<People> select() throws SQLException, ClassNotFoundException;
    void insert(People people) throws SQLException, ClassNotFoundException;
    void delete(int id) throws SQLException, ClassNotFoundException;
    boolean selectUsers(String login, String password) throws SQLException, ClassNotFoundException;
}
