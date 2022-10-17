package objects;

import java.io.Serializable;

public class People implements Serializable {

    private static final long serialVersionUID = 1L;

    private int id;
    private String name;
    private String surname;
    private String patronymic;

    public People() {
    };

    public People(int id, String name, String surname, String patronymic) {

        this.id = id;
        this.name = name;
        this.surname = surname;
        this.patronymic = patronymic;
    }

    public void setPatronymic(String patronymic) {
        this.patronymic = patronymic;
    }

    public String getPatronymic() {
        return patronymic;
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

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setId(int id) {
        this.id = id;
    }

}