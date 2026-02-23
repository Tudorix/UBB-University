from Domain.student import Student
class StudentRepo:
    def __init__(self , fileName):
        """
            Constructorul clasei StudentRepo
        """
        self.__lista_studenti = []
        self.__fileName = fileName
        self.load_from_file()
        
    def getList(self):
        """ 
            Functie care returneaza lista de studenti
        """
        self.load_from_file()
        return self.__lista_studenti

    def lenght(self):
        """ 
            Functie care returneaza lungimea lista de studenti
        """
        return len(self.__lista_studenti)
        
    def rst(self):
        """
            Functie care reseteaza lista de studenti
        """
        self.__lista_studenti = []
        self.load_in_file()
        
    def exista_ID(self, ID):
        """
            Functie care verifica daca ID exista in lista
            @param ID - int
        """
        for e in self.__lista_studenti:
            if ID == e.getID():
                return True
        return False
    
    def get_by_id(self, ID):
        """
            Functie care returneaza student daca ID exista in lista
            @param ID - int
            Raise - IndexError 
        """
        for e in self.__lista_studenti:
            if ID == e.getID():
                return e
        raise IndexError
        
    def adauga_student(self , student):
        """
            Functie care adauga student in lista de studenti
            @param student - Student
            Raise - IndexError 
        """
        if self.exista_ID(student.getID()):
            raise IndexError
        else:
            self.__lista_studenti.append(student)
            self.load_in_file()
            
    #Recursiv
    def sterge_student(self , ID, i = 0):
        """
            Functie care sterge student din lista de studenti
            @param ID - string
            Raise - MemoryError 
        """
        if i == len(self.__lista_studenti):
            raise MemoryError
        
        if self.__lista_studenti[i].getID() == int(ID):
            del self.__lista_studenti[i]
            self.load_in_file()
        else:
            self.sterge_student(ID , i + 1)
        
    #Recursiv
    def update_student(self , ID, student , i = 0):
        """
            Functie care modifica un student din lista de studenti
            @param ID - string
            @param student - Student
            Raise - MemoryError 
        """
        if (self.exista_ID(student.getID()) and int(ID) != student.getID()) or i == len(self.__lista_studenti):
            raise MemoryError
        
        if self.__lista_studenti[i].getID() == int(ID):
            self.__lista_studenti[i] = student
            self.load_in_file()
        else:    
            self.update_student(ID , student , i + 1)
        
    def load_from_file(self):
        """  
            Functie care incarca informatii din fisier
        """
        with open(self.__fileName,"r") as f:
            #reset the list
            self.__lista_studenti.clear()
            #preluare informatii pe linii
            while True:
                line = f.readline()
                if line == "":
                    break;
                ID = int(line.strip())
                line = f.readline()
                Nume = line.strip()
                line = f.readline()
                Varsta = int(line)
                student = Student(ID , Nume , Varsta)
                self.__lista_studenti.append(student)
        
    def load_in_file(self):
        """  
            Functie care incarca informatii in fisier
        """
        with open(self.__fileName , "w") as f:
            for i in self.__lista_studenti:
                f.writelines(f"{i.getID()}\n{i.getNume()}\n{i.getVarsta()}\n")