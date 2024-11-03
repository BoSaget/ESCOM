package ipn.com.mx.Practica2.Config;

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
            .authorizeHttpRequests(authz -> authz
                .requestMatchers("/", "/register", "/login", "/css/**", "/js/**", "/api/register").permitAll() // Permitir el acceso a la ruta /api/register
                .anyRequest().authenticated() // Todas las demás rutas requieren autenticación
            )
            .formLogin(form -> form
                .loginPage("/") // Página de inicio de sesión personalizada
                .permitAll() // Permitir que todos accedan a la página de inicio de sesión
            )
            .logout(logout -> logout
                .permitAll() // Permitir que todos cierren sesión
            );

        return http.build();
    }
}
