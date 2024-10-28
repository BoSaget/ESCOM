package ipn.mx.Practica2.Config; // Ajusta esto según donde lo hayas creado

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;

public class PasswordUtils {
    
    private static final BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();

    public static String encrypt(String password) {
        return passwordEncoder.encode(password);
    }

     // Método para verificar la contraseña
    public static boolean verify(String inputPassword, String storedPassword) {
        return passwordEncoder.matches(inputPassword, storedPassword);
    }
}
