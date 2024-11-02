package ipn.com.mx.Practica2.Controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class RegisterController {

    @GetMapping("/register")
    public String showRegistrationForm() {
        return "register"; // Devuelve la vista register.html
    }

    @PostMapping("/register")
    public String registerUser(
        @RequestParam String username,
        @RequestParam String firstName,
        @RequestParam String lastName,
        @RequestParam String email,
        @RequestParam String password,
        @RequestParam String confirmPassword) {
        
        // Lógica para procesar el registro (validaciones, guardar en la base de datos, etc.)
        
        // Aquí puedes implementar la lógica para manejar la creación del usuario
        // Validar que la contraseña y la confirmación de contraseña coincidan, etc.

        return "redirect:/"; // Redirige a la página de inicio después del registro
    }
}
