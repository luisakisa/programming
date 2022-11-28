package pack.model.api.in;
import pack.model.api.dto.Product;
import pack.model.api.out.IBasketRep;

import java.util.ArrayList;


public interface IBasketModel {
  void deleteProduct(int id);
  ArrayList<Product> findProductsBasket();
 void injectRepository(IBasketRep repository);
}