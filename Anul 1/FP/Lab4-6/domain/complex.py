lista_numere = []
list_stack = [[]]

def create_complex(real, imag):
    """
    Creeaza elementul complex
    """
    return {"real": real, "imag": imag}

def reset_list():
    """
    Goleste lista de numere complexe
    """
    set_list([])
    list_stack = [[]]
    
def set_list(val):
    """
    Seteaza lista de numere complexe
    """
    global lista_numere
    lista_numere = val
    
def update_stack():
    """
    Updateaza stiva de liste de numere complexe
    param: val - list
    """
    list_stack.append(get_list().copy())
    
def undo():
    """
    Seteaza lista de numere la ultima valoare din stiva
    """
    global lista_numere
    lista_numere = list_stack.pop()
    
def undo_batch(lista_curenta, args):
    """
    Seteaza lista de numere la ultima valoare din stiva
    """
    if len(args) != 0: raise ValueError
    if len(list_stack) > 0:
        return list_stack.pop()
    return []
    
def get_list():
    """
    Returneaza lista de numere complexe
    """
    return lista_numere

def get_list_len():
    """
    Returneaza lungimea listei de numere complexe
    """
    return len(lista_numere)

def get_real(z):
    """
    Returnrneaza partea intreaga a elemntului complex
    @param z - dict
    """
    return z["real"]

def get_imag(z):
    """
    Returnrneaza partea imaginara a elemntului complex
    @param z - dict
    """
    return z["imag"]


def set_real(z, value):
   """
    Seteaza partea intreaga a elemntului complex
    @param z - dict
   """
   z["real"] = value

def set_imag(z, value):
    """
    Seteaza partea imaginara a elemntului complex
    @param z - dict
    """
    z["imag"] = value