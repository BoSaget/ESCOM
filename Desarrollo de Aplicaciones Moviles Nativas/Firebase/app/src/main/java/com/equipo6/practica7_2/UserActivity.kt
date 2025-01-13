package com.equipo6.practica7_2

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.auth.FirebaseAuth

class UserActivity : AppCompatActivity() {

    private lateinit var auth: FirebaseAuth

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_user)

        auth = FirebaseAuth.getInstance()

        val viewProfileButton = findViewById<Button>(R.id.btnViewProfile)
        val logoutButton = findViewById<Button>(R.id.btnLogoutUser)

        viewProfileButton.setOnClickListener {
            // Aquí iría la lógica para ver y editar el perfil del usuario
            Toast.makeText(this, "Función de ver y editar perfil en construcción", Toast.LENGTH_SHORT).show()
        }

        logoutButton.setOnClickListener {
            auth.signOut()
            startActivity(Intent(this, LoginActivity::class.java))
            finish()
        }
    }
}