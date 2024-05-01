/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.Enumeration;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author LeonT
 */
public class Sesion extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try ( PrintWriter out = response.getWriter()) {
            //Obtenemos la sesión actual o creamos una de ser necesario.
            HttpSession sesion = request.getSession(true);
            //Datos de la Sesión
            String idSesion = sesion.getId();
            long fechaCreacion = sesion.getCreationTime();
            long fechaUltimoAcceso = sesion.getLastAccessedTime();
            //Incrementa el contador de la sesion del cliente "cuenta.sesion"
            Integer cuenta = (Integer)sesion.getAttribute("cuenta.sesion");
            if (cuenta == null)
            {
                cuenta = 1;
            }
            else
            {
                cuenta = cuenta + 1;
            }
            sesion.setAttribute("cuenta.sesion", cuenta);
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet de Seguimiento de Sesione </title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Leon Francisco Tejeda Moyao has Visitado esta página " + cuenta + ((cuenta == 1)? " vez" : " veces.") + "</h1>");
            out.println("<h2>Datos de la Sesión actual: </h2>");
            out.println("<h3>Id de la Sesión" + idSesion + "</h2>");
            out.println("<h3>Fecha de Creación" + (new Date(fechaCreacion)) + "</h2>");
            out.println("<h3>Se accedio por ultima vez: " + (new Date(fechaUltimoAcceso)) + "</h3>");
            out.println("<h2>Atributos: </h2>");
            Enumeration nombres = sesion.getAttributeNames();
            while (nombres.hasMoreElements())
            {
                String param = (String)nombres.nextElement();
                out.println("<h3>" + param + ": " + sesion.getAttribute(param) + "</h3>");
            }
            out.println("</body>");
            out.println("</html>");
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
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
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
        return "Servlet Seguimiento Sesión";
    }// </editor-fold>

}
