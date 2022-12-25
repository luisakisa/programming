package pack.builder;

import pack.model.api.in.IProductModel;
import pack.model.api.out.IProductsRep;

import jakarta.inject.Inject;
import jakarta.enterprise.inject.Produces;
import jakarta.enterprise.inject.Default;



public class ProductsBuilder { 

    @Inject @Default
    private IProductModel model;

    @Inject @Default
    private IProductsRep repository;

    @Produces @Built
    public IProductModel buildModel() {
	   model.injectRepository(repository);
       return model;
    } 
}