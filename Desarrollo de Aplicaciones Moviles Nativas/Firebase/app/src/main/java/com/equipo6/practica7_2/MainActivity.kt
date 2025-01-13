package com.equipo6.practica7_2

import android.Manifest
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.content.Intent
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.os.Handler
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        enableEdgeToEdge()

        checkAndRequestNotificationPermission()

        Handler().postDelayed({

            val intent = Intent(this, LoginActivity::class.java)
            startActivity(intent)
            finish()
        }, 2000)
    }

    // Función para crear el canal de notificación
    private fun createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            val channelId = "default_channel"
            val channelName = "Default Notifications"
            val importance = NotificationManager.IMPORTANCE_DEFAULT

            // Crear el canal de notificación
            val notificationChannel =
                NotificationChannel(channelId, channelName, importance).apply {
                    description = "General notifications"
                }

            // Registrar el canal con el sistema
            val notificationManager =
                getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
            notificationManager.createNotificationChannel(notificationChannel)
        }
    }

    // Lanzador para solicitar permisos
    private val requestPermissionLauncher =
        registerForActivityResult(ActivityResultContracts.RequestPermission()) { isGranted: Boolean ->
            if (isGranted) {
                Toast.makeText(this, "Permiso concedido. ¡Ahora puedes recibir notificaciones!", Toast.LENGTH_SHORT).show()
            } else {
                Toast.makeText(this, "Permiso denegado. No podrás recibir notificaciones.", Toast.LENGTH_SHORT).show()
            }
        }

    private fun checkAndRequestNotificationPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) { // API 33+
            if (ContextCompat.checkSelfPermission(this, Manifest.permission.POST_NOTIFICATIONS)
                != PackageManager.PERMISSION_GRANTED
            ) {
                // Solicitar permiso
                requestPermissionLauncher.launch(Manifest.permission.POST_NOTIFICATIONS)
            } else {
                // Permiso ya otorgado
                Toast.makeText(this, "Permiso ya concedido para notificaciones", Toast.LENGTH_SHORT).show()
            }
        } else {
            // No se necesita permiso para versiones inferiores a Android 13
            Toast.makeText(this, "No se necesita permiso para notificaciones", Toast.LENGTH_SHORT).show()
        }
    }


}



