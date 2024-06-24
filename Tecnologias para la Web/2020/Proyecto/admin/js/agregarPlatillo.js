//Para ingresar
document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('add-button').addEventListener('click', function(e) {
      
      e.preventDefault();
      var formularioPlatillo = document.getElementById('platillo');
      var datosPlatillo = new FormData(formularioPlatillo);
  
      //Revisa si ambos campos se encuentran vacios
      if(datosPlatillo.get('platillo') == '' && datosPlatillo.get('tipo')=='' && datosPlatillo.get('precio') == '')
        {
          Swal.fire({
            title: '¡Cuidado!',
            text: 'Los campos de platillo, tipo y precio se encuentran vacios, favor de llenarlos',
            icon: 'warning',
            confirmButtonText: 'Aceptar'
          });
        }
  
      else if(datosPlatillo.get('platillo') == '')
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'El campo platillo no puede estar vacio',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }
  
      else if(datosPlatillo.get('tipo') == '')
      {
        Swal.fire({
          title: '¡Cuidado!',
          text: 'El campo tipo no puede estar vacio',
          icon: 'warning',
          confirmButtonText: 'Aceptar'
        });
      }

      else if(datosPlatillo.get('precio') == '')
        {
          Swal.fire({
            title: '¡Cuidado!',
            text: 'El campo precio no puede estar vacio',
            icon: 'warning',
            confirmButtonText: 'Aceptar'
          });
        }
  
      else{
        // Datos que quieres enviar al archivo PHP
        const registro = {
          platillo: datosPlatillo.get('platillo'),
          tipo: datosPlatillo.get('tipo'),
          ingredientes: datosPlatillo.get('ingredientes'),
          notas: datosPlatillo.get('notas'),
          precio: datosPlatillo.get('precio')
        };
  
        // Función para enviar los datos
      async function enviarDatos() 
      {
        try 
        {
          const response = await fetch('./guardarPlatillo.php', {
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
              text: 'Platillo registrado con exito',
              icon: 'success',
              confirmButtonText: 'Aceptar',
            }).then((result) => {
              if (result.isConfirmed) {
                // Si el usuario confirma, recargamos la página
                window.location.href = "./modificarMenu.php";
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