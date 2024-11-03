// registerValidation.js

document.getElementById("registerForm").addEventListener("submit", function(event) {
    event.preventDefault(); // Prevenir el envío normal del formulario

    // Obtener los datos del formulario
    const formData = new FormData(this);

    // Validación de campos vacíos
    for (let [key, value] of formData.entries()) {
        if (!value.trim()) {
            Swal.fire({
                title: 'Error',
                text: `El campo ${key} no puede estar vacío.`,
                icon: 'error',
                confirmButtonText: 'Aceptar'
            });
            return;
        }
    }

    // Validación de correo electrónico con regex
    const email = formData.get("email");
    const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/; // Expresión regular para validar el formato de correo
    if (!emailPattern.test(email)) {
        Swal.fire({
            title: 'Error',
            text: 'Por favor, ingresa un correo electrónico válido.',
            icon: 'error',
            confirmButtonText: 'Aceptar'
        });
        return;
    }

    // Validación de confirmación de contraseña
    const password = formData.get("password");
    const confirmPassword = formData.get("confirmPassword");
    if (password !== confirmPassword) {
        Swal.fire({
            title: 'Error',
            text: 'Las contraseñas no coinciden.',
            icon: 'error',
            confirmButtonText: 'Aceptar'
        });
        return;
    }
    // Hacer la solicitud AJAX
    fetch('/register', {
        method: 'POST',
        body: formData,
        url: "/register"
    })
    .then(response => {
        if (response.ok) {
            return response.text(); // El registro fue exitoso
        } else {
            return response.text().then(text => { throw new Error(text); }); // Capturar el error
        }
    })
    .then(data => {
        // Si es exitoso, muestra un mensaje de éxito
        Swal.fire({
            title: 'Registro Exitoso',
            text: data,
            icon: 'success',
            confirmButtonText: 'Aceptar'
        }).then(() => {
            window.location.href = "/login"; // Redirigir a la página de inicio
        });
    })
    .catch(error => {
        // Si hay un error, muestra un mensaje de error
        Swal.fire({
            title: 'Error',
            text: error.message,
            icon: 'error',
            confirmButtonText: 'Aceptar'
        });
    });
});
