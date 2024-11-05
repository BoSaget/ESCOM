package ipn.com.mx.Practica2.Controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.AuthenticationException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import ipn.com.mx.Practica2.Repository.UserRepository;

@Controller
@RequestMapping("/login")
public class LoginController {

    @Autowired
    private UserRepository userRepository;

    @GetMapping
    public String showLoginForm() {
        return "login"; // Devuelve el nombre del archivo HTML que contiene el formulario de inicio de sesión
    }

    @PostMapping
    public ResponseEntity<String> loginUser(
            @RequestParam String identifier, // Puede ser el nombre de usuario o correo
            @RequestParam String password) {
        try {
            // Determinar si el identificador es un correo o nombre de usuario
            String username;
            if (userRepository.existsByEmail(identifier)) {
                username = userRepository.findByEmail(identifier).getUsername();
            } else if (userRepository.existsByUsername(identifier)) {
                username = identifier;
            } else {
                return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                        .body("Credenciales inválidas. Usuario o correo no encontrado.");
            }

            return ResponseEntity.ok("Inicio de sesión exitoso. Redirigiendo a /home...");

        } catch (AuthenticationException e) {
            e.printStackTrace();
            return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                    .body("Error de autenticación. Verifica tus credenciales.");
        } catch (Exception e) {
            e.printStackTrace();
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR)
                    .body("Ha ocurrido un error en el servidor.");
        }
    }
}
