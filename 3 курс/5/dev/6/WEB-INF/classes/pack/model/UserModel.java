package pack.model;

import pack.model.api.dto.Password;
import pack.model.api.in.IUserModel;
import pack.model.api.out.IUsersRep;



public class UserModel implements IUserModel{
    private Password ps = new Password();

    IUsersRep repository;
  
    @Override
    public void injectRepository(IUsersRep repository) {
      this.repository = repository;
    } 

    @Override
    public byte[] auth(String email, String password) {
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
    public boolean checkAuth(String login, String password)  {
      if(repository.selectUsers(login,password)){
          return true;
      }
      return false;
    }
  
}
