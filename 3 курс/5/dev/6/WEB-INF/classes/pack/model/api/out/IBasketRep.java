package pack.model.api.out;

import java.util.ArrayList;

import pack.model.api.dto.Product;

public interface IBasketRep {
    ArrayList<Product> findProductsBasket();
    void deleteProduct(int id);
}
