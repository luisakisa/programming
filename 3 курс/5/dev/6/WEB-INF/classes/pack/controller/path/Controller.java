package pack.controller.path;

import jakarta.ws.rs.Path;
import jakarta.ws.rs.PathParam;
import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.PUT;
import jakarta.ws.rs.Produces;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.DELETE;
import jakarta.ws.rs.core.Response;

import jakarta.ws.rs.core.Context;
import jakarta.ws.rs.container.ContainerRequestContext;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.json.bind.JsonbException;

import jakarta.inject.Inject;

// import pack.controller.interceptor.IdRequired;

import pack.builder.Built;

import java.util.ArrayList;

import pack.model.api.dto.Product;
import pack.model.api.dto.User;
import pack.model.api.in.IBasketModel;
import pack.model.api.in.IUserModel;
import pack.model.api.in.IProductModel;

@Path("/")
public class Controller {

  @Inject
  @Built
  IBasketModel MB;

  @Inject
  @Built
  IProductModel MP;

  @Inject
  @Built
  IUserModel MU;

  @DELETE
  @Path("/deleting/{id}")
  public void delete(@PathParam("id") int id) {
    MB.deleteProduct(id);
  }

  @PUT
  @Path("/adding/{id}")
  public void add(@PathParam("id") int id) {
    MP.addProduct(id);
  }

  @POST
  @Path("/basket")
  @Consumes("text/plain")
  @Produces("application/json")
  public Response tableBasket(String hash) {
    if (MU.checkHash(hash.toCharArray())) {
      ArrayList<Product> products = MB.findProductsBasket();
      Jsonb jsonb = JsonbBuilder.create();
      String productsJSON = jsonb.toJson(products);
      return Response.ok(productsJSON).build();
    } else
      return Response.ok("0").build();
  }

  @POST
  @Path("/products")
  @Consumes("text/plain")
  @Produces("application/json")
  public Response tableProducts(String hash) {
    if (MU.checkHash(hash.toCharArray())) {
      ArrayList<Product> products = MP.findAllProducts();
      Jsonb jsonb = JsonbBuilder.create();
      String productsJSON = jsonb.toJson(products);
      return Response.ok(productsJSON).build();
    } else
      return Response.ok("0").build();
  }

  @POST
  @Path("/login")
  @Consumes("application/json")
  @Produces("text/plain")
  public byte[] autorization(String userJSON) {
    Jsonb jsonb = JsonbBuilder.create();
    User user = jsonb.fromJson(userJSON, User.class);

    byte[] hash = MU.auth(user.getEmail(), user.getPassword());
    return hash;
  }
}