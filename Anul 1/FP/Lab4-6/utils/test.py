from methods import *
from complex import *

def test_addAtTheEnd():
    """
        test function for the addAtTheEnd method
    """
    reset_list()
    complex_element = create_complex(7, 8)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    complex_element = create_complex(3,4)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    assert get_list() == [{'real': 7, 'imag': 8}, {'real': 3, 'imag': 4}]

def test_addAtIndex():
    """
        test function for the addAtIndex method
    """
    reset_list()
    complex_element = create_complex(7, 8)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    complex_element = create_complex(3,4)
    set_list(addAtIndex(lista_curenta=get_list(), item=complex_element, index = 0))
    assert get_list() == [{'real': 3, 'imag': 4}, {'real': 7, 'imag': 8}]

def test_replaceItem():
    """
        test function for the replace method
    """
    reset_list()
    complex_element = create_complex(7, 8)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    complex_element = create_complex(3,4)
    set_list(addAtIndex(lista_curenta=get_list(), item=complex_element, index = 0))
    complex_element_old = create_complex(3,4)
    complex_element_new = create_complex(6,6)
    set_list(replaceItem(lista_curenta=get_list(),oldItem=complex_element_old, newItem=complex_element_new))
    assert get_list() == [{'real': 6, 'imag': 6}, {'real': 7, 'imag': 8}]
    
def test_deleteIndex():
    """
        test function for the deleteAtIndex method
    """
    reset_list()
    complex_element = create_complex(7, 8)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    complex_element = create_complex(3,4)
    set_list(addAtIndex(lista_curenta=get_list(), item=complex_element, index = 0))
    set_list(deleteAtIndex(lista_curenta=get_list(),index = 0))
    assert get_list() == [{'real': 7, 'imag': 8}]

def test_deleteInterval():
    """
        test function for the deleteInterval method
    """
    reset_list()
    complex_element = create_complex(7, 8)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    complex_element = create_complex(3,4)
    set_list(addAtIndex(lista_curenta=get_list(), item=complex_element, index = 0))
    set_list(deleteInterval(lista_curenta=get_list(), indexS=0,indexF=1))
    assert get_list() == []

def test_isPrime():
    """
        test function for the isPrime method
    """
    assert isPrime(7)
    assert isPrime(2)
    assert not isPrime(1)
    assert not isPrime(4)

def test_filterPrimeNums():
    """
        test function for the filterPrimeNums method
    """
    reset_list()
    complex_element = create_complex(7, 8)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    complex_element = create_complex(4,4)
    set_list(addAtIndex(lista_curenta=get_list(), item=complex_element, index = 0))
    assert filterPrimeNums(get_list()) == [{'real': 4, 'imag': 4}]

def test_filterCondition():
    """
        test function for the filterCondition method
    """
    reset_list()
    complex_element = create_complex(7, 8)
    set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
    complex_element = create_complex(10,0)
    set_list(addAtIndex(lista_curenta=get_list(), item=complex_element, index = 0))
    assert filterCondition(lista_curenta=get_list(), case=2,number=10) == [{'real': 7, 'imag': 8}]
    
#Execution Block
def test_all():
    test_filterPrimeNums()
    test_isPrime()
    test_addAtTheEnd()
    test_addAtIndex()
    test_deleteIndex()
    test_deleteInterval()
    test_replaceItem()
    test_filterCondition()
    
test_all()