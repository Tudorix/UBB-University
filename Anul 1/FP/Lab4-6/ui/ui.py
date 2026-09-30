from utils.methods import *
from domain.complex import *

def run():
    print_initial()
    running = True
    stack_index = 0
    
    reset_list()
    
    while running :
        print_menu()
        option = getNumber(">>>")
        
        match option:
            case 1:
                print(get_list())
            case 2:
                update_stack()

                x = getNumber("Real : ")
                y = getNumber("Imag : ")
                complex_element = create_complex(x, y)
                set_list(addAtTheEnd(lista_curenta=get_list(), item=complex_element))
            case 3:
                if len(get_list()) > 0:
                    update_stack()
                    x = getNumber("Real : ")
                    y = getNumber("Imag : ")
                    complex_element = create_complex(x, y)
                    
                    z = getIndex(0 , get_list_len())
                    set_list(addAtIndex(lista_curenta=get_list(),item=complex_element , index=z))
                else:
                    print("The list has no numbers currently")
            case 4:
                if get_list_len() > 0:
                    update_stack()
                    list_stack[stack_index] = get_list().copy()
                    stack_index += 1

                    y = getIndex(0 , get_list_len())
                    set_list(deleteAtIndex(lista_curenta=get_list(),index=y))
                else:
                    print("The list has no numbers currently")
            case 5:
                if get_list_len() > 0:
                    update_stack()
                    y = getIndex(0 , get_list_len())
                    z = getIndex(y , get_list_len())
                        
                    set_list(deleteInterval(lista_curenta=get_list(),indexS=y, indexF=z))
                else:
                    print("The list has no numbers currently")
            case 6:
                if get_list_len()  > 0:
                    update_stack()
                    x = getNumber("Old Real : ")
                    y = getNumber("Old Imag : ")
                    complex_element_old = create_complex(x, y)
                    
                    x = getNumber("New Real : ")
                    y = getNumber("New Imag : ")
                    complex_element_new = create_complex(x, y)
                    
                    set_list(replaceItem(lista_curenta=get_list(),oldItem=complex_element_old, newItem=complex_element_new))
                else:
                    print("The list has no numbers currently")
            case 7:
                if get_list_len() > 0:
                    y = getIndex(0, get_list_len())
                    z = getIndex(y, get_list_len())
                    print("Imaginary parts are:\n")
                    for i in range(y , z + 1):
                        print(get_imag(get_list()[i]))
                else:
                    print("The list has no numbers currently")
            case 8:
                if get_list_len() > 0:
                    for i in range(0 , get_list_len()):
                        w = get_real(get_list()[i])
                        z = get_imag(get_list()[i])

                        absVal = 0
                        absVal = math.sqrt(pow(w , 2) + pow(z , 2))

                        if absVal > 10:
                            print (get_list()[i])
                else:
                    print("The list has no numbers currently")
                   
            case 9:
                if get_list_len() > 0:
                    for i in range(0 , get_list_len()):
                        w = get_real(get_list()[i])
                        z = get_imag(get_list()[i])

                        absVal = 0
                        absVal = math.sqrt(pow(w , 2) + pow(z , 2))

                        if absVal == 10:
                            print (get_list()[i])
                else:
                    print("The list has no numbers currently")

            #Iteratie 2     
            case 10:
                if get_list_len() > 0:
                    y = getIndex(0, get_list_len())
                    z = getIndex(y, get_list_len())

                    sumW = 0
                    sumI = 0
                    for i in range(y , z + 1):
                        sumW += get_real(get_list()[i])
                        sumI += get_imag(get_list()[i])

                    print(f"\nThe sum is: {sumW} {sumI}i\n")
                else:
                    print("The list has no numbers currently")
            
            case 11:
                if get_list_len() > 0:
                    y = getIndex(0, get_list_len())
                    z = getIndex(y, get_list_len())
                    multiplier = makeMult(y,z)
                    print(f"\nThe multiplication is: {multiplier}\n")
                else:
                    print("The list has no numbers currently")
            case 12:
                if get_list_len() > 0:
                    list_to_sort = get_list().copy()
                    
                    for i in range(y , z):
                        for j in range(i , z + 1):
                            elem1 = list_to_sort[i]
                            elem2 = list_to_sort[j]
                            if get_imag(elem1) < get_imag(elem2):
                                list_to_sort[i], list_to_sort[j] = list_to_sort[j], list_to_sort[i]

                    print(f"\n{list_to_sort}\n")
                else:
                    print("The list has no numbers currently")
            case 13:
                filtered_list = filterPrimeNums(lista_curenta=get_list())
                print(f"\n{filtered_list}\n")
            case 14:
                x = getCase()
                y = getNumber("What should it be compared to :")
                filtered_list = filterCondition(lista_curenta=get_list() , case=x, number=y)
                print(f"\n{filtered_list}\n")
            #Iteratie 3
            case 15:
                undo()
                print("Undo successful!")
            case 0:
                running = False
            case _:
                print("Unknown command")

    print_exit()

def print_initial():
    """
    Prints the introduction message of the app
    """
    print("Welcome to your Complex Numbers Editor Program(C.N.E.P) \n" \
    "What do you want to do today?")
        
def print_exit():
    """
    Prints the end message of the app
    """
    print("Have a nice day!")

def print_menu():
    """
    Prints the menu of the app
    """
    print("1. Show list")
    print("2. Add element at the end of list")
    print("3. Add element at a specified index")
    print("4. Delete element at a specified index")
    print("5. Delete element from a specified range")
    print("6. Replace elements with a specified value")
    print("7. Show the imaginary part of specified range")
    print("8. Show the numbers with the abs value greater than 10")
    print("9. Show the numbers with the abs value is equal to 10")
    print("10. Show the sum of the numbers in the range")
    print("11. Show the multiplication of the numbers in the range")
    print("12. Show a sorted range of numbers")
    print("13. Filter out all numbers with a real prime number")
    print("14. Filter out all numbers that have the absolute value <,=,> that another number")
    print("15. Undo")
    print("0. Close app")

def getComplexNumber():
    correct = False
    x = 0
    while not correct:
        correct = True
        x = input("Insert a complex number : ")
        x = x.split()
        if len(x) != 2: 
            correct = False
            print("The input was incorrect")
        else:
            try:
                x[0] = int(x[0])
                x[1] = int(x[1])
            except:
                correct = False
                print("The input was incorrect")

    return x

def getNumber(msg):
    correct = False
    x = 0
    while not correct:
        correct = True
        x = input(msg)
        try:
            x = int(x)
        except:
            correct = False
            print("The input was incorrect")

    return x

def getCase():
    correct = False
    x = 0
    while not correct:
        correct = True
        x = input("How should the number be? (< ; = ; >) :")
        if x != ">" and x != "=" and x != "<": 
            correct = False
            print("The input was incorrect")
        else:
            match x:
                case "<": x = 1
                case "=": x = 2
                case ">": x = 3

    return x

def getIndex(start , fin):
    correct = False
    x = 0
    while not correct:
        correct = True
        x = input("Insert a index number : ")
        try:
            x = int(x)
            if x > fin or x < start:
                correct = False
                print("The input was incorrect")
        except:
            correct = False
            print("The input was incorrect")

    return x