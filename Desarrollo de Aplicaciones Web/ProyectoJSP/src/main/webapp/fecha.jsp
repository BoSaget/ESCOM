<%-- 
    Document   : fecha
    Created on : 2/05/2022, 01:04:03 AM
    Author     : LeonT
--%>
<!-- Archivo: fecha.jsp-->
<%@ page import = "java.util.Date"%>
<%@ page import = "java.text.SimpleDateFormat"%>
<%= (new SimpleDateFormat ("E dd/MM/YYYY - hh:mm:ss a zzz").format (new Date()))%>
