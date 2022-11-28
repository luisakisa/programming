package DB;

import java.sql.SQLException;
import java.util.ArrayList;

import model.objects.EProduct;

public interface  IDB {
    ArrayList<EProduct> selectProducts() throws SQLException, ClassNotFoundException;
    ArrayList<EProduct> selectBasket() throws SQLException, ClassNotFoundException;
    void insertToBasket(int id) throws SQLException, ClassNotFoundException;
    void deleteFromBasket(int id) throws SQLException, ClassNotFoundException;
    boolean selectUsers(String login, String password) throws SQLException, ClassNotFoundException;
}
