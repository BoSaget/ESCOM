using System;
using System.Collections.Generic;

public class Transicion
{
    private char SimbInf1;
    private cahr SimbSup1;
    private Estado Edo;
    public Transicion (char simb, Estado e)
    {
        SimbInf1 = simb;
        SimbSup1 = simb;
        Edo = e;
    }

    public Transicion(char simb1, char simb2, Estado e)
    {
        SimbInf1 = simb1;
        SimbSup1 = simb2;
        Edo = e;
    }
    public Transicion()
    {
        Edo = null;

    }

    public void SetTransicion(char s1, char s2, Estado e)
    {
        SimbInf1 = s1;
        SimbSup1 = s2;
        Edo = e;
    }
    public void SetTransicion(char s1, Estado e)
    {
        SimbInf1 = s1;
        SimbSup1 = s1;
        Edo = e;
        return;
    }

    public char SimbInf { get => SimbInf1; set => SimbInf1 = value; }
    public char SimbSup {  get => SimbSup1; set => SimbSup1 = value; }

    public Estado GetEdoTrans(char s)
    {
        if(SimbInf1 <= s && s <= SimbSup1)
        {
            return Edo;
        }
        return null;
    }
}