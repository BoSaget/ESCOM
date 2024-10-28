// Obtener el formulario y añadir el evento de submit
document.getElementById("loginForm").addEventListener("submit", function(event) {
    // Obtener los valores de los campos
    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;

    // Verificar si algún campo está vacío
    if (username === "" || password === "") {
        event.preventDefault(); // Evitar que se envíe el formulario

        // Mostrar SweetAlert
        Swal.fire({
            title: 'Campos vacíos',
            text: 'Por favor, completa todos los campos antes de iniciar sesión.',
            icon: 'warning',
            confirmButtonText: 'Aceptar'
        });
    }
});
