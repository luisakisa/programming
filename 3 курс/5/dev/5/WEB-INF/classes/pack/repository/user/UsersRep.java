package pack.repository.user;
import java.util.List;

import jakarta.annotation.Resource;
import jakarta.persistence.*;
import jakarta.transaction.*;
import jakarta.transaction.RollbackException;
import pack.model.api.out.IUsersRep;

public class UsersRep implements IUsersRep{

    @PersistenceUnit(unitName = "pg_persistence_unit")
    private EntityManagerFactory entityManagerFactory;
   
    @Resource
    private UserTransaction userTransaction;
 

  public boolean selectUsers(String login, String password) {
    EntityManager entityManager= entityManagerFactory.createEntityManager();
    try {
        userTransaction.begin();
    } catch (NotSupportedException | SystemException e) {
        e.printStackTrace();
    }
    entityManager.joinTransaction();
    List<EUser> user = entityManager.createQuery("SELECT u FROM EUser u where u.login='"+login+"' and u.password='"+password+"';",EUser.class).getResultList();

    try {
        userTransaction.commit();
    } catch (SecurityException | IllegalStateException | RollbackException | HeuristicMixedException
            | HeuristicRollbackException | SystemException e) {
        e.printStackTrace();
    }
    if(user != null){
    return true;
    }    return false;
}
}
