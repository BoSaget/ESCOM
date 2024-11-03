package ipn.com.mx.Practica2.Controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import ipn.com.mx.Practica2.Models.RegisterModel;
import ipn.com.mx.Practica2.Repository.UserRepository;
import ipn.com.mx.Practica2.Services.PasswordEncoderService;

@RestController
@RequestMapping("/api") // Mapeo de la ruta base para el API
public class ApiRegisterController {

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private PasswordEncoderService passwordEncoderService;

    @PostMapping("/register")
    public ResponseEntity<String> registerUser(@RequestBody RegisterModel registerModel) {
        try {
            // Verificar si el usuario ya existe
            if (userRepository.existsByUsername(registerModel.getUsername())) {
                return ResponseEntity.status(HttpStatus.CONFLICT)
                        .body("El nombre de usuario ya está en uso.");
            }

            if (userRepository.existsByEmail(registerModel.getEmail())) {
                return ResponseEntity.status(HttpStatus.CONFLICT)
                        .body("El correo ya está en uso.");
            }

            System.out.println(registerModel); // Muestra los valores recibidos

            // Encriptar la contraseña antes de guardarla
            String encryptedPassword = passwordEncoderService.encode(registerModel.getPassword());
            registerModel.setPassword(encryptedPassword);

            // Guardar el usuario en la base de datos
            userRepository.save(registerModel);

            return ResponseEntity.ok("Registro exitoso. Ya puede iniciar sesión.");

        } catch (Exception e) {
            // Manejo de cualquier excepción no prevista
            e.printStackTrace();
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR)
                    .body("Ha ocurrido un error en el servidor.");
        }
    }
}
