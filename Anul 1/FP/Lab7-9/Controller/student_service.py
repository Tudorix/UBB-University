from Domain.student import Student
import random
import string

class ServiceStudent:
    def __init__(self, ValidatorStudent, RepoStudent):
        """
            Constructorul clasei ServiceStudent
            @param ValidatorStudent - ValidatorStudent
            @param RepoStudent - StudentRepo
        """
        self.__validatorStudent = ValidatorStudent
        self.__repoStudent = RepoStudent
        
    def lenght(self):
        """ 
            Functie care returneaza lungimea listei de studenti
        """
        return self.__repoStudent.lenght()
        
    def cautare_student(self, args):
        """ 
            Functie care cauta un student
            @param args - lista
            Raise - Exeption
        """
        if len(args) != 2:
            raise Exception
        
        case = 0
        
        if args[0] == "ID" : 
            case = 1
            try:
                self.__validatorStudent.validareID(args[1])
            except:
                raise Exception
        elif args[0] == "Nume" :
            case = 2
            try:
                self.__validatorStudent.validareCuvant(args[1])
            except:
                raise Exception
        elif args[0] == "Varsta" : 
            case = 3
            try:
                self.__validatorStudent.validareVarsta(args[1])
            except:
                raise Exception
        else : raise Exception
        
        lista = self.get_studenti()
        lista_filtrata = []
        
        for e in self.get_studenti():
            if (case == 1 and e.getID() == int(args[1])) or (case == 2 and e.getNume() == args[1]) or (case == 3 and e.getVarsta() == int(args[1])):
                lista_filtrata.append(e)
        
        return lista_filtrata
    
    def gen_studenti(self , nr):
        while nr > 0:
            varsta = random.randint(18 , 30)
            id = random.randint(0 , 100)
            
            k = random.randint(6,12)
            letters = string.ascii_letters
            alg = ""
            for i in range(0 ,k):
                alg += random.choice(letters)
            nume = ""
            nume = nume.join(alg)
            
            student = Student(id , nume , varsta)
            
            try:
                self.__validatorStudent.validareStudent(student)
                if not self.__repoStudent.exista_ID(student.getID()):
                    nr -= 1
                    self.__repoStudent.adauga_student(student)
            except:
                pass
        
    def reset_list(self):
        """
            Functie care reseteaza lista de studenti
        """
        self.__repoStudent.rst()
        
        
    #Complexitatea este Theta(n) , n - lungimea listei de studenti
    def filt_varsta(self , varsta):
        """
        Functie care filtreaza studentii peste o anumita varsta
        
        :param varsta: int
        
        Raises:
            ValueError: daca varsta nu e un numar

        Returns:
            list : studentii care au varsta mai mare
        """
        
        try:
            self.__validatorStudent.validareVarsta(varsta)
        except:
            raise Exception
        
        lista_studenti = self.get_studenti()
        lista_filt = []
        
        for student in lista_studenti:
            if student.getVarsta() <= varsta:
                lista_filt.append(student)
                
        return lista_filt
        
    
    def adauga_student(self , idStudent, Nume, Varsta):
        """
            Functie care adauga student in lista de studenti
            @param idStudent - int
            @param Nume - string
            @param Varsta - int
            Raise - ValueError
        """
        student = Student(idStudent , Nume.strip(), Varsta)
        try:
            self.__validatorStudent.validareStudent(student)
        except:
            raise ValueError
        
        self.__repoStudent.adauga_student(student)
        
    def sterge_student(self,idStudent):
        """
            Functie care sterge student din lista de studenti
            @param idStudent - int
            Raise - ValueError
        """
        try:
            self.__validatorStudent.validareID(idStudent)
        except:
            raise ValueError
        
        self.__repoStudent.sterge_student(idStudent)
        
    def update_student(self,idStudent , newId , Nume, Varsta):
        """
            Functie care modifica student din lista de studenti
            @param ID - string
            @param newId - int
            @param Nume - string
            Raise - ValueError - Invalid Student
            Raise - IndexError - Invalid ID
        """
        student = Student(newId , Nume, Varsta)
        try:
            self.__validatorStudent.validareStudent(student)
        except:
            raise ValueError
        
        try:
            self.__validatorStudent.validareID(idStudent)
        except:
            raise IndexError
        
        self.__repoStudent.update_student(idStudent, student)
        
    def get_studenti(self):
        """ 
            Functie care returneza lista curenta de studenti
        """
        return self.__repoStudent.getList()