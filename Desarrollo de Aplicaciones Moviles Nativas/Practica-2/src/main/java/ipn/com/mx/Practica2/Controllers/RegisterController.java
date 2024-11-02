package ipn.com.mx.Practica2.Controllers;

import org.springframework.beans.factory.annotation.Autowired;
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

    // Manejar la solicitud GET para mostrar el formulario de registro
    @GetMapping
    public String showRegistrationForm() {
        return "register"; // Devuelve el nombre del archivo HTML que contiene el formulario
    }

    // Manejar la solicitud POST para procesar el registro
    @PostMapping
    public String registerUser(@RequestParam String username, 
                                @RequestParam String firstName, 
                                @RequestParam String lastName, 
                                @RequestParam String email, 
                                @RequestParam String password) {
        
        RegisterModel registerModel = new RegisterModel();
        registerModel.setUsername(username);
        registerModel.setFirstName(firstName);
        registerModel.setLastName(lastName);
        registerModel.setEmail(email);
        
        // Encriptar la contraseña antes de guardarla
        String encryptedPassword = passwordEncoderService.encode(password);
        registerModel.setPassword(encryptedPassword); 

        userRepository.save(registerModel);

        return "redirect:/"; // Redirigir a la página de inicio o a otra página
    }
}
