package com.equipo6.practica7_2

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.auth.FirebaseAuth

class AdminActivity : AppCompatActivity() {

    private lateinit var auth: FirebaseAuth

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_admin)

        auth = FirebaseAuth.getInstance()

        val manageUsersButton = findViewById<Button>(R.id.btnManageUsers)
        val sendNotificationsButton = findViewById<Button>(R.id.btnSendNotifications)
        val logoutButton = findViewById<Button>(R.id.btnLogoutAdmin)

        manageUsersButton.setOnClickListener {
           startActivity(Intent(this, ManageUsersActivity::class.java))
        }

        sendNotificationsButton.setOnClickListener {
            // Aquí iría la lógica para enviar notificaciones
            Toast.makeText(this, "Función de enviar notificaciones en construcción", Toast.LENGTH_SHORT).show()
        }

        logoutButton.setOnClickListener {
            auth.signOut()
            startActivity(Intent(this, LoginActivity::class.java))
            finish()
        }
    }
}