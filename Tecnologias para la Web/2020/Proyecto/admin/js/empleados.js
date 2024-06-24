function editRow(button) {
    var row = button.parentNode.parentNode;
    var cells = row.getElementsByTagName("td");
    for (var i = 1; i < cells.length-1; i++) {
        var cellValue = cells[i].innerText;
        cells[i].innerHTML = `<input type='text' value='${cellValue}' class='border border-slate-700'/>`;
    }
    button.style.display = "none";
    button.nextElementSibling.style.display = "inline-block";
}

function saveRow(button) {
    
    var row = button.parentNode.parentNode;
    var cells = row.getElementsByTagName("td");
    var id = row.getAttribute("data-id");
    var data = {};
    for (var i = 1; i < cells.length-1; i++) {
        var cellInput = cells[i].getElementsByTagName("input")[0];
        data[cells[i].dataset.column] = cellInput.value;
        cells[i].innerText = cellInput.value;
    }
    button.style.display = "none";
    button.previousElementSibling.style.display = "inline-block";

    fetch('actualizarEmpleado.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ id: id, data: data })
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            Swal.fire({
                title: 'Actualizado!',
                text: 'el registro fue actualizado',
                icon: 'success',
                confirmButtonText: 'Aceptar',
              }).then((result) => {
                if (result.isConfirmed) {
                  // Si el usuario confirma, recargamos la página
                  location.reload();
                }
              });
        } else {
            Swal.fire({
                title: '¡Error!',
                text: 'Hubo un error',
                icon: 'error',
                confirmButtonText: 'Aceptar'
              });
        }
    })
    .catch(error => {
        console.error('Error:', error);
    });
}

function deleteRow(button) {
    
    var row = button.parentNode.parentNode;
    var id = row.getAttribute("data-id");
    var usuario = row.getElementsByTagName("td")[3].innerText;
    
    Swal.fire({
        title: 'Seguro?',
        text: 'Seguro que quiere borrar a: '+ usuario + '?',
        icon: 'warning',
        confirmButtonText: 'Aceptar',
    }).then((result) => {
        if (result.isConfirmed) {
          // Si el usuario confirma, se procederá para el eliminado del platillo
          fetch('borrarEmpleado.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ id: id})
            })
            .then(response => response.json())
            .then(data => {
                if (data.success) {
                    Swal.fire({
                        title: 'Actualizado!',
                        text: usuario + ' fue eliminado',
                        icon: 'success',
                        confirmButtonText: 'Aceptar',
                    }).then((result) => {
                        if (result.isConfirmed) {
                        // Si el usuario confirma, recargamos la página
                        location.reload();
                        }
                    });
                } else {
                    Swal.fire({
                        title: '¡Error!',
                        text: 'Hubo un error al borrar' + usuario,
                        icon: 'error',
                        confirmButtonText: 'Aceptar'
                    });
                }
            })
            .catch(error => {
                console.error('Error:', error);
            });
        }

        
    });
}