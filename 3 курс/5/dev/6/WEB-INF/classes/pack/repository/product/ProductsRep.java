package pack.repository.product;
import java.util.ArrayList;
import java.util.List;

import jakarta.annotation.Resource;
import jakarta.persistence.*;
import jakarta.transaction.*;
import jakarta.transaction.RollbackException;
import pack.model.api.dto.Product;
import pack.model.api.out.IProductsRep;

public class ProductsRep  implements IProductsRep{
    @PersistenceUnit(unitName = "pg_persistence_unit")
    private EntityManagerFactory entityManagerFactory;
   
    @Resource
    private UserTransaction userTransaction;
  
 

   public void addProduct(int id) {
    EntityManager entityManager= entityManagerFactory.createEntityManager();
    try {
        userTransaction.begin();
    } catch (NotSupportedException e) {
        e.printStackTrace();
    } catch (SystemException e) {
        e.printStackTrace();
    }
    entityManager.joinTransaction();
    EProduct productFind = entityManager.find(EProduct.class,id);	
    entityManager.persist(productFind);
    entityManager.flush();
    try {
        userTransaction.commit();
    } catch (SecurityException | IllegalStateException | RollbackException | HeuristicMixedException
            | HeuristicRollbackException | SystemException e) {
        e.printStackTrace();
    }
  }


  public ArrayList<Product> findAllProducts(){
    EntityManager entityManager= entityManagerFactory.createEntityManager();
    try {
        userTransaction.begin();
    } catch (NotSupportedException | SystemException e) {
        e.printStackTrace();
    }
    entityManager.joinTransaction();
    List<EProduct> EProducts = entityManager.createQuery("SELECT p FROM EProduct p",EProduct.class).getResultList();
    try {
        userTransaction.commit();
    } catch (SecurityException | IllegalStateException | RollbackException | HeuristicMixedException
            | HeuristicRollbackException | SystemException e) {
        e.printStackTrace();
    }
    ArrayList<Product> products =  new ArrayList<>();
    for (EProduct Eptoduct: EProducts){
        Product p = new Product();        p.setId(Eptoduct.getId());
        p.setName(Eptoduct.getName());
        p.setParametrs(Eptoduct.getParametrs());
        p.setTotal(Eptoduct.getTotal());
        products.add(p);
    }
    return products;
  }
}


