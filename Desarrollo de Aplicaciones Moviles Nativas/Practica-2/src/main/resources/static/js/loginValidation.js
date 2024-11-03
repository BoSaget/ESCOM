document.addEventListener("DOMContentLoaded", function () {
    const loginForm = document.getElementById("loginForm");

    loginForm.addEventListener("submit", function (event) {
        event.preventDefault(); // Prevenir el envío normal del formulario

        // Obtener los datos del formulario
        const formData = new FormData(this);
        const identifier = formData.get("identifier").trim();
        const password = formData.get("password").trim();

        // Validar que los campos no estén vacíos
        if (!identifier || !password) {
            Swal.fire({
                title: 'Error',
                text: 'Por favor, completa todos los campos.',
                icon: 'error',
                confirmButtonText: 'Aceptar'
            });
            return; // Salir de la función si hay campos vacíos
        }

        // Hacer la solicitud AJAX
        fetch('/login', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: new URLSearchParams({
                identifier: identifier,
                password: password
            })
        })
        .then(response => {
            if (response.ok) {
                return response.text(); // Éxito en la autenticación
            } else {
                return response.text().then(text => { throw new Error(text); }); // Capturar el error
            }
        })
        .then(data => {
            // Si es exitoso, muestra un mensaje de éxito y redirige
            Swal.fire({
                title: 'Éxito',
                text: data,
                icon: 'success',
                confirmButtonText: 'Aceptar'
            }).then(() => {
                window.location.href = "/home"; // Redirigir a la página de inicio
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
});
