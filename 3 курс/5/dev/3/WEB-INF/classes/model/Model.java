package model;

import java.sql.SQLException;
import java.util.ArrayList;

import DB.DBTypes;
import DB.FactoryDB;
import DB.IDB;
import model.objects.*;

public class Model implements IModel {
  private FactoryDB factory = new FactoryDB();
  private Password ps = new Password();

  IDB db  = factory.getDB(DBTypes.PostgreDB);

  @Override
  public ArrayList<People> addPeople(People people) throws ClassNotFoundException, SQLException {
    db.insert(people);
    return db.select();
  }

  @Override
  public void deletePeople(int id) throws ClassNotFoundException, SQLException {
    db.delete(id);
  }

  @Override
  public ArrayList<People> findAllPeoples() throws ClassNotFoundException, SQLException {
    return db.select();
  }

  @Override
  public byte[] auth(String email, String password) throws ClassNotFoundException, SQLException {
    String text = "nothash";
    byte[] notHash = text.getBytes();
    if (checkAuth(email, password)) {
      byte[] hash = ps.hash((password.toCharArray()));
      return hash;
    } else
      return notHash;
  }

  @Override
  public boolean checkHash(char[] hash) {
    return ps.isExpectedPassword(hash);

  }
  public boolean checkAuth(String login, String password) throws SQLException, ClassNotFoundException {
    if(db.selectUsers(login,password)){
        return true;
    }
    return false;
  }

}
