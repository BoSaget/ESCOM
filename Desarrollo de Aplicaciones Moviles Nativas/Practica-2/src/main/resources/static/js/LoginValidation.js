document.addEventListener("DOMContentLoaded", function () {
    const loginForm = document.getElementById("loginForm");

    loginForm.addEventListener("submit", function (event) {
        event.preventDefault(); // Evita el envío del formulario

        const username = document.getElementById("username").value.trim();
        const password = document.getElementById("password").value.trim();

        // Validación de campos
        if (username === "" || password === "") {
            Swal.fire({
                icon: 'error',
                title: 'Error',
                text: 'Por favor, completa todos los campos.',
                confirmButtonText: 'Aceptar'
            });
            return;
        }

        // Si la validación es exitosa, puedes enviar el formulario
        loginForm.submit();
    });
});
