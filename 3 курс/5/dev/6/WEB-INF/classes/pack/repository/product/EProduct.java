package pack.repository.product;

import java.io.Serializable;
import jakarta.persistence.*;


@Entity
@Table(name = "\"products\"")
public class EProduct implements Serializable {

  @Id
  @Column(name = "\"id\"")
  private int id;
  @Column(name = "\"name\"")
  private String name;
  @Column(name = "\"parametrs\"")
  private String parametrs;
  @Column(name = "\"total\"")
  private int total;

    public void setTotal(int total) {
        this.total = total;
    }

    public int getTotal() {
        return total;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getParametrs() {
        return parametrs;
    }

    public void setParametrs(String parametrs) {
        this.parametrs = parametrs;
    }

    public void setId(int id) {
        this.id = id;
    }

}