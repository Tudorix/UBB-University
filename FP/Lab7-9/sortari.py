
class Sort:
    
    def BubbleSort(lista , key , cmp,key_aux = None):
        check = False
        while not check:
            check = True
            for i in range(0 , len(lista) - 1):
                if cmp(key(lista[i]) , key(lista[i + 1])):
                    lista[i], lista[i + 1] = lista[i + 1] , lista[i]
                    check = False
                elif key(lista[i]) == key(lista[i + 1]):
                    if key_aux(lista[i]) < key_aux(lista[i + 1]):
                        lista[i], lista[i + 1] = lista[i + 1] , lista[i]
                        check = False
                    
        return lista
    
    def ShellSort(lista, key):
        #Initial Gap
        n = len(lista)
        gap = n // 2
        
        while gap > 0:
            
            for i in range(gap , n):
                temp = lista[i]
                j = i
                while j >= gap and key(lista[j - gap]) < key(temp):
                    lista[j] = lista[j - gap]
                    j -= gap
                    
                lista[j] = temp
                
            gap //= 2
        
        return lista