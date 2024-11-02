package ipn.mx.Practica2.Controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import ipn.mx.Practica2.Config.PasswordUtils;
import ipn.mx.Practica2.Models.UserModel;
import ipn.mx.Practica2.Repository.UserRepository;

@RestController
@RequestMapping("/api/users")
public class UserController {

    @Autowired
    private UserRepository userRepository;

    // Endpoint para crear un nuevo usuario
    @PostMapping("/add")
    public ResponseEntity<UserModel> createUser(@RequestBody UserModel user) {
        try {
            // Encriptar la contraseña antes de guardarla
            String encryptedPassword = PasswordUtils.encrypt(user.getContraseña());
            user.setContraseña(encryptedPassword);

            // Muestra los valores recibidos
            //System.out.println(user);
            
            UserModel newUser = userRepository.save(user);
            return new ResponseEntity<>(newUser, HttpStatus.CREATED);
            
        } catch (Exception e) {
            System.err.println("Error al guardar el usuario: " + e.getMessage());
            return new ResponseEntity<>(null, HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }
}

