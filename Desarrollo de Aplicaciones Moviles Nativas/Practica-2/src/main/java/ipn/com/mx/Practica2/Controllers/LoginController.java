package ipn.com.mx.Practica2.Controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class LoginController {

    @GetMapping("/login")
    public String showLoginForm() {
        return "login"; // Retorna la vista login.html
    }

    @PostMapping("/login")
    public String processLogin(
            @RequestParam String identifier, 
            @RequestParam String password, 
            Model model) {
        
        // Aquí iría la lógica para autenticar al usuario.
        // Por simplicidad, asumimos que la autenticación es exitosa si 
        // el nombre de usuario o correo y la contraseña no están vacíos.

        if (identifier.isEmpty() || password.isEmpty()) {
            model.addAttribute("error", "Por favor, complete todos los campos.");
            return "login"; // Retorna a la vista de login si hay un error
        }

        // Lógica de autenticación (puedes reemplazar esto con tu lógica real)
        // if (authService.authenticate(identifier, password)) {
        //     return "redirect:/home"; // Redirige a la página de inicio después del login exitoso
        // }

        // Si la autenticación falla, puedes agregar un mensaje de error.
        model.addAttribute("error", "Credenciales inválidas. Intenta de nuevo.");
        return "login"; // Retorna a la vista de login en caso de error
    }
}
