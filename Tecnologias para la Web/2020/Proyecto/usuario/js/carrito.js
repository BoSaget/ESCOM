document.addEventListener("DOMContentLoaded", () => {
    const carritoList = document.getElementById("carrito-list");
    const carritoTotal = document.getElementById("carrito-total");
    const generarPedido = document.getElementById("generar-pedido");
    const notasPedido = document.getElementById("notas-pedido");
    let carrito = [];

    function renderCarrito() {
        carritoList.innerHTML = "";
        let total = 0;
        carrito.forEach(item => {
            const li = document.createElement("li");
            li.textContent = `${item.name} - $${item.price} x ${item.quantity}`;
            carritoList.appendChild(li);
            total += item.price * item.quantity;
        });
        carritoTotal.textContent = total.toFixed(2);
    }

    document.querySelectorAll(".add-to-cart").forEach(button => {
        button.addEventListener("click", (event) => {
            const id = event.target.dataset.id;
            const name = event.target.dataset.name;
            const price = parseFloat(event.target.dataset.price);

            const itemIndex = carrito.findIndex(item => item.id === id);
            if (itemIndex > -1) {
                carrito[itemIndex].quantity += 1;
            } else {
                carrito.push({ id, name, price, quantity: 1 });
            }
            renderCarrito();
        });
    });

    generarPedido.addEventListener("click", () => {
        const notas = notasPedido.value;
        fetch('generarPedido.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ carrito: carrito , notas:notas }),
        })
        .then(response => response.json())
        .then(data => {
            if (data.status === 'success') {
                // Puedes limpiar el carrito después de guardar
                carrito = [];
                renderCarrito();
                notasPedido.value = "";
                Swal.fire({
                    title: 'Actualizado!',
                    text: 'El pedido fue generado',
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
                    text: data.message,
                    icon: 'error',
                    confirmButtonText: 'Aceptar'
                  });
            }
        })
        .catch((error) => {
            console.error('Error:', error);
        });
    });
});
