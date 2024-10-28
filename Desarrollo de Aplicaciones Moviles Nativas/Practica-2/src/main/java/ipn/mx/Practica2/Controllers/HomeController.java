package ipn.mx.Practica2.Controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class HomeController {

    @GetMapping("/")
    public String index() {
        return "index"; // Renderiza la vista index.html
    }

    @GetMapping("/home")
    public String home() {
        return "home"; // Asegúrate de que tienes un archivo home.html en src/main/resources/templates
    }
}
