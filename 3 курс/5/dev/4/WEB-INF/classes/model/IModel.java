package model;
import model.objects.Product;

import java.sql.SQLException;
import java.util.ArrayList;


public interface IModel {
  byte[] auth(String email, String password) throws ClassNotFoundException, SQLException;
  ArrayList<Product> findAllProducts() throws ClassNotFoundException, SQLException;
  void deleteProduct(int id) throws ClassNotFoundException, SQLException;
  void addProduct(int id) throws ClassNotFoundException, SQLException;
  boolean checkHash(char[] hash);
  public ArrayList<Product> findProductsBasket() throws ClassNotFoundException, SQLException;
}