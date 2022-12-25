package pack.model.api.in;
import pack.model.api.dto.Product;
import pack.model.api.out.IProductsRep;
import java.util.ArrayList;

public interface IProductModel {
    void injectRepository(IProductsRep repository);
    ArrayList<Product> findAllProducts();
    void addProduct(int id);
}
