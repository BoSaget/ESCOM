<%-- 
    Document   : mostrarFecha
    Created on : 2/05/2022, 01:00:52 AM
    Author     : LeonT
--%>
<!-- archivo: mostarFecha.jsp-->
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>LLamando archivos con JSP</title>
    </head>
    <body style = " background-color: #FBEFF4">
        <h1>Le fecha y hora actuales son:</h1>
        
        <h2><%@ include file = "fecha.jsp"%></h2>
        <h2><%@ include file = "LlamadaJSP.html"%></h2>
        <h2><%@ include file = "texto.txt"%></h2>
        
    </body>
</html>
