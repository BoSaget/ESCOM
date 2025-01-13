package com.equipo6.practica7_2

import android.Manifest
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.pm.PackageManager
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.ProgressBar
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.app.NotificationCompat
import androidx.core.app.NotificationManagerCompat
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.firestore.FirebaseFirestore
import com.google.firebase.messaging.FirebaseMessaging

class RegisterActivity : AppCompatActivity() {
    private lateinit var auth: FirebaseAuth
    private lateinit var db: FirebaseFirestore
    private lateinit var progressBar: ProgressBar

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_register)
        enableEdgeToEdge()

        // Inicializar Firebase Auth y Firestore
        auth = FirebaseAuth.getInstance()
        db = FirebaseFirestore.getInstance()

        // Referencias a los elementos de la interfaz
        val nameField = findViewById<EditText>(R.id.etName)
        val emailField = findViewById<EditText>(R.id.etEmail)
        val passwordField = findViewById<EditText>(R.id.etPassword)
        val confirmPasswordField = findViewById<EditText>(R.id.etConfirmPassword)
        val registerButton = findViewById<Button>(R.id.btnRegister)
        progressBar = findViewById(R.id.progressBar)

        // Acción del botón de registro
        registerButton.setOnClickListener {
            val name = nameField.text.toString().trim()
            val email = emailField.text.toString().trim()
            val password = passwordField.text.toString().trim()
            val confirmPassword = confirmPasswordField.text.toString().trim()

            // Validaciones de campos
            if (name.isBlank() || email.isBlank() || password.isBlank() || confirmPassword.isBlank()) {
                Toast.makeText(this, "Completa todos los campos", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            if (!android.util.Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
                Toast.makeText(this, "Ingresa un correo válido", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            if (password.length < 6) {
                Toast.makeText(this, "La contraseña debe tener al menos 6 caracteres", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            if (password != confirmPassword) {
                Toast.makeText(this, "Las contraseñas no coinciden", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
                val channel = NotificationChannel(
                    "default_channel_id",
                    "Canal predeterminado",
                    NotificationManager.IMPORTANCE_HIGH
                ).apply {
                    description = "Canal para notificaciones generales"
                }
                val notificationManager = getSystemService(NotificationManager::class.java)
                notificationManager.createNotificationChannel(channel)
            }

            // Mostrar el ProgressBar y deshabilitar el botón
            progressBar.visibility = View.VISIBLE
            registerButton.isEnabled = false

            // Crear el usuario en Firebase Authentication
            auth.createUserWithEmailAndPassword(email, password)
                .addOnCompleteListener { task ->
                    if (task.isSuccessful) {
                        val userId = auth.currentUser?.uid
                        val user = hashMapOf(
                            "name" to name,
                            "email" to email,
                            "role" to "user" // Coincide con tu base de datos
                        )

                        // Guardar los datos del usuario en Firestore
                        if (userId != null) {
                            db.collection("Users").document(userId)
                                .set(user)
                                .addOnSuccessListener {
                                    // Obtener el token del dispositivo para notificaciones
                                    FirebaseMessaging.getInstance().token.addOnCompleteListener { tokenTask ->
                                        if (tokenTask.isSuccessful) {
                                            val token = tokenTask.result
                                            Log.d("FCM Token", "Token obtenido: $token")
                                            // Enviar notificación al usuario
                                            sendPushNotification(token, name)
                                        } else {
                                            Toast.makeText(this, "Error al obtener el token para notificaciones", Toast.LENGTH_SHORT).show()
                                            Log.e("FCM Token", "Error al obtener el token", task.exception)
                                        }
                                    }
                                    Toast.makeText(this, "Registro exitoso", Toast.LENGTH_SHORT).show()
                                    finish() // Finalizar la actividad
                                }
                                .addOnFailureListener { e ->
                                    Toast.makeText(this, "Error al guardar datos: ${e.message}", Toast.LENGTH_SHORT).show()
                                }
                        } else {
                            Toast.makeText(this, "Error: ID de usuario no válido", Toast.LENGTH_SHORT).show()
                        }
                    } else {
                        Toast.makeText(this, "Error al registrar usuario: ${task.exception?.message}", Toast.LENGTH_SHORT).show()
                    }

                    // Ocultar el ProgressBar y habilitar el botón
                    progressBar.visibility = View.GONE
                    registerButton.isEnabled = true
                }
        }
    }

    private fun sendPushNotification(token: String, userName: String) {
        // Construir el mensaje
        val messageTitle = "¡Bienvenido a la aplicación!"
        val messageBody = "Hola $userName, gracias por registrarte."

        // Enviar la notificación mediante el token de Firebase
        val notification = NotificationCompat.Builder(this, "default_channel_id")
            .setSmallIcon(android.R.drawable.ic_dialog_info)
            .setContentTitle(messageTitle)
            .setContentText(messageBody)
            .setPriority(NotificationCompat.PRIORITY_HIGH)
            .setAutoCancel(true)
            .build()

        // Enviar la notificación al dispositivo usando NotificationManagerCompat
        if (ActivityCompat.checkSelfPermission(
                this,
                Manifest.permission.POST_NOTIFICATIONS
            ) != PackageManager.PERMISSION_GRANTED
        ) {
            // TODO: Consider calling
            //    ActivityCompat#requestPermissions
            // here to request the missing permissions, and then overriding
            //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
            //                                          int[] grantResults)
            // to handle the case where the user grants the permission. See the documentation
            // for ActivityCompat#requestPermissions for more details.
            return
        }
        NotificationManagerCompat.from(this).notify(1001, notification)

        Toast.makeText(this, "Notificación enviada al token: $token", Toast.LENGTH_LONG).show()
    }

}
