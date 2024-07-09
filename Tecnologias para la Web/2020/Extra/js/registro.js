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
    if(datosRegistro.get('user-name') == '' && datosRegistro.get('user-lastname') == '' && datosRegistro.get('user-dir') == '' && datosRegistro.get('user-tel') == '' && datosRegistro.get('user-mail') == '' && datosRegistro.get('user-doc') == '' && datosRegistro.get('user-birth') == ''  && datosRegistro.get('user-contract') == '' && datosRegistro.get('user-personal') == ''  && datosRegistro.get('user-sign-date') == '')
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'Todos los campos se encuentran vacios',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }

    else if(datosRegistro.get('user-name') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese un nombre',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }
    else if(datosRegistro.get('user-lastname') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese un apellido',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-dir') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese una direccion',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });   
    }

    else if(datosRegistro.get('user-tel') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese un numero de telefono',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-mail') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese un correo',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-doc') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese un documento',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-birth') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese una fecha de nacimiento',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-contado') != 1 && datosRegistro.get('user-credito') != 1)
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'Favor de seleccionar una forma de pago',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }

    else if(datosRegistro.get('user-contado') == 1 && datosRegistro.get('user-credito')== 1)
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Favor de solo seleccionar una forma de pago',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-contract') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese un numero de contrato',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-personal') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese un nombre de personal',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else if(datosRegistro.get('user-sign-date') == '')
    {
      Swal.fire({
        title: '¡Cuidado!',
        text: 'Ingrese fecha de registro',
        icon: 'warning',
        confirmButtonText: 'Aceptar'
      });
    }

    else
    {
      // Datos que quieres enviar al archivo PHP

      const registro = {
        nombre: datosRegistro.get('user-name'),
        apellido: datosRegistro.get('user-lastname'),
        direccion: datosRegistro.get('user-dir'),
        telefono: datosRegistro.get('user-tel'),
        mail: datosRegistro.get('user-mail'),
        documento: datosRegistro.get('user-doc'),
        nacimiento: datosRegistro.get('user-birth'),
        curso: datosRegistro.get('user-course'),
        horario: datosRegistro.get('course-hour'),
        contado: datosRegistro.get('user-contado'),
        credito: datosRegistro.get('user-credito'),
        contrato: datosRegistro.get('user-contract'),
        personal: datosRegistro.get('user-personal'),
        inscripcion: datosRegistro.get('user-sign-date')
      };

      // Función para enviar los datos
      async function enviarDatos() 
      {
        try 
        {
          const response = await fetch('./registro.php', {
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
  document.getElementById('delete-button').addEventListener('click', function(e) {
    
    e.preventDefault();
    var formularioRegistro = document.getElementById('registro');
    var datosRegistro = new FormData(formularioRegistro);
    const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    const palominoEmailRegex = /^[a-zA-Z0-9._%+-]+@pl\.com$/;

    //console.log(datosRegistro.get('user-sign'))
    //console.log(datosRegistro.get('user-sign-pass'))

    //Revisa si ambos campos se encuentran vacios
    if(datosRegistro.get('user-id') == '' )
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'Todos los campos se encuentran vacios',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }

    else
    {
      // Datos que quieres enviar al archivo PHP

      const registro = {
        id: datosRegistro.get('user-id')
      };

      // Función para enviar los datos
      async function enviarDatos() 
      {
        try 
        {
          const response = await fetch('./borrar.php', {
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