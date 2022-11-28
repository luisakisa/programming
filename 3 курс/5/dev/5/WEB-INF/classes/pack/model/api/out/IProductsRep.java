package pack.model.api.out;

import java.util.ArrayList;

import pack.model.api.dto.Product;

public interface IProductsRep {
    void addProduct(int id);
    ArrayList<Product> findAllProducts();
}
