package rest;
import jakarta.ws.rs.Path;
import jakarta.ws.rs.PathParam;
import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.DELETE;
import jakarta.ws.rs.PUT;

import jakarta.ws.rs.Produces;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.core.Response;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;

import jakarta.inject.Inject;

import java.sql.SQLException;
import java.util.ArrayList;


import model.IModel;
import model.objects.*;

@Path("/")
public class Service {

  @Inject
  IModel model;

  @DELETE
  @Path("/deleting/{id}")
  public void delete(@PathParam("id") int id) throws ClassNotFoundException, SQLException {
    model.deletePeople(id);
  }

  @PUT
  @Path("/new_people")
  @Consumes("application/json")
  @Produces("application/json")
  public Response add(String peopleJSON) throws ClassNotFoundException, SQLException {
    Jsonb jsonb = JsonbBuilder.create();
    People people = jsonb.fromJson(peopleJSON, People.class);
    ArrayList<People> peoples = model.addPeople(people);
    String peoplesJSON = jsonb.toJson(peoples);
    return Response.ok(peoplesJSON).build();
  }

  @POST
  @Path("/peoples")
  @Consumes("text/plain")
  @Produces("application/json")
  public Response table(String hash) throws ClassNotFoundException, SQLException {
    if (model.checkHash(hash.toCharArray())) {
      ArrayList<People> peoples = model.findAllPeoples();
      Jsonb jsonb = JsonbBuilder.create();
      String peoplesJSON = jsonb.toJson(peoples);
      return Response.ok(peoplesJSON).build();
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