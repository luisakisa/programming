package pack.model;

import java.util.ArrayList;


import pack.model.api.dto.Product;
import pack.model.api.in.IBasketModel;
import pack.model.api.out.IBasketRep;


public class BasketModel implements IBasketModel {
 
  IBasketRep repository;

    
    @Override
    public void injectRepository(IBasketRep repository) {
      this.repository = repository;
    } 

  @Override
  public void deleteProduct(int id) {
    repository.deleteProduct(id);
  }
  @Override
  public ArrayList<Product> findProductsBasket()  {
    ArrayList<Product> products =  repository.findProductsBasket();
    return products; 
  }
}
