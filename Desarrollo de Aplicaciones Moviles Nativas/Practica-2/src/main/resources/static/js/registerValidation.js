function validateRegisterForm() {
    const username = document.getElementById("username").value.trim();
    const firstName = document.getElementById("firstName").value.trim();
    const lastName = document.getElementById("lastName").value.trim();
    const email = document.getElementById("email").value.trim();
    const password = document.getElementById("password").value;
    const confirmPassword = document.getElementById("confirmPassword").value;

    // Validación de campos vacíos
    if (!username || !firstName || !lastName || !email || !password || !confirmPassword) {
        Swal.fire({
            icon: 'error',
            title: 'Error',
            text: 'Por favor, complete todos los campos.',
        });
        return false; // No envía el formulario
    }

    // Validación de formato de correo
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(email)) {
        Swal.fire({
            icon: 'error',
            title: 'Error',
            text: 'Por favor, ingrese un correo electrónico válido.',
        });
        return false; // No envía el formulario
    }

    // Validación de contraseñas
    if (password !== confirmPassword) {
        Swal.fire({
            icon: 'error',
            title: 'Error',
            text: 'Las contraseñas no coinciden.',
        });
        return false; // No envía el formulario
    }

    return true; // Envía el formulario si todas las validaciones pasan
}
