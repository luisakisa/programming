
import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;

import jakarta.ws.rs.Produces;
import jakarta.ws.rs.Consumes;

import jakarta.ws.rs.core.Response;
import objects.People;
import objects.User;
import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.json.bind.JsonbException;

import java.security.SecureRandom;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import DB.Auth;
import DB.DB;

@Path("/")
public class Service {
  User user = new User();
  Password ps = new Password();

  @POST
  @Path("/deletion")
  @Consumes("text/plain")
  @Produces("application/json")
  public Response delete(String id) throws ClassNotFoundException, SQLException {
    DB.delete(Integer.parseInt(id));
    Jsonb jsonb = JsonbBuilder.create();
    ArrayList<People> peoples = DB.select();
    String peoplesJSON = jsonb.toJson(peoples);
    return Response.ok(peoplesJSON).build();
  }

  @POST
  @Path("/adding")
  @Consumes("application/json")
  @Produces("application/json")
  public Response add(String peopleJSON) throws ClassNotFoundException, SQLException {
    Jsonb jsonb = JsonbBuilder.create();
    People people = jsonb.fromJson(peopleJSON, People.class);
    DB.insert(people);
    ArrayList<People> peoples = DB.select();
    String peoplesJSON = jsonb.toJson(peoples);
    return Response.ok(peoplesJSON).build();
  }

  @POST
  @Path("/table")
  @Consumes("text/plain")
  @Produces("application/json")
  public Response table(String usr) throws ClassNotFoundException, SQLException {

    if (ps.isExpectedPassword(usr.toCharArray())) {
      ArrayList<People> peoples = DB.select();
      Jsonb jsonb = JsonbBuilder.create();
      String peoplesJSON = jsonb.toJson(peoples);
      return Response.ok(peoplesJSON).build();
    } else
      return Response.ok("0").build();
  }

  @POST
  @Path("/autorization")
  @Consumes("application/json")
  @Produces("text/plain")
  public byte[] autorization(String userJSON) throws ClassNotFoundException, SQLException {
    String text = "nothash";
    byte[] notHash = text.getBytes();
    Jsonb jsonb = JsonbBuilder.create();
    user = jsonb.fromJson(userJSON, User.class);
    byte[] hash = ps.hash((user.password).toCharArray());
    if (Auth.auth(user.email, user.password)) {
      return hash;
    } else
      return notHash;
  }
}