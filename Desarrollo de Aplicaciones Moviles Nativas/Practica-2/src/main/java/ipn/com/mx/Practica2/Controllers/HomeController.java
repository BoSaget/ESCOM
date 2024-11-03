package ipn.com.mx.Practica2.Controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class HomeController {

    @GetMapping("/home")
    public String home() {
        return "home"; // Devuelve el nombre de la vista correspondiente a /home
    }
}
