document.getElementById("loginForm").addEventListener("submit", function(event) {
    event.preventDefault(); // Evitar el envío del formulario

    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;

    if (username === "" || password === "") {
        Swal.fire({
            title: 'Campos vacíos',
            text: 'Por favor, completa todos los campos antes de iniciar sesión.',
            icon: 'warning',
            confirmButtonText: 'Aceptar'
        });
        return; // Salir si hay campos vacíos
    }

    // Hacer una solicitud de inicio de sesión
    fetch('/api/users/login', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ usuario: username, contraseña: password })
    })
    .then(response => {
        if (response.ok) {
            // Redirigir a la pantalla de inicio
            window.location.href = '/home'; // Asegúrate de que esta ruta esté configurada en tu aplicación
        } else {
            return response.text().then(text => {
                Swal.fire({
                    title: 'Error',
                    text: text, // Mensaje de error de la respuesta
                    icon: 'error',
                    confirmButtonText: 'Aceptar'
                });
            });
        }
    })
    .catch(error => {
        console.error('Error:', error);
        Swal.fire({
            title: 'Error',
            text: 'Ocurrió un error en el servidor.',
            icon: 'error',
            confirmButtonText: 'Aceptar'
        });
    });
});
