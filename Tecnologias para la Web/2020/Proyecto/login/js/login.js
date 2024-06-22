document.addEventListener('DOMContentLoaded', (event) => {
    const socket = io();
  
    const form = document.getElementById('login');
    form.addEventListener('submit', (event) => {
      event.preventDefault();
  
      const formData = {
        email: form.email.value
      };
  
      socket.emit('formSubmit', formData);
      console.log('Datos del formulario enviados:', formData);
    });
  });
  