document.addEventListener('DOMContentLoaded', function() {
  document.getElementById('login-button').addEventListener('click', function(e) {
    
    e.preventDefault();
    var formularioIngreso = document.getElementById('login');
    var datosIngreso = new FormData(formularioIngreso);

    //Revisa si ambos campos se encuentran vacios
    if(datosIngreso.get('user-login') == '' && datosIngreso.get('user-login-pass')=='')
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'Ambos campos se encuentran vacios en login',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }

    //Validation de si el usuario en registro está vacio
    else if(datosIngreso.get('user-login') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingresa un usuario en login',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    //Validación para ver si el campo de contraseña está vacio
    else if(datosIngreso.get('user-login-pass') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingresa una contraseña en login',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

  });
});

document.addEventListener('DOMContentLoaded', function() {
  document.getElementById('sign-button').addEventListener('click', function(e) {
    
    e.preventDefault();
    var formularioRegistro = document.getElementById('registro');
    var datosRegistro = new FormData(formularioRegistro);
    const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;

    //Revisa si ambos campos se encuentran vacios
    if(datosRegistro.get('user-sign') == '' && datosRegistro.get('user-sign-pass') == '')
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'Ambos campos se encuentran vacios en registro',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }

    //Validation de si el usuario en registro está vacio
    else if(datosRegistro.get('user-sign') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingresa un usuario en registro',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(emailRegex.test(datosRegistro.get('user-sign')) == false)
    {
      Swal.fire({
        title: 'Error!',
        text: 'Dirección de correo no valida',
        icon: 'error',
        confirmButtonText: 'Aceptar'
      });
    }

    //Validación para ver si el campo de contraseña está vacio
    else if(datosRegistro.get('user-sign-pass') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingresa una contraseña en registro',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }
  });
});