package ipn.com.mx.Practica2.Repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import ipn.com.mx.Practica2.Models.RegisterModel;

@Repository
public interface UserRepository extends JpaRepository<RegisterModel, Long> {
    
    // Método para encontrar un usuario por nombre de usuario
    RegisterModel findByUsername(String username);
    
    // Método para encontrar un usuario por correo electrónico
    RegisterModel findByEmail(String email);
}
