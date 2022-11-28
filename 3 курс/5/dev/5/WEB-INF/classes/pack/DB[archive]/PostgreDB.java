package DB;

import java.sql.*;
import java.util.ArrayList;

import model.objects.Product;


public class  PostgreDB implements IDB{


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
    public  void deleteFromBasket(int id) throws SQLException, ClassNotFoundException {
        Statement statement = getDbConnection().createStatement();
        String query = "delete from public.basket where id= "+id;
        statement.executeUpdate(query);
    }


    public void insertToBasket(int id) throws SQLException, ClassNotFoundException {
        Statement statement = getDbConnection().createStatement();
        String query = "select * from public.products where id = "+id;
        ResultSet rs = statement.executeQuery(query);
        rs.next();
        query = "INSERT INTO public.basket (id, name, parametrs, total) VALUES ("+rs.getInt(1)+", '"+rs.getString(2)+"', '"+rs.getString(3)+"', "+rs.getInt(4)+");";
        statement.executeUpdate(query);
    }
    public ArrayList<Product> selectBasket() throws SQLException, ClassNotFoundException {
        ArrayList<Product> Products = new ArrayList<Product>();
        String query = "select * from public.basket;";

        Statement statement = getDbConnection().createStatement();
        ResultSet rs = statement.executeQuery(query);
        while (rs.next()) {

            int id = rs.getInt(1);
            String name = rs.getString(2);
            String parametrs = rs.getString(3);
            int total = rs.getInt(4);
            Product Product = new Product(id, name, parametrs, total);
            Products.add(Product);
        }
        return Products;
    }
    public ArrayList<Product> selectProducts() throws SQLException, ClassNotFoundException {
        ArrayList<Product> Products = new ArrayList<Product>();
        String query = "select * from public.products;";

        Statement statement = getDbConnection().createStatement();
        ResultSet rs = statement.executeQuery(query);
        while (rs.next()) {

            int id = rs.getInt(1);
            String name = rs.getString(2);
            String parametrs = rs.getString(3);
            int total = rs.getInt(4);
            Product Product = new Product(id, name, parametrs, total);
            Products.add(Product);
        }
        return Products;
    }

    public boolean selectUsers(String login, String password) throws SQLException, ClassNotFoundException {
        String query = "select * from public.users where login='"+login+"' and password='"+password+"';";
        Statement statement = getDbConnection().createStatement();
        ResultSet rs = statement.executeQuery(query);
 
        if(rs.next()){
        return true;
        }
        return false;
    }


}

