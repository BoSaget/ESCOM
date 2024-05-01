/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package ServletRegistro;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Registro extends HttpServlet{
    /**
    *Manu¿ipula las posibles peticiones enviadas por el cliente:
    *Utilizando el atributo meyhod=get o method=post.
    */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
            {
                response.setContentType("text/html;charset=UTF-8");
                try (PrintWriter out = response.getWriter())
                {
                    //Respondemos peticiones
                    out.println("<!DOCTYPE html>");
                    out.println("<html>");
                    out.println("<head>");
                    out.println("<title>Servlet Registro</title>");
                    out.println("</head>");
                    out.println("<body>");
                    out.println("<h1>Registro Exitoso!!</h1>");
                    out.println("</body>");
                    out.println("</html>");
                }
            } 
    /**
     * Metodo que se encarga de la peticion GET
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException 
            {
                processRequest(request, response);
            }

    /**
     * Metodo que se encarga de la peticion POST
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException 
            {
                processRequest(request, response);
            }

    /**
     * Devuelve una descripción breve del servlet.
     */
    @Override
    public String getServletInfo() 
    {
        return "Servlet Registro";
    }// </editor-fold>
}
