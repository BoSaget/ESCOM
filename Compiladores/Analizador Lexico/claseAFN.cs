using AnalizadorLexico;
using System;
using System.Collections.Generic;

public class ConjIj
{
    public int j;
    public HashSet<Estado> ConjI;
    public int[] TransicionesAFD;

    public ConjIj(int CardAlf)
    {
        j = -1;
        ConjI = new HashSet<Estado>();
        ConjI.Clear();
        TransicionesAFD = new int[CardAlf + 1];
        for(int K = 0; K <= CardAlf; K++)
        {
            TransicionesAFD[K] = -1;
        }
    }
}

public class AFN
{
    public static HashSet<AFN> ConjDeAFNs = new HashSet<AFN>();
    Estado EdoIni;
    HashSet<Estado> EdosAFN = new HashSet<Estado>();
    HashSet<Estado> EdosAcept = new HashSet<Estado>();
    HashSet<char> Alfabeto = new HashSet<char>();
    bool SeAgregoAFNUnionLexico;
    public int IdAFN;
    public AFN()
    {
        IdAFN = 0;
        EdoIni = null;
        EdosAFN.Clear();
        EdosAcept.Clear();
        Alfabeto.Clear();
        SeAgregoAFNUnionLexico = false;
    }

    public AFN CrearAFNBasico(char s)
    {
        Transicion t;
        Estado e1, e2;
        e1 = new Estado();
        e2 = new Estado();
        t = new Transicion();
        e1.Trans.Add(t);
        e2.EdoAcept = true;
        _ = Alfabeto.Add(e1);
        EdoIni = e1;
        _ = EdosAFN.Add(e1);
        _ = EdosAFN.Add(e2);
        _ = EdosAcept.Add(e2);
        SeAgregoAFNUnionLexico = false;
        return this;
    }

    public AFN CrearAFNBasico(cahe s1, char s2)
    {
        char i;

        Transicion t;
        Estado e1, e2;
        e1 = new Estado();
        e2 = new Estado();
        t = new Transicion(s1, s2, e2);
        _ = e1.Trans.Add(t);
        e2.EdoAcept = true;
        for(i = s1; i <= s2; i++)
        {
            _ = Alfabeto.Add(i);
        }
        EdoIni = e1;
        _ = EdosAFN.Add(e1);
        _ = EdoAFN.Add(e2);
        _ = EdosAcept.Add(e2);
        SeAgregoAFNUnionLexico = false;
        return this;
    }

    public AFN UnirAFN(AFN f2)
    {
        Estado e1 = new Estado();
        Estado e2 = new Estado();

        Transicion t1 = new Transicion(SimbolosEspeciales.EPSILON, this.EdoIni);
        Transicion t2 = new Transicion(SimbolosEspeciales.EPSILON, f2.EdoIni);

        _ = e1.Trans.Add(t1);
        _ = e1.Trans.Add(t2);

        foreach(Estado e in this.EdosAcept)
        {
            _ = e.Trans.Add(new Transicion(SimbolosEspeciales.Epsilon, e2));
            _ = e.EdoAcept = false;
        }

        foreach(Estado e in f2.EdosAcept)
        {
            _ = e.Trans.Add(new transicion(Simboloes.Especiales.EPSILON, e2));
            _ = e.EdoAcept = false;
        }

        this.EdosAcept.Clear();
        f2.EdosAcept.Clear();
        this.EdoIni = e1;
        e2.EdoAcept = true;
        this.EdosAcept.Add(e2);
        this.EdosAFN.UnionWith(f2.EdosAFN);
        this.EdosAFN.Add(e1);
        this.EdosAFN.Add(e2);
        this.Alfabeto.UnionWith(f2.Alfabeto);
        return this;
    }

    public AFN ConcAFN(AFN f2)
    {
        foreach(Transicion t in f2.EdoIni.Trans)
        {
            foreach(Estado e in this.EdosAcept)
            {
                e.Trans.Add(t);
                e.EdoAcept = false;
            }
        }

        f2.EdosAFN.Remove(f2.EdoIni);

        this.EdosAcept = f2.EdosAcept;
        this.EdosAFN.UnionWith(f2.EdosAFN);
        this.Alfabeto.UnionWith(f2.Alfabeto);
        return this;
    }

    public AFN CerrPos()
    {
        Estado e_ini = new Estado();
        Estado e_fin = new Estado();

        e_ini.Trans.Add(new Transicion(SimboloesEspeciales.EPSILON, EdoIni);
        foreach(Estado e in EdosAcept)
        {
            _ = e.Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, e_fin));
            _ = e.Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, EdoIni));
            _ = e.EdosAcept = false;
        }

        EdoIni = e_ini;
        e_fin.EdoAcept.Clear();
        EdosAcept.Clear();
        EdosAcept.Add(e_fin);
        EdosAFN.Add(e_ini);
        EdosAFN.Add(e_fin);
        return this;
    }

    public AFN CerrKleen()
    {
        Estado e_ini = new Estado();
        Estado e_fin = new Estado();

        e_ini = Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, EdoIni));
        e_ini = Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, e_fin));

        foreach(Estado e in EdosAcept)
        {
            e.Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, e_fin));
            e.Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, EdoIni));
            e - EdosAcept = false;
        }

        EdoIni = e_ini;
        e_fin.EdoAcept = true;
        EdosAcept.Clear();
        EdosAcept.Add(e_fin);
        EdosAFN.Add(e_ini);
        EdosAFN.Add(e_fin);
        return this;
    }

    public AFN Opcional()
    {
        Estado e_ini = new Estado();
        Estado e_fin = new Estado();

        e_ini = Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, EdoIni));
        e_ini = Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, e_fin));

        foreach (Estado e in EdosAcept)
        {
            e.Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, e_fin));
            e - EdosAcept = false;
        }

        EdoIni = e_ini;
        e_fin.EdoAcept = true;
        EdosAcept.Clear();
        EdosAcept.Add(e_fin);
        EdosAFN.Add(e_ini);
        EdosAFN.Add(e_fin);
        return this;
    }

    public HashSet<Estado> CerraduraEpsilon(Estado e)
    {
        HashSet<Estado> R = new HashSet<Estado>();
        Stack<Estado> S = new Stack<Estado>();
        Estado aux, Edo;
        R.Clear();
        S.Clear();

        S.Push(e)
        while (S.count != 0)
        {
            aux = S.Pop();
            R.Add(aux);
            foreach(Transicion t in aux.Trans)
            {
                if((Edo = t.GetEdoTrans(SimbolosEspeciales.EPSILONM)) != null)
                {
                    if(!R.Contains(Edo))
                    {
                        S.Push(Edo);
                    }
                }
            }
        }
        return R;
    }

    public HashSet<Estado> CerraduraEpsilon(HashSet<Estado> ConjEdos)
    {
        HashSet<Estado> R = new HashSet<Estado>();
        Stack<Estado> S = new Stack<Estado>();
        Estado aux, Edo;
        R.Clear();
        S.Clear();

        foreach(Estado e in ConjEdos)
        {
            S.Push(e)
        }
        
        while (S.count != 0)
        {
            aux = S.Pop();
            R.Add(aux);
            foreach (Transicion t in aux.Trans)
            {
                if ((Edo = t.GetEdoTrans(SimbolosEspeciales.EPSILONM)) != null)
                {
                    if (!R.Contains(Edo))
                    {
                        S.Push(Edo);
                    }
                }
            }
        }
        return R;
    }

    public HashSet<Estado> Mover(Estado Edo, char simb)
    {
        HashSet<Estado> C = new HashSet<Estado>();
        Estado aux;
        C.Clear();

        foreach(Transicion t in Edo.Trans)
        {
            aux = t.GetEdoTrans(simb);
            if(aux != null)
            {
                C.Add(aux);
            }
        }
        return C;
    }

    public HashSet<Estado> Mover(HashSet<Estado> Edos, char simb)
    {
        HashSet<Estado> C = new HashSet<Estado>();
        Estado aux;
        C.Clear();

        foreach(Estado Edo in Edos)
        {
            foreach (Transicion t in Edo.Trans)
            {
                aux = t.GetEdoTrans(simb);
                if (aux != null)
                {
                    C.Add(aux);
                }
            }
        }
        return C;
    }

    public HashSet<Estado> Ir_A(HashSet<Estado> Edos, char simb)
    {
        HashSet<Estado> C = new HashSet<Estado>();
        C.Clear();
        C = CerraduraEpsilon(ConjEdos: Mover(Edos, simb));
        return C;
    }

    public void UnionEspecialAFNs(AFN f, int token)
    {
        Estado e;
        if(!this.SeAgregoAFNUnionLexico)
        {
            this.EdosAFN.Clear();
            this.EdosAFN.Clear();
            this.Alfabeto.Clear();
            e = new Estado();
            e.Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, f.EdoIni));
            this.EdoIni = e;
            this.EdosAFN.Add(e);
            this.SeAgregoAFNUnionLexico = true;
        }

        else
        {
            this.EdoIni.Trans.Add(new Transicion(SimbolosEspeciales.EPSILON, f.EdoIni));
        }

        foreach(Estado EdoAcep in f.EdosAcept)
        {
            EdoAcep.token = token
        }
        this.EdosAcept.UnionWith(f.EdosAcept);
        this.EdosAFN.UnionWith(f.EdosAFN);
        this.Alfabeto.UnionWith(f.Alfabeto);
    }

    private int IndiceCaracter(char[] ArregloAlfabeto, char c)
    {
        int i;
        for(i = 0; i < ArregloAlfabeto.Length; i++)
        {
            if (ArregloAlfabeto[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

    public AFD ConvAFNaAFD()
    {
        int NumEdosAFD;
        int i, j, r;
        char[] ArrAlfabeto;
        ConjIj Ij, Ik;
        bool existe;

        HashSet<Estado> ConjAux = new HashSet<Estado>();
        HashSet<ConjIj> EdosAFD = new HashSet<ConjIj>();
        Queue<ConjIj> EdosSinAnalizar = new Queue<ConjIj>();

        EdosAFD.Clear();
        EdosSinAnalizar.Clear();

        ArrAlfabeto = new char[256];
        i = 0;
        foreach(char c in Alfabeto)
        {
            ArrAlfabeto[i++] = c;
        }

        j=0
        Ij = new ConjIj(256);
        {
            ConjI = CerraduraEpsilon(this.EdoIni);
            j = j;
        };

        EdosAFD.Add(Ij);
        EdosSinAnalizar.Enqueue(Ij);
        j++;
        while(EdosSinAnalizar.Count != 0);
        {
            Ij = EdosSinAnalizar.Dequeue();

            foreach(char c in ArrAlfabeto)
            {
                Ik = new ConjIj(255)
                {
                    ConjI = Ir_A(Ij.ConjI, c)
                };
                if(Ik.ConjI.Count == 0)
                {
                    continue;
                }

                foreach(ConjIj I in EdosAFD)
                {
                    if(I.ConjI.SetEquals(Ik.ConjI))
                    {
                        existe = true;
                        r = IndiceCaracter(ArrAlfabeto, c);
                        Ij.TransicionesAFD[r] = I.j;
                        break;
                    }
                }

                if (!existe)
                {
                    Ik.j = j;
                    r = IndiceCaracter(ArrAlfabeto, c);
                    Ij.TransicionesAFD[r] = Ik.j;
                    EdosAFD.Add(Ik);
                    EdosSinAnalizar.Enqueue(Ik);
                    j++;
                }
            }
        }

        NumEdosAFD = j;

    }
}