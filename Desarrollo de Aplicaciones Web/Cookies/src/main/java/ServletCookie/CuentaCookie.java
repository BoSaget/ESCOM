/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package ServletCookie;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class CuentaCookie extends HttpServlet {

    /**
     * Manipular las posibles peticiones enviadas por el cliente
     * utilizando el atributo method=get o method=post
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException 
        {
            response.setContentType("text/html; charset=UTF-8");
            try (PrintWriter out = response.getWriter() )
            {
                /*Obtenemos el valor actual de las cookie CuentaCoookie
                iterando entre las cookies que se reciban*/
                String nCuenta = null;
                Cookie[] cookies = request.getCookies();

                if(cookies != null)
                {
                    for (int i = 0; i < cookies.length; i++)
                    {
                        if (cookies[i].getName().equals("Cuenta.Cookie"))
                        {
                            nCuenta = cookies[i].getValue();
                            break;
                        }
                    }
                }

                /*Incrementar el contador para esta pagina
                El valior es guardado en la cookie ocn el nombre de "Cuenta.Cookie"*/

                Integer conteo = null;

                if(nCuenta == null)
                {
                    conteo = new Integer(1);
                }

                else
                {
                    conteo = new Integer(Integer.parseInt(nCuenta) + 1);
                }

                Cookie newCookie = new Cookie("Cuenta.Cookie", conteo.toString());
                response.addCookie(newCookie);
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                out.println("<head>");
                out.println("<title>Servlet Cuenta Cookies</title>");
                out.println("</head>");
                out.println("<body>");
                out.println("<h1>Bienvenido Tejeda Leon</h1>");
                out.println("<h2>Has visitado esta pagina " + conteo.toString() + ((conteo.intValue() == 1)? " vez" : " veces.") + "</h2>");
                out.println("</body>");
                out.println("</html>");
            }
        }
        
    

    /*Metodo que se encargar de l apeticion POST
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException 
        {
            processRequest(request, response);
        }
}
