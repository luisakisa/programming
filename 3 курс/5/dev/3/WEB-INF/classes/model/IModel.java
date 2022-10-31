package model;
import model.objects.People;

import java.sql.SQLException;
import java.util.ArrayList;


public interface IModel {
  byte[] auth(String email, String password) throws ClassNotFoundException, SQLException;
  ArrayList<People> findAllPeoples() throws ClassNotFoundException, SQLException;
  void deletePeople(int id) throws ClassNotFoundException, SQLException;
  ArrayList<People> addPeople(People people) throws ClassNotFoundException, SQLException;
  boolean checkHash(char[] hash);
}