package pack.model.api.dto;


public class Product {


    private int id;
    private String name;
    private String parametrs;
    private int total;

    public Product() {
    };

    public Product(int id, String name, String parametrs, int total) {

        this.id = id;
        this.name = name;
        this.parametrs = parametrs;
        this.total = total;
    }

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