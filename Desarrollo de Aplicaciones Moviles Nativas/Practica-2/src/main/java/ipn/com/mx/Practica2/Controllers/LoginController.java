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
    public String showLogingForm() {
        return "login"; // Devuelve el nombre del archivo HTML que contiene el formulario
    }

    @PostMapping
    public ResponseEntity <String> loginUser(
            @RequestParam String identifier, 
            @RequestParam String password) {

        try {
            
            // Verificar si el usuario ya existe
            if (!userRepository.existsByUsername(identifier) && !userRepository.existsByEmail(identifier)) {
                return ResponseEntity.status(HttpStatus.CONFLICT)
                            .body("Usuario incorrecto");
            }
            
            Authentication auth = authenticationManager.authenticate(
                new UsernamePasswordAuthenticationToken(identifier, password)
            );
            SecurityContextHolder.getContext().setAuthentication(auth);
            
            return ResponseEntity.ok("Ventarrones");
            
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR)
            .body("Contraseña incorrecta");
        }
    }

    /*
    @GetMapping("/logout")
    public String logoutPage(HttpServletRequest request, HttpServletResponse response) {
        Authentication auth = SecurityContextHolder.getContext().getAuthentication();
        if (auth != null) {
            new SecurityContextLogoutHandler().logout(request, response, auth);
        }
        return "redirect:/login?logout=true";
    }
    */
}
