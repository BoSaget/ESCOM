from itertools import *

def get_clase_mascara(ip,dictclase):
    for clase in dictclase:
        valores = dictclase[clase]
        ipsplit = ip.split(".")
        if int(ipsplit[0]) >= valores[0] and int(ipsplit[0]) <=valores[1]:
            return clase,dictclase[clase][2]
        
#num redes mayor a 1
def get_bits_prestados(numredes,clase):
    bitsdisp = {"A":24,"B":16,"C":8}
    for bits in range(bitsdisp[clase]):
        if numredes <= pow(2,bits)-2:
            return bits



def genera_tablasubeteo(clase,ip,bitsprestados):
    clasebits = {"A":"00000000.00000000.00000000","B":"00000000.00000000","C":"00000000"}
    listbits = getbinario(bitsprestados,clase)
    #print("IP: ",ip)
    ipsplit = ip.split(".")
    #print(ipsplit)
    listasegmentos = []
    if clase == "C":
        ultimo = []
        ban = False
        for combinacionesip in listbits:
            
            #print(combinacionesip + " :  "+str(binario_a_decimal(combinacionesip)))
            if ban:
                ultimo.append(binario_a_decimal(combinacionesip)-1)
                listasegmentos.append(ultimo)
                ultimo = [ipsplit[0],ipsplit[1],ipsplit[2],combinacionesip,binario_a_decimal(combinacionesip)]
            else:
                ultimo = [ipsplit[0],ipsplit[1],ipsplit[2],combinacionesip,binario_a_decimal(combinacionesip)]
                ban = True
        ultimo.append(255)
        listasegmentos.append(ultimo)
    elif clase == "B":
        ultimo = []
        ban = False
        for combinacionesip in listbits:
            combinacionesipuno = combinacionesip[0:8]
            combinacionesipdos = combinacionesip[8::]

            #print(combinacionesip+ "   " +combinacionesipuno+"."+combinacionesipdos + " :  "+str(binario_a_decimal(combinacionesipuno)) + " :  "+str(binario_a_decimal(combinacionesipdos)))
            if ban:
                if combinacionesipdos.find("1") != -1:
                    ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+"."+str(binario_a_decimal(combinacionesipdos)-1))
                else:
                    ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+".255")
                listasegmentos.append(ultimo)
                ultimo = [ipsplit[0],ipsplit[1],combinacionesipuno+"."+combinacionesipdos,str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos))]
            else:
                ultimo = [ipsplit[0],ipsplit[1],combinacionesipuno+"."+combinacionesipdos,str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos))]
                ban = True
        ultimo.append("255.255")
        listasegmentos.append(ultimo)
    elif clase == "A":
        ultimo = []
        ban = False
        for combinacionesip in listbits:
            combinacionesipuno = combinacionesip[0:8]
            combinacionesipdos = combinacionesip[8:16]
            combinacionesiptres = combinacionesip[16::]    
            #print(combinacionesip+ "   " +combinacionesipuno+"."+combinacionesipdos +"."+combinacionesiptres + " :  "+str(binario_a_decimal(combinacionesipuno)) + " :  "+str(binario_a_decimal(combinacionesipdos)) + " :  "+str(binario_a_decimal(combinacionesiptres)))
            if ban:
                """print(binario_a_decimal(combinacionesipuno)-1)
                if bitsprestados > 0 and bitsprestados <=8:    
                    ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+".255.255")
                elif bitsprestados > 8 and bitsprestados <=16:
                    if binario_a_decimal(combinacionesipuno)-1 != -1:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+"."+str(binario_a_decimal(combinacionesipdos)-1)+".255")
                    else:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos)-1)+".255")
                """
                if bitsprestados > 0 and bitsprestados <= 8:
                    ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+".255.255")
                elif bitsprestados > 8 and bitsprestados <= 16:
                    if ultimo[1].split(".")[0] == combinacionesipuno:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos)-1)+".255")
                    else:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+".255.255")
                elif bitsprestados > 16 and bitsprestados <= 24:
                    if ultimo[1].split(".")[0] == combinacionesipuno and ultimo[1].split(".")[1] == combinacionesipdos and ultimo[1].split(".")[2] == combinacionesiptres:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos))+".255")
                    elif ultimo[1].split(".")[0] == combinacionesipuno and ultimo[1].split(".")[1] == combinacionesipdos:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos))+"."+str(binario_a_decimal(combinacionesiptres)-1))
                    elif ultimo[1].split(".")[0] == combinacionesipuno and ultimo[1].split(".")[2] == combinacionesiptres:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos)-1)+"."+str(binario_a_decimal(combinacionesiptres)))
                    elif ultimo[1].split(".")[1] == combinacionesipdos and ultimo[1].split(".")[2] == combinacionesiptres:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+"."+str(binario_a_decimal(combinacionesipdos))+"."+str(binario_a_decimal(combinacionesiptres)))
                    elif combinacionesipdos.find("1") == -1:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+".255.255")    
                    else:
                        if combinacionesipuno.find("1") == -1:
                            ultimo.append(str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos)-1)+".255")
                        else:
                            ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+"."+str(binario_a_decimal(combinacionesipdos)-1)+".255")
                    """
                    elif ultimo[1].split(".")[0] == combinacionesipuno:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos)-1)+"."+str(binario_a_decimal(combinacionesiptres)-1))
                    elif ultimo[1].split(".")[1] == combinacionesipdos:
                        ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+"."+str(binario_a_decimal(combinacionesipdos))+"."+str(binario_a_decimal(combinacionesiptres)-1))
                    elif ultimo[1].split(".")[2] == combinacionesiptres :
                        ultimo.append(str(binario_a_decimal(combinacionesipuno)-1)+"."+str(binario_a_decimal(combinacionesipdos)-1)+"."+str(binario_a_decimal(combinacionesiptres)-1))
                    else:
                    """
                    
                        
                listasegmentos.append(ultimo)
                ultimo = [ipsplit[0],combinacionesipuno+"."+combinacionesipdos+"."+combinacionesiptres,str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos))+"."+str(binario_a_decimal(combinacionesiptres))]
            else:
                ultimo = [ipsplit[0],combinacionesipuno+"."+combinacionesipdos+"."+combinacionesiptres,str(binario_a_decimal(combinacionesipuno))+"."+str(binario_a_decimal(combinacionesipdos))+"."+str(binario_a_decimal(combinacionesiptres))]
                ban = True
        ultimo.append("255.255.255")
        listasegmentos.append(ultimo)

    return listasegmentos



def aux_binario(decimal):
    binario = 0
    i = 0
    while (decimal>0):
        digito  = decimal%2
        decimal = int(decimal//2)
        binario = binario+digito*(10**i)
        i = i+1

    return binario

def binario_a_decimal(binario):
    posicion = 0
    decimal = 0
    # Invertir la cadena porque debemos recorrerla de derecha a izquierda
    binario = binario[::-1]
    for digito in binario:
        # Elevar 2 a la posición actual
        multiplicador = 2**posicion
        decimal += int(digito) * multiplicador
        posicion += 1
    return decimal

def getbinario(bitsprestados,clase):
    bitsdisp = {"A":24,"B":16,"C":8}
    listabinario = []
    maxdecimal = pow(2,bitsprestados)
    #print(maxdecimal)
    binario = 0
    i = 0
    for numdecimal in range(maxdecimal):
        decimal = numdecimal
        aux__binario = str(aux_binario(decimal))
        for ceros in range(bitsprestados-len(aux__binario)):
            aux__binario = "0"+aux__binario     
        
        for ceros in range(bitsdisp[clase]-len(aux__binario)):
            aux__binario = aux__binario+"0"
        
        listabinario.append(aux__binario)
    return listabinario

def mascara_bits(mascarared,bitsprestados):
    mascara_redbits = ""
    mascarasubredbits = ""
    auxmascarasubredbits = ""
    mascarasubred = ""
    
    
    for porcionmasrcara in mascarared.split("."):
        aux__binario = str(aux_binario(int(porcionmasrcara)))
        auxmascarasubredbits = ""
        if aux__binario.find("0") != -1:
            if bitsprestados >= 8:
                for unos in range(8):
                    auxmascarasubredbits += "1"
                
                mascarasubred += str(binario_a_decimal(auxmascarasubredbits))
                mascarasubred += "."
                mascarasubredbits += auxmascarasubredbits
                mascarasubredbits += "."
                bitsprestados-=8
            else:
                for unos in range(bitsprestados):
                    auxmascarasubredbits += "1"
                for ceros in range(8-bitsprestados):
                    auxmascarasubredbits += "0"    
                bitsprestados = 0                    
                mascarasubred += str(binario_a_decimal(auxmascarasubredbits))
                mascarasubred += "."
                mascarasubredbits += auxmascarasubredbits
                mascarasubredbits += "."
            for ceros in range(8-len(aux__binario)):
                aux__binario = "0"+aux__binario
            mascara_redbits+= aux__binario
            mascara_redbits+="."
        else:
            mascarasubredbits += aux__binario
            mascarasubredbits += "."
            mascarasubred += str(binario_a_decimal(aux__binario))
            mascarasubred += "."
            mascara_redbits+= aux__binario
            mascara_redbits+="."
    return mascara_redbits[0:-1],mascarasubredbits[0:-1],mascarasubred[0:-1]

def generar_rango_subredes(mascara_redbits,mascarasubredbits,bitsprestados):
    
    auxmascara_redbits2 = str(mascara_redbits.replace("11111111.","").replace(".",""))
    auxmascara_redbits = ""
    for pos in range(len(auxmascara_redbits2)):
        if pos <= bitsprestados:
            auxmascara_redbits+= '1'
        else:
            auxmascara_redbits+= '0'
    auxmascarasubredbits = mascarasubredbits.replace("11111111.","").replace(".","")
    #print(auxmascara_redbits,auxmascarasubredbits)
    auxresultado = ""
    #print(auxmascara_redbits,auxmascarasubredbits)
    auxmascara_redbits = auxmascara_redbits[::-1]
    auxmascarasubredbits = auxmascarasubredbits[::-1]
    
    for pos in range(len(auxmascarasubredbits)):
        if auxmascara_redbits[pos] == "1" and auxmascarasubredbits[pos] == "1":
            auxresultado+="1"
        else:
            auxresultado+="0"
    auxresultado=auxresultado.replace("1","").replace("0","1")
    return binario_a_decimal(auxresultado[::-1])+1





def get_info_basico(ip,numredes):

    numredes = int(numredes)
    dictclase = {
    "A" : (1,126,"255.0.0.0","1.0.0.0","126.0.0.0"),
    "B" : (128,191,"255.255.0.0","128.0.0.0","191.255.0.0"),
    "C" : (193,223,"255.255.255.0","192.0.0.0","223.255.255.0")
    }



    dictclaveprivada = {"A":["10.0.0.0","10.255.255.255"],"B":["172.16.0.0","172.31.255.255"], "C":["192.168.0.0","192.168.255.255"],}

    #ip = "8.0.0.0"
    #numredes = 6
    clase,mascara_red  = get_clase_mascara(ip,dictclase)
    bitsprestados = get_bits_prestados(numredes,clase)

    mascara_redbits,mascarasubredbits,mascarasubred = mascara_bits(mascara_red,bitsprestados)
    rango_subredes = generar_rango_subredes(mascara_redbits,mascarasubredbits,bitsprestados)

    info = {"ClaseIP" : clase,"MascaraRed" : mascara_red,"MascaraBits" : mascara_redbits,"BistPrestados" : bitsprestados,"MascaraSubRedBits" : mascarasubredbits,"MascaraSubRed" : mascarasubred,"RangoHost":rango_subredes}

    return info


def get_info_basico_tabla(ip,numredes):
    #ip = "8.0.0.0"
    #numredes = 6
    numredes = int(numredes)
    dictclase = {
    "A" : (1,126,"255.0.0.0","1.0.0.0","126.0.0.0"),
    "B" : (128,191,"255.255.0.0","128.0.0.0","191.255.0.0"),
    "C" : (193,223,"255.255.255.0","192.0.0.0","223.255.255.0")
    }



    dictclaveprivada = {"A":["10.0.0.0","10.255.255.255"],"B":["172.16.0.0","172.31.255.255"], "C":["192.168.0.0","192.168.255.255"],}

    
    clase,mascara_red  = get_clase_mascara(ip,dictclase)
    bitsprestados = get_bits_prestados(numredes,clase)

    mascara_redbits,mascarasubredbits,mascarasubred = mascara_bits(mascara_red,bitsprestados)
    rango_subredes = generar_rango_subredes(mascara_redbits,mascarasubredbits,bitsprestados)

    info = {"ClaseIP" : clase,"MascaraRed" : mascara_red,"MascaraBits" : mascara_redbits,"BistPrestados" : bitsprestados,"MascaraSubRedBits" : mascarasubredbits,"MascaraSubRed" : mascarasubred,"RangoHost":rango_subredes
            ,"Tabla": genera_tablasubeteo(clase,ip,bitsprestados)}

    return info



