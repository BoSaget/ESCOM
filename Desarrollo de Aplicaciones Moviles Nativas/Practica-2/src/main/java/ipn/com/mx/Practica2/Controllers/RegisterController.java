package ipn.com.mx.Practica2.Controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import ipn.com.mx.Practica2.Models.RegisterModel;
import ipn.com.mx.Practica2.Repository.UserRepository;
import ipn.com.mx.Practica2.Services.PasswordEncoderService;

@Controller
@RequestMapping("/register")
public class RegisterController {

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private PasswordEncoderService passwordEncoderService;

    @GetMapping
    public String showRegistrationForm() {
        return "register"; // Devuelve el nombre del archivo HTML que contiene el formulario
    }

    @PostMapping
    public ResponseEntity<String> registerUser(
            @RequestParam String username, 
            @RequestParam String firstName, 
            @RequestParam String lastName, 
            @RequestParam String email, 
            @RequestParam String password,
            @RequestParam String confirmPassword) {

        try {
            // Verificar si el usuario ya existe
            if (userRepository.existsByUsername(username)) {
                return ResponseEntity.status(HttpStatus.CONFLICT)
                        .body("El nombre de usuario ya está en uso.");
            }

            if (userRepository.existsByEmail(email)) {
                return ResponseEntity.status(HttpStatus.CONFLICT)
                        .body("El correo ya está en uso.");
            }

            // Crear una instancia de RegisterModel y configurar sus atributos
            RegisterModel registerModel = new RegisterModel();
            registerModel.setUsername(username);
            registerModel.setFirstName(firstName);
            registerModel.setLastName(lastName);
            registerModel.setEmail(email);

            // Encriptar la contraseña antes de guardarla
            String encryptedPassword = passwordEncoderService.encode(password);
            registerModel.setPassword(encryptedPassword);

            // Guardar el usuario en la base de datos
            userRepository.save(registerModel);

            return ResponseEntity.ok("Ya puede iniciar sesion");

        } catch (Exception e) {
            // Manejo de cualquier excepción no prevista
            e.printStackTrace();
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR)
                    .body("Ha ocurrido un error en el servidor");
        }
    }
}
