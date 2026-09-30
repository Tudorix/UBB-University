class Nota:
    def __init__(self, Student, Disciplina, valoare, ID):
        """
            Constructorul clasei Student
            @param ID - int
            @param Student - Student
            @param Disciplina - Disciplina
            @param valoare - int
        """
        self.__ID = ID
        self.__student = Student
        self.__disciplina = Disciplina
        self.__valoare = valoare
        
    def getStudent(self):
        """
            Getter pentru Student
        """
        return self.__student
    
    def getID(self):
        """
            Getter pentru ID
        """
        return self.__ID
    
    def getDisciplina(self):
        """
            Getter pentru Disciplina
        """
        return self.__disciplina
    
    def getValoare(self):
        """
            Getter pentru Valoari
        """
        return self.__valoare
    
    def setStudent(self, student):
        """
            Setter pentru Student
        """
        self.__student = student
        
    def setID(self, id):
        """
            Setter pentru ID
        """
        self.__ID = id
        
    def setDisciplina(self, disciplina):
        """
            Setter pentru Disciplina
        """
        self.__disciplina = disciplina
        
    def setValoare(self, valoare):
        """
            Setter pentru Valoare
        """
        self.setValoare = valoare
        
    def __str__(self):
        """
            Functie care schimba obiectul Nota sub forma unui string
        """
        return f"({self.getID()} , {self.__student.getNume()} , {self.__disciplina.getNume()} , {self.__valoare})"