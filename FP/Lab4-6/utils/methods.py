import math
from domain.complex import *
    
def addAtTheEnd(lista_curenta, item) -> list:
    """
    Adds the element "item" at end of "lista_curenta"
    lista_curenta - list
    item - string
    Return - modified dictionary
    """
    lista_curenta.append(item)
    return lista_curenta
    
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
    
def filterPrimeNums(lista_curenta) -> list:
        """
        Filteres out the elements with a prime whole number
        lista_curenta - dict
        lista - type = Lista
        """
        filtered_dict = []
        i = 0
        lim = get_list_len()
        while i < lim:
            if not isPrime(get_real(lista_curenta[i])):
                filtered_dict.append(lista_curenta[i])
            i += 1
                
        return filtered_dict
    
def filterCondition(lista_curenta, case, number):
        """
        Filteres out the elements that are <,=,> that a given number
        lista_curenta - dict
        lista - type = Lista
        case - int
        number - int
        """
        filtered_dict = []
        i = 0
        lim = get_list_len()
        while i < lim:
            w = get_real(lista_curenta[i])
            z = get_imag(lista_curenta[i]) 

            absVal = math.sqrt(pow(w , 2) + pow(z , 2))
            if (case == 1 and absVal >= number) or (case == 2 and absVal != number) or (case == 3 and absVal <= number):
                filtered_dict.append(lista_curenta[i])
            i += 1
                
        return filtered_dict
    
def makeMult(start, fin):
    num1 = get_list()[start]
    r1 = get_real(num1)
    i1 = get_real(num1)
    multiplier = []
    for i in range(start + 1 , fin + 1):
        num2 = get_list()[i]
        r2 = get_real(num2)
        i2 = get_imag(num2)
                        
        whole = (r1 * r2 - i1 * i2)
        imaginary = (r1 * i2 + r2 * i1)

        multiplier = [whole, imaginary]
    return multiplier
    
def addAtIndex(lista_curenta, item , index) -> list:
        """
        Adds the element "item" at the position "index" in "lista_curenta"
        lista_curenta - list
        index - int
        item - string
        Return - modified dictionary
        """
        items = lista_curenta
        items.insert(index ,item)
        return items
    
def deleteAtIndex(lista_curenta, index) -> list:
        """
        Deletes the element from "lista_curenta" that has the index "index"
        lista_curenta - list
        index - int
        Return - modified dictionary
        """
        items = lista_curenta
        del items[index]
        return items
    
def deleteInterval(lista_curenta, indexS , indexF) -> list:
        """
        Deletes the elements from "lista_curenta" that have the index starting from "indexS" to "indexF"
        lista_curenta - list
        indexS - int
        indexF - int
        Return - modified dictionary
        """
        items = lista_curenta
        del items[indexS : indexF + 1]
        return items
    
def replaceItem(lista_curenta, oldItem, newItem) -> list:
        """
        Replaces the elements from "lista_curenta" of valuea "oldItem" with the value "newValue"
        lista_curenta - dict
        oldItem - string
        newItem - string
        Return - modified dictionary
        """
        for k in lista_curenta:
            if get_imag(k) == get_imag(oldItem) and get_real(k) == get_real(oldItem):
                set_imag(k,get_imag(newItem))
                set_real(k,get_real(newItem))

        return lista_curenta   
