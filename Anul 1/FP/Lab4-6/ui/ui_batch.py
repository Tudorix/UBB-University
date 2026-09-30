from utils.methods_batch import *
from domain.complex import *

commands = {
    "Add" : addAtTheEnd,
    "Del" : deleteAtIndex,
    "Fil" : filterPrimeNums,
    "Rep" : replaceItem,
    "Undo" : undo_batch
}

def run_batch():
    print_initial()
    running = True
    stack_index = 0
    
    reset_list()
    
    while running :
        option = input(">>>")
        
        com = option.split(";")
        
        for i in range(0 , len(com)):
            com[i] = com[i].strip()
            s = com[i].split(" ")
            
            if s[0] == "Exit":
                running = False
                break
            
            if s[0] not in commands:
                print(f"CommandError ({com[i]}) : Invalid command")
                continue
            
            arguments = s[1:]

            try:
                set_list(commands[s[0]](get_list(),arguments))
                print(list_stack)
            except ValueError:
                print("Something went wrong")
                   
        print(get_list())
         

    print_exit()

def print_initial():
    """
    Prints the introduction message of the app
    """
    print("Welcome to your Complex Numbers Editor BATCH Mode \n")

def print_exit():
    """
    Prints the end message of the app
    """
    print("Have a nice day!")

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