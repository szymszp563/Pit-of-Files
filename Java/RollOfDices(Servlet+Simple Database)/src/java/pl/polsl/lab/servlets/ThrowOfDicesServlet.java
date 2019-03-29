package pl.polsl.lab.servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import pl.model.DiceException;
import pl.model.Model;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Main class of the servlet that is used as controller to operate at model
 * and compute results
 * in version 1.1 added database
 *
 * @author Szymon Szpakowski
 * @version 1.1
 */
public class ThrowOfDicesServlet extends HttpServlet {

    /**
     * model field of servlet to act on model
     */
    private Model model = new Model();

    /**
     * arguments passed in request
     */
    private String args[] = new String[3];

    /**
     * error field, if false lets logic work
     */
    boolean error = false;

    /**
     * checks if parameter is INTEGER
     *
     * @param s
     * @return
     */
    public static boolean isInteger(String s) {
        return isInteger(s, 10);
    }

    /**
     * checks if parameter is INTEGER
     *
     * @param s
     * @param radix
     * @return
     */
    public static boolean isInteger(String s, int radix) {
        if (s.isEmpty()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s.charAt(i) == '-') {
                if (s.length() == 1) {
                    return false;
                } else {
                    continue;
                }
            }
            if (Character.digit(s.charAt(i), radix) < 0) {
                return false;
            }
        }
        return true;
    }


    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param req servlet request
     * @param resp servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    public void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {
        
        HttpSession session = req.getSession(true);
        if ((Connection) session.getAttribute("connection") == null){ 
            Connection connection = null;
            try {
                Class.forName(this.getInitParameter("driver")); 
                connection = DriverManager.getConnection(
                        this.getInitParameter("url"), 
                        this.getInitParameter("user"), 
                        this.getInitParameter("password")
                );
            } catch (SQLException | ClassNotFoundException sqle) {
                resp.sendError(HttpServletResponse.SC_BAD_REQUEST, sqle.getMessage());
            }
            session.setAttribute("connection", connection); 
        }
        
        resp.setContentType("text/html; charset=ISO-8859-2");
        PrintWriter out = resp.getWriter();

       
        String dices = req.getParameter("dices");
        String walls = req.getParameter("walls");
        String mode = req.getParameter("mode");
        this.args[0] = dices;
        this.args[1] = walls;
        this.args[2] = mode;
      
        if (!this.error && (dices.length() == 0 || walls.length() == 0)) {
            resp.sendError(resp.SC_BAD_REQUEST, "You should give two parameters!");
        } else if (!isInteger(dices) || !isInteger(walls)) {
            resp.sendError(resp.SC_BAD_REQUEST, "No numbers of type int!!! First and second argument should be of type int!");
        } else {
            this.model.setNumOfDices(Integer.parseInt(dices));
            this.model.setNumOfWalls(Integer.parseInt(walls));
            this.model.setMode(mode);
            String result;
            try {
                    model.throwDices();
                    if (model.getMode().equals("max")) {
                        result = String.valueOf(model.getResult());
                        out.println("Max number of your rolls is: ");
                        out.println(result);
                        Cookie cookie = new Cookie("max", result);
                        resp.addCookie(cookie);
                        Connection connection = (Connection) session.getAttribute("connection"); //insert result to database
                        Statement statement = connection.createStatement();
                        statement.executeUpdate("INSERT INTO A.RESULTS VALUES ("
                        + "'max'," + " "
                        + "'" + result + "'"
                        + ")");
                    } else {
                        result = String.valueOf(model.getResult());
                        out.println("Sum of your rolls is: ");
                        out.println(result);
                        Cookie cookie = new Cookie("sum",result);
                        resp.addCookie(cookie);
                        Connection connection = (Connection) session.getAttribute("connection"); //insert result to database
                        Statement statement = connection.createStatement();
                        statement.executeUpdate("INSERT INTO A.RESULTS VALUES ("
                        + "'sum'," + " "
                        + "'" + result + "'"
                        + ")");
                    }
                } catch (DiceException ex) {
                    out.println(ex.getMessage());
                } catch (SQLException ex) {
                    resp.sendError(HttpServletResponse.SC_BAD_REQUEST, ex.getMessage());
                }
            
        }
    }
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param req servlet request
     * @param resp servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    public void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {
        doGet(req, resp);
    }
}
