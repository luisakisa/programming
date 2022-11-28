package pack.model;

import java.util.ArrayList;


import pack.model.api.dto.Product;
import pack.model.api.in.IProductModel;
import pack.model.api.out.IProductsRep;


public class ProductModel implements IProductModel {
 
  IProductsRep repository;

    
    @Override
    public void injectRepository(IProductsRep repository) {
      this.repository = repository;
    } 



  @Override
  public void addProduct(int id) {
    repository.addProduct(id);
  }
  
  @Override
  public ArrayList<Product> findAllProducts() {
    ArrayList<Product> products =  repository.findAllProducts();
    return products; 
  }
}
