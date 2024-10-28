package ipn.mx.Practica2.Repository;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import ipn.mx.Practica2.Models.UserModel;

@Repository
public interface UserRepository extends JpaRepository<UserModel, Long> {
    // Puedes añadir métodos de búsqueda aquí si es necesario
}