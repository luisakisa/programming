package pack.builder;

import pack.model.api.in.IUserModel;
import pack.model.api.out.IUsersRep;

import jakarta.inject.Inject;
import jakarta.enterprise.inject.Produces;

import jakarta.enterprise.inject.Default;



public class UsersBuilder { 

    @Inject @Default
    private IUserModel model;

    @Inject @Default
    private IUsersRep repository;

    @Produces @Built
    public IUserModel buildModel() {
	   model.injectRepository(repository);
       return model;
    } 
}