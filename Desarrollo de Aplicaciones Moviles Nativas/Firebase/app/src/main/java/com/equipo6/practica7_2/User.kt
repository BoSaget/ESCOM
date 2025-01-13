package com.equipo6.practica7_2

data class User(
    var id: String = "",
    var name: String = "",
    var email: String = "",
    var role: String = "user" // Puede ser "user" o "admin"
)