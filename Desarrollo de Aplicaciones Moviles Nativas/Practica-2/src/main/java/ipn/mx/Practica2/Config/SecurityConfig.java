package ipn.mx.Practica2.Config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.web.SecurityFilterChain;

@Configuration
@EnableWebSecurity
public class SecurityConfig {

    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
            .authorizeHttpRequests(authorize -> authorize
                // Permitir acceso sin autenticación a /login y archivos estáticos (CSS, JS)
                .requestMatchers("/", "/login", "/register", "/css/**", "/js/**").permitAll()
                // Proteger la ruta /home, necesita autenticación
                .requestMatchers("/home").authenticated()
                // Requerir autenticación para cualquier otra ruta
                .anyRequest().authenticated()
            )
            .formLogin(form -> form
                .loginPage("/") // Página de inicio de sesión personalizada
                .defaultSuccessUrl("/home") // Redirigir a /home después de un inicio de sesión exitoso
                .permitAll() // Permitir a todos acceder a la página de inicio de sesión
            )
            .logout(logout -> logout.permitAll()); // Permitir a todos acceder al cierre de sesión

        return http.build();
    }
}