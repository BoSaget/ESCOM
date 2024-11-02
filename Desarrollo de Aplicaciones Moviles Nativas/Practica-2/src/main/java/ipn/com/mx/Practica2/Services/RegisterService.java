package ipn.com.mx.Practica2.Services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ipn.com.mx.Practica2.Models.RegisterModel;
import ipn.com.mx.Practica2.Repository.UserRepository;

@Service
public class RegisterService {

    @Autowired
    private UserRepository userRepository;

    public void saveUser(RegisterModel registerModel) {
        // Aquí puedes agregar lógica adicional, como validar el usuario antes de guardarlo
        userRepository.save(registerModel);
    }
}
