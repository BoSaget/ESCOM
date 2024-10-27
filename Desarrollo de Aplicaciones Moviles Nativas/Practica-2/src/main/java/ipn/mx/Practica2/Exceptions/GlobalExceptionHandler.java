package ipn.mx.Practica2.Exceptions;

import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;

@ControllerAdvice
public class GlobalExceptionHandler {

    @ExceptionHandler(Exception.class)
    public String handleException(Exception ex, Model model) {
        // Puedes agregar el error al modelo si quieres mostrarlo en la página de error
        model.addAttribute("errorMessage", ex.getMessage());
        return "index"; // Redirige al index en caso de cualquier excepción
    }
}
