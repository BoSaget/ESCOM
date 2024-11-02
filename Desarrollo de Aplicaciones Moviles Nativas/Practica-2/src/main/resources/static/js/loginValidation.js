function validateLoginForm() {
    const identifier = document.getElementById("identifier").value.trim();
    const password = document.getElementById("password").value;

    // Validación de campos vacíos
    if (!identifier || !password) {
        Swal.fire({
            icon: 'error',
            title: 'Error',
            text: 'Por favor, complete todos los campos.',
        });
        return false; // No envía el formulario
    }

    return true; // Envía el formulario si todas las validaciones pasan
}
