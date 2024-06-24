//Para ingresar
document.addEventListener('DOMContentLoaded', function() {
  document.getElementById('login-button').addEventListener('click', function(e) {
    
    e.preventDefault();
    var formularioIngreso = document.getElementById('login');
    var datosIngreso = new FormData(formularioIngreso);

    //console.log(datosIngreso.get('user-login'))
    //console.log(datosIngreso.get('user-login-pass'))

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

    else{
      // Datos que quieres enviar al archivo PHP
      const ingreso = {
        user: datosIngreso.get('user-login'),
        pass: datosIngreso.get('user-login-pass')
      };

      // Función para enviar los datos
      async function enviarDatos() 
      {
        try 
        {
          const response = await fetch('./login.php', {
            method: 'POST', // Método de la solicitud
            headers: {
              'Content-Type': 'application/json' // Tipo de contenido
            },
            body: JSON.stringify(ingreso) // Convertir los datos a una cadena JSON
        });

        // Convertir la respuesta a JSON
        const resultado = await response.json();
          
        if (resultado.status === 'success') 
        {
          if(resultado.empleado == 1)
          {
            if(resultado.rol == 'Cocina')
            {
              window.location.href = "./../cocina/index.php";
            }
            else
            {
              window.location.href = "./../admin/index.php";
            }
          }

          else
          {
            window.location.href = "./../usuario/index.php";
          }
        }

        else if (resultado.status === 'not found') 
        {
          Swal.fire({
            title: '¡Atención!',
            text: resultado.message,
            icon: 'error',
            confirmButtonText: 'Aceptar'
          });
        }
    
        else 
        {
          Swal.fire({
            title: '¡Error!',
            text: resultado.message,
            icon: 'error',
            confirmButtonText: 'Aceptar'
          });
        }
    
      } 
      catch (error) 
      {
          console.error('Error de red:', error);
          Swal.fire({
            title: '¡Error de Red!',
            icon: 'error',
            confirmButtonText: 'Aceptar'
          });
      }
    }

      // Llamar a la función para enviar los datos
      enviarDatos();
    }
  });
});

//Para el registro
document.addEventListener('DOMContentLoaded', function() {
  document.getElementById('sign-button').addEventListener('click', function(e) {
    
    e.preventDefault();
    var formularioRegistro = document.getElementById('registro');
    var datosRegistro = new FormData(formularioRegistro);
    const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    const palominoEmailRegex = /^[a-zA-Z0-9._%+-]+@pl\.com$/;

    //console.log(datosRegistro.get('user-sign'))
    //console.log(datosRegistro.get('user-sign-pass'))

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

    //Checa si es una dirección de correo valida
    else if(emailRegex.test(datosRegistro.get('user-sign')) == false)
    {
      Swal.fire({
        title: '¡Error!',
        text: 'Dirección de correo no valida',
        icon: 'error',
        confirmButtonText: 'Aceptar'
      });
    }

    //Checa si no es una dirección de correo de la empresa
    else if(palominoEmailRegex.test(datosRegistro.get('user-sign')) == true)
      {
        Swal.fire({
          title: '¡Error!',
          text: 'No se puede usar la terminación @pl.com, es de la empresa',
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

    else
    {
      // Datos que quieres enviar al archivo PHP
      const registro = {
        email: datosRegistro.get('user-sign'),
        pass: datosRegistro.get('user-sign-pass')
      };

      // Función para enviar los datos
      async function enviarDatos() 
      {
        try 
        {
          const response = await fetch('./sign.php', {
            method: 'POST', // Método de la solicitud
            headers: {
              'Content-Type': 'application/json' // Tipo de contenido
            },
            body: JSON.stringify(registro) // Convertir los datos a una cadena JSON
          });

          // Convertir la respuesta a JSON
          const resultado = await response.json();
        
          if (resultado.status === 'success') 
          {
            //console.log('Datos enviados exitosamente:', resultado.data);
            Swal.fire({
              title: '¡Registrado!',
              text: 'Favor de ingresar tus datos en la sección de registro',
              icon: 'success',
              confirmButtonText: 'Aceptar',
            }).then((result) => {
              if (result.isConfirmed) {
                // Si el usuario confirma, recargamos la página
                location.reload();
              }
            });
          }

          else if(resultado.status === 'encontrado')
          {
            Swal.fire({
              title: '¡Error!',
              text: resultado.message,
              icon: 'error',
              confirmButtonText: 'Aceptar'
            });
          }

          else if(resultado.status === 'no registrado')
          {
            Swal.fire({
              title: '¡Error!',
              text: resultado.message,
              icon: 'error',
              confirmButtonText: 'Aceptar'
            });
          }

        } 
        catch (error) 
        {
            console.error('Error de red:', error);
            Swal.fire({
              title: '¡Error de Red!',
              icon: 'error',
              confirmButtonText: 'Aceptar'
            });
        }
      }

      // Llamar a la función para enviar los datos
      enviarDatos();
    }
  });
});