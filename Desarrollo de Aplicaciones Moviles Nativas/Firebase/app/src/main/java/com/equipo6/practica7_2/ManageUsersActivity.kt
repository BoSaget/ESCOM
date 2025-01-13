package com.equipo6.practica7_2

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.google.firebase.firestore.FirebaseFirestore

class ManageUsersActivity : AppCompatActivity() {

    private lateinit var recyclerView: RecyclerView
    private lateinit var addButton: Button
    private lateinit var userAdapter: UserAdapter
    private val db = FirebaseFirestore.getInstance()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_manage_users)

        recyclerView = findViewById(R.id.rvUsers)
        addButton = findViewById(R.id.btnAddUser)

        recyclerView.layoutManager = LinearLayoutManager(this)
        userAdapter = UserAdapter(mutableListOf(), ::onEditUser, ::onDeleteUser)
        recyclerView.adapter = userAdapter

        fetchUsers()

        addButton.setOnClickListener {
            //startActivity(Intent(this, AddUserActivity::class.java))
        }

    }

    private fun fetchUsers() {
        db.collection("users")
            .get()
            .addOnSuccessListener { documents ->
                val users = mutableListOf<User>()
                for (document in documents) {
                    val user = document.toObject(User::class.java)
                    user.id = document.id
                    users.add(user)
                }
                userAdapter.updateUsers(users)
            }
            .addOnFailureListener {
                Toast.makeText(this, "Error al obtener usuarios", Toast.LENGTH_SHORT).show()
            }
    }

    private fun onEditUser(user: User) {
        // Navegar a EditUserActivity con los datos del usuario
        //val intent = Intent(this, EditUserActivity::class.java)
        intent.putExtra("USER_ID", user.id)
        intent.putExtra("USER_NAME", user.name)
        intent.putExtra("USER_EMAIL", user.email)
        intent.putExtra("USER_ROLE", user.role)
        startActivity(intent)
    }

    private fun onDeleteUser(user: User) {
        db.collection("users").document(user.id)
            .delete()
            .addOnSuccessListener {
                Toast.makeText(this, "Usuario eliminado", Toast.LENGTH_SHORT).show()
                fetchUsers() // Actualizar la lista
            }
            .addOnFailureListener {
                Toast.makeText(this, "Error al eliminar usuario", Toast.LENGTH_SHORT).show()
            }
    }
}