import math
from domain.complex import *
    
def addAtTheEnd(lista_curenta, args) -> list:
    if len(args) != 2 : raise ValueError
    x = checkNum(args[0])
    y = checkNum(args[1])
    lista_curenta.append(create_complex(x,y))
    update_stack()
    return lista_curenta

def deleteAtIndex(lista_curenta, args) -> list:
        if len(args) != 1 : raise ValueError
        items = lista_curenta
        index = checkNum(args[0])
        try:
            del items[index]
        except:
            raise ValueError

        update_stack()
        return items
    
def filterPrimeNums(lista_curenta, args) -> list:
        if len(args) != 0: raise ValueError
        
        filtered_dict = []
        i = 0
        lim = get_list_len()
        while i < lim:
            if not isPrime(get_real(lista_curenta[i])):
                filtered_dict.append(lista_curenta[i])
            i += 1
                
        print(filtered_dict)
        return lista_curenta

def checkNum(s):
    try:
        return int(s)
    except:
        raise ValueError
    
    
def isPrime(n):
        """
        Checks if a number is prime
        n - int
        """
        if n < 2: return False
        if n % 2 == 0 and n != 2: return False
        for i in range(3 , int(n/2) + 1):
            if n % i == 0:
                return False
        return True

def replaceItem(lista_curenta, args) -> list:
        if len(args) != 4: raise ValueError
        
        x = checkNum(args[0])
        y = checkNum(args[1])
        oldItem = create_complex(x , y)
        
        x = checkNum(args[2])
        y = checkNum(args[3])
        newItem = create_complex(x , y)
        
        for k in lista_curenta:
            if get_imag(k) == get_imag(oldItem) and get_real(k) == get_real(oldItem):
                set_imag(k,get_imag(newItem))
                set_real(k,get_real(newItem))

        update_stack()
        return lista_curenta   
