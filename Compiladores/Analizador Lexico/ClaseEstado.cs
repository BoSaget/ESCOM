using System;
using System.Collections.Generic;

public class Estado
{
    static int ContadorIdEstado = 0;
    private int IdEstado1;
    private bool EdoAcept1;
    private int Token1;
    private HashSet<Transicion> Trans1 = new HashSet<Transicion>();
    public Estado()
    {
        EdoAcept = false;
        Token = -1;

        IdEstado1 = ContadorIdEstado++;
        Trans1.Clear();
    }

    public int IdEstao { get => IdEstado1; set => IdEstado1 = value; }
    public bool EdoAcept { get => EdoAcept1; set => EdoAcept1 = value; }
    public int Token { get => Token1; set => Token1 = value; }
    public HashSet<Transicion> Trans { get => Trans1; set => Trans1 = value; }

}