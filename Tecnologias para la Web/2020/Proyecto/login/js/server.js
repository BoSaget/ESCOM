const express = require('express');
const http = require('http');
const socketIo = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = socketIo(server);

app.use(express.static('public')); // Sirve archivos estáticos desde la carpeta 'public'

io.on('connection', (socket) => {
  console.log('Nuevo cliente conectado');

  socket.on('formSubmit', (formData) => {
    console.log('Datos del formulario recibidos:', formData);
    // Aquí puedes manejar los datos del formulario
  });

  socket.on('disconnect', () => {
    console.log('Cliente desconectado');
  });
});

const PORT = process.env.PORT || 5500;
server.listen(PORT, () => console.log(`Servidor corriendo en el puerto ${PORT}`));
