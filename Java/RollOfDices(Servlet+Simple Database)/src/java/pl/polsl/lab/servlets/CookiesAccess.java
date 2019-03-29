/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.lab.servlets;

import java.io.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.http.*;

/**
 * Servlet presenting the use of cookies
 * in version 1.1 added database
 * @author Szymon Szpakowski
 * @version 1.1
 */
public class CookiesAccess extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request
     * @param response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    public void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        PrintWriter out = response.getWriter();
        response.setContentType("text/plain; charset=ISO-8859-2");
        
        out.println("Last results:");
        
        Cookie[] cookies = request.getCookies();
        for (Cookie cookie : cookies) {
            if (cookie.getName().equals("max")) 
                out.println(cookie.getName() + ": " + cookie.getValue());
            else if (cookie.getName().equals("sum"))
                out.println(cookie.getName() + ": " + cookie.getValue());
        }
        
         HttpSession session = request.getSession(true);
        Connection connection = null;
        if ((Connection) session.getAttribute("connection") == null) {
            try {
                Class.forName(this.getInitParameter("driver"));
                connection = DriverManager.getConnection(
                        this.getInitParameter("url"), 
                        this.getInitParameter("user"), 
                        this.getInitParameter("password")
                );
            } catch (SQLException | ClassNotFoundException sqle) {
                response.sendError(HttpServletResponse.SC_BAD_REQUEST, sqle.getMessage());
            }
            session.setAttribute("connection", connection);
        }
        connection = (Connection) session.getAttribute("connection");
        out.println("\nResults from database:");
        
        try {
                Statement statement = connection.createStatement();
                ResultSet rs = statement.executeQuery("SELECT * FROM A.RESULTS");

                if (rs.next() == false) {
                    out.println("No results");
                } else {
                    out.println(rs.getString("mode") + " " + rs.getString("result"));
                }

                while (rs.next()) {
                    out.println(rs.getString("mode") + " " + rs.getString("result"));
                }
            } catch (SQLException sqle) {
                response.sendError(HttpServletResponse.SC_BAD_REQUEST, sqle.getMessage());
            }

        
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
