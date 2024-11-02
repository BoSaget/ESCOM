package ipn.mx.Practica2.Repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import ipn.mx.Practica2.Models.UserModel;

@Repository
public interface UserRepository extends JpaRepository<UserModel, Long> {
    
    // Método para encontrar un usuario por su nombre de usuario
    UserModel findByUsuario(String usuario);
}
