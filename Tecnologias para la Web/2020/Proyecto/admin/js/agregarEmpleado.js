//Para el registro
document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('add-button').addEventListener('click', function(e) {
      
      e.preventDefault();
      var formularioRegistro = document.getElementById('agregarEmpleado');
      var datosRegistro = new FormData(formularioRegistro);
      const palominoEmailRegex = /^[a-zA-Z0-9._%+-]+@pl\.com$/;
  
      if(datosRegistro.get('correo') == '' && datosRegistro.get('nombre') == '' && datosRegistro.get('pass') == '')
        {
          Swal.fire({
            title: '¡Cuidado!',
            text: 'Todos los campos se encuentran vacios en  el registro',
            icon: 'warning',
            confirmButtonText: 'Aceptar'
          });
        }
  
      //Validation de si el correo en registro está vacio
      else if(datosRegistro.get('correo') == '')
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'Ingresa un correo en el registro',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }
  
      //Checa si no es una dirección de correo de la empresa
      else if(palominoEmailRegex.test(datosRegistro.get('correo')) == false)
        {
          Swal.fire({
            title: '¡Error!',
            text: 'Se debe de ingresar el dominio @pl.com para todos los empleados',
            icon: 'error',
            confirmButtonText: 'Aceptar'
          });
        }

    //Validation de si el nombre en registro está vacio
      else if(datosRegistro.get('nombre') == '')
        {
          Swal.fire({
            title: '¡Cuidado!',
            text: 'Ingresa un nombre en el registro',
            icon: 'warning',
            confirmButtonText: 'Aceptar'
          });
        }
  
      //Validación para ver si el campo de contraseña está vacio
      else if(datosRegistro.get('pass') == '')
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
          rol: datosRegistro.get('rol'),
          email: datosRegistro.get('correo'),
          nombre: datosRegistro.get('nombre'),
          pass: datosRegistro.get('pass')
        };
  
        // Función para enviar los datos
        async function enviarDatos() 
        {
          try 
          {
            const response = await fetch('./guardarEmpleado.php', {
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
                text: 'Empleado guardado con exito',
                icon: 'success',
                confirmButtonText: 'Aceptar',
              }).then((result) => {
                if (result.isConfirmed) {
                    window.location.href = "./empleados.php";
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