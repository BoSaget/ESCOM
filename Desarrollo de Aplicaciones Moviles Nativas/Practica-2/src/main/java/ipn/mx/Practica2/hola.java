package ipn.mx.Practica2;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class hola {

    @GetMapping("/hola")
    public String sayHello(Model model) {
        model.addAttribute("mensaje", "¡Hola desde tu aplicación Spring Boot!");
        return "hola";
    }
}
