package ipn.mx.Practica2.Controllers;

import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import ipn.mx.Practica2.Models.UserModel; // Asegúrate de que esta clase esté bien definida

@Controller
public class HomeController {

    @GetMapping("/home")
    public String home(@AuthenticationPrincipal UserModel user, Model model) {
        // Puedes agregar información del usuario al modelo si lo deseas
        model.addAttribute("username", user.getUsuario()); // Suponiendo que 'usuario' es el nombre de usuario
        return "home"; // Retorna la vista de inicio
    }
}
