package ipn.mx.Practica2.Controllers;

import org.springframework.security.core.Authentication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import ipn.mx.Practica2.Config.PasswordUtils;
import ipn.mx.Practica2.Models.UserModel;
import ipn.mx.Practica2.Repository.UserRepository;

@Controller
public class LoginController {

    private final UserRepository userRepository;

    // Constructor para inyectar el UserRepository
    public LoginController(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @GetMapping("/login")
    public String showLoginForm() {
        return "login"; // Retorna la vista de inicio de sesión
    }

    @PostMapping("/login")
    public String login(@RequestParam String username, @RequestParam String password, Authentication authentication) {
        // Buscar el usuario en la base de datos
        UserModel foundUser = userRepository.findByUsuario(username); // Cambia `user.getUsuario()` por `username`

        // Mostrar valores para depuración
        System.out.println("Intertado: " + username);
        System.out.println("Contraseña: " + password);

        if (foundUser != null && PasswordUtils.verify(password, foundUser.getContraseña())) {
            // Si las credenciales son correctas, redirigir a /home
            return "redirect:/home"; // Redirige a la página de inicio
        } else {
            // Si las credenciales son incorrectas, redirigir de nuevo al login con un mensaje de error
            return "redirect:/login?error"; // Redirige al login con un parámetro de error
        }
    }
}
