package pack.model.api.in;
import pack.model.api.out.IUsersRep;

public interface IUserModel {
    boolean checkHash(char[] hash);
    byte[] auth(String email, String password);
    void injectRepository(IUsersRep repository);
}
