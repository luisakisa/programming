package controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;


import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;


public class WebController extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        HttpSession session = request.getSession(true);
        Object login = request.getParameter("email");
        Object password = request.getParameter("password");
        try {
            if(firstConnection(request)){
            if(Auth.authorization((String) login, (String) password)) {
                String servletPath = request.getServletPath();
                session.setAttribute("log", login);
                session.setAttribute("pass", password);
                if (servletPath.equals("/login")) {
                        table(request);
                        request.getRequestDispatcher("/WEB-INF/views/table.jsp").forward(request, response);
                }

            }
                else request.getRequestDispatcher("/WEB-INF/views/loginError.jsp").forward(request, response);}
            String servletPath = request.getServletPath();
            if (servletPath.equals("/enter")) {
                String name = request.getParameter("name");
                String surname = request.getParameter("surname");
                String patronymic = request.getParameter("patronymic");
                People people = new People(0,name, surname, patronymic);
                DB.insert(people);
                table(request);
                request.getRequestDispatcher("/WEB-INF/views/table.jsp").forward(request, response);
            }
            if (servletPath.equals("/delete")) {
                int id = Integer.parseInt(request.getParameter("id"));
                DB.delete(id);
                table(request);
                request.getRequestDispatcher("/WEB-INF/views/table.jsp").forward(request, response);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String servletPath = req.getServletPath();
        if(!firstConnection(req)){
        if (servletPath.equals("/add")) {
            req.getRequestDispatcher("/WEB-INF/views/add.jsp").forward(req, resp);
        }}
    }
    private HttpServletRequest table(HttpServletRequest request){
        ArrayList<People> peoples = null;
        try {
            peoples = DB.select();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
        request.setAttribute("peoples", peoples);
        return request;

    }
    private boolean firstConnection(HttpServletRequest request) {
        HttpSession session = request.getSession(true);
        Object login = session.getAttribute("log");
        Object password = session.getAttribute("pass");

        if (login == null || password == null) {
            return true;
        }
        return false;
    }
}