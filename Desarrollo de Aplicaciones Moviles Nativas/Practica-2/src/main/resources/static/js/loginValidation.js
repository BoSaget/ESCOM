document.getElementById("loginForm").addEventListener("submit", function(event) {
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

    // Hacer la solicitud AJAX
    fetch('/login', {
        method: 'POST',
        body: formData,
        url: "/login"
    })
    .then(response => {
        if (response.ok) {
            return response.text(); // El loggeo fue exitoso
        } else {
            return response.text().then(text => { throw new Error(text); }); // Capturar el error
        }
    })
    .then(data => {
        // Si es exitoso, muestra un mensaje de éxito
        Swal.fire({
            title: 'Bienvenido',
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
