package com.equipo6.practica7_2

import android.Manifest
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.pm.PackageManager
import android.os.Build
import androidx.core.app.ActivityCompat
import androidx.core.app.NotificationCompat
import androidx.core.app.NotificationManagerCompat
import com.google.firebase.messaging.FirebaseMessagingService
import com.google.firebase.messaging.RemoteMessage

class MyFirebaseMessagingService : FirebaseMessagingService() {

    override fun onMessageReceived(remoteMessage: RemoteMessage) {
        super.onMessageReceived(remoteMessage)

        // Verifica que el mensaje tenga datos o notificación
        val notificationTitle = remoteMessage.notification?.title ?: "Título predeterminado"
        val notificationBody = remoteMessage.notification?.body ?: "Cuerpo predeterminado"
        val channelId = "default_channel_id"
        val notificationId = 101

        // Crear el canal de notificación (necesario para Android 8.0+)
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            val channel = NotificationChannel(
                channelId,
                "Default Channel",
                NotificationManager.IMPORTANCE_HIGH
            ).apply {
                description = "Este es el canal predeterminado para notificaciones"
            }
            val notificationManager = getSystemService(NotificationManager::class.java)
            notificationManager?.createNotificationChannel(channel)
        }

        // Construir la notificación
        val notification = NotificationCompat.Builder(this, channelId)
            .setSmallIcon(android.R.drawable.ic_dialog_info) // Cambia este ícono por uno personalizado si lo deseas
            .setContentTitle(notificationTitle)
            .setContentText(notificationBody)
            .setPriority(NotificationCompat.PRIORITY_HIGH)
            .setAutoCancel(true) // Descartar la notificación al tocarla
            .build()

        // Verificar el permiso para mostrar notificaciones (necesario en Android 13+)
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            if (ActivityCompat.checkSelfPermission(
                    this,
                    Manifest.permission.POST_NOTIFICATIONS
                ) != PackageManager.PERMISSION_GRANTED
            ) {
                // Si no se tiene el permiso, no se muestra la notificación
                return
            }
        }

        // Mostrar la notificación
        NotificationManagerCompat.from(applicationContext).notify(notificationId, notification)
    }
}

