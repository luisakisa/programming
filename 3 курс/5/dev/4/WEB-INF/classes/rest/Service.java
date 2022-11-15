package rest;
import model.IModel;
import model.objects.*;
import jakarta.inject.Inject;
import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.ws.rs.*;
import jakarta.ws.rs.core.Response;

import java.sql.SQLException;
import java.util.ArrayList;

@Path("/")
public class Service {

  @Inject
  IModel model;

  @DELETE
  @Path("/deleting/{id}")
  public void delete(@PathParam("id") int id) throws ClassNotFoundException, SQLException {
    model.deleteProduct(id);
  }

  @PUT
  @Path("/adding/{id}")
  public void add(@PathParam("id") int id) throws ClassNotFoundException, SQLException {
    model.addProduct(id);
  }
  @POST
  @Path("/basket")
  @Consumes("text/plain")
  @Produces("application/json")
  public Response tableBasket(String hash) throws ClassNotFoundException, SQLException {
    if (model.checkHash(hash.toCharArray())) {
      ArrayList<Product> products = model.findProductsBasket();
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
  public Response tableProducts(String hash) throws ClassNotFoundException, SQLException {
    if (model.checkHash(hash.toCharArray())) {
      ArrayList<Product> products = model.findAllProducts();
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
  public byte[] autorization(String userJSON) throws ClassNotFoundException, SQLException {
    Jsonb jsonb = JsonbBuilder.create();
    User user = jsonb.fromJson(userJSON, User.class);

    byte[] hash = model.auth(user.getEmail(), user.getPassword());
    return hash;
  }
}