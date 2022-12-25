package pack.repository.basket;
import java.util.ArrayList;
import java.util.List;

import jakarta.annotation.Resource;
import jakarta.persistence.*;
import jakarta.transaction.*;
import jakarta.transaction.RollbackException;
import pack.model.api.dto.Product;
import pack.model.api.out.IBasketRep;

public class BasketRep  implements IBasketRep{


    @PersistenceUnit(unitName = "pg_persistence_unit")
    private EntityManagerFactory entityManagerFactory;
   
    @Resource
    private UserTransaction userTransaction;

    

  public void deleteProduct(int id) {
    EntityManager entityManager= entityManagerFactory.createEntityManager();
    try {
        userTransaction.begin();
    } catch (NotSupportedException | SystemException e) {
        e.printStackTrace();
    }
    entityManager.joinTransaction();
    EBasket productFind = entityManager.find(EBasket.class,id);	
    if(productFind != null){
        entityManager.remove(productFind);
      }
      try {
        userTransaction.commit();
    } catch (SecurityException | IllegalStateException | RollbackException | HeuristicMixedException
            | HeuristicRollbackException | SystemException e) {
        e.printStackTrace();
    }
  }

  public ArrayList<Product> findProductsBasket(){
    EntityManager entityManager= entityManagerFactory.createEntityManager();
    try {
        userTransaction.begin();
    } catch (NotSupportedException | SystemException e) {
        e.printStackTrace();
    }
    entityManager.joinTransaction();
    List<EBasket> EProducts = entityManager.createQuery("SELECT b FROM EBasket b",EBasket.class).getResultList();
    try {
        userTransaction.commit();
    } catch (SecurityException | IllegalStateException | RollbackException | HeuristicMixedException
            | HeuristicRollbackException | SystemException e) {
        e.printStackTrace();
    }
    ArrayList<Product> products =  new ArrayList<>();
    for (EBasket Eptoduct: EProducts){
        Product p = new Product();
        p.setId(Eptoduct.getId());
        p.setName(Eptoduct.getName());
        p.setParametrs(Eptoduct.getParametrs());
        p.setTotal(Eptoduct.getTotal());
        products.add(p);
    }
    return products;
  }


}
