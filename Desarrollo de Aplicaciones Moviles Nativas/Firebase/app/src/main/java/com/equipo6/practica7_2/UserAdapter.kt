package com.equipo6.practica7_2

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class UserAdapter(
    private var users: MutableList<User>,
    private val onEdit: (User) -> Unit,
    private val onDelete: (User) -> Unit
) : RecyclerView.Adapter<UserAdapter.UserViewHolder>() {

    inner class UserViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val nameTextView: TextView = itemView.findViewById(R.id.tvUserName)
        val emailTextView: TextView = itemView.findViewById(R.id.tvUserEmail)
        val editButton: Button = itemView.findViewById(R.id.btnEditUser)
        val deleteButton: Button = itemView.findViewById(R.id.btnDeleteUser)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): UserViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.user_item, parent, false)
        return UserViewHolder(view)
    }

    override fun onBindViewHolder(holder: UserViewHolder, position: Int) {
        val user = users[position]
        holder.nameTextView.text = user.name
        holder.emailTextView.text = user.email

        holder.editButton.setOnClickListener { onEdit(user) }
        holder.deleteButton.setOnClickListener { onDelete(user) }

    }

    override fun getItemCount() = users.size

    fun updateUsers(newUsers: MutableList<User>) {
        users = newUsers
        notifyDataSetChanged()
    }
}