package ipn.com.mx.Practica2.Services;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

@Service
public class PasswordEncoderService {
    
    private final BCryptPasswordEncoder passwordEncoder;

    public PasswordEncoderService() {
        this.passwordEncoder = new BCryptPasswordEncoder();
    }

    // Método para encriptar la contraseña
    public String encode(String rawPassword) {
        return passwordEncoder.encode(rawPassword);
    }
}
