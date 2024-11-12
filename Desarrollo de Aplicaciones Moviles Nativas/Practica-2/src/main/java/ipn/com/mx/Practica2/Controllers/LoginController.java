package ipn.com.mx.Practica2.Controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
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
    private AuthenticationManager authenticationManager;

    @Autowired
    private UserRepository userRepository;

    @GetMapping
    public String showLoginForm() {
        return "login"; // Devuelve el nombre del archivo HTML que contiene el formulario
    }

    @PostMapping
    public ResponseEntity<String> loginUser(
            @RequestParam String identifier, 
            @RequestParam String password) {

        try {

            // Buscar usuario por nombre de usuario o correo
            if (!userRepository.existsByEmail(identifier) && !userRepository.existsByUsername(identifier)) {
                return ResponseEntity.status(HttpStatus.CONFLICT)
                                     .body("Usuario incorrecto");
            }

            Authentication auth = authenticationManager.authenticate(
                new UsernamePasswordAuthenticationToken(identifier, password)
            );
            SecurityContextHolder.getContext().setAuthentication(auth);

            return ResponseEntity.ok("Bienvenido, " + auth.getName() + "!");
            
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                                 .body("Credenciales incorrectas");
        }
    }
    
    @GetMapping("/logout")
    public String logout() {
        SecurityContextHolder.clearContext();
        return "redirect:/login?logout=true";
    }
}
