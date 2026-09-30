class Disciplina:
    
    def __init__(self, ID , Nume, Profesor):
        """
            Constructorul clasei Student
            @param ID - int
            @param Nume - string
            @param Profesor - string
        """
        self.__ID = ID
        self.__Nume = Nume
        self.__Profesor = Profesor
        
    def getID(self):
        """
            Getter pentru ID Disciplina
        """
        return self.__ID
    
    def getNume(self):
        """
            Getter pentru Nume Disciplina
        """
        return self.__Nume
    
    def getProfesor(self):
        """
            Getter pentru Profesor Disciplina
        """
        return self.__Profesor
    
    def setID(self, id):
        """
            Setter pentru ID Disciplina
            @param id - int
        """
        self.__ID = id
    
    def setNume(self, nume):
        """
            Setter pentru Nume Disciplina
            @param Nume - string
        """
        self.__Nume = nume
    
    def setProfesor(self, profesor):
        """
            Setter pentru Profesor Disciplina
            @param Profesor - string
        """
        self.__Profesor = profesor
        
    def __str__(self):
        """
            Functie care schimba obiectul Disciplina sub forma unui string
        """
        return f"({self.__ID} , {self.__Nume} , {self.__Profesor})"
    
    def __repr__(self):
        """
            Functie care schimba reprezentarea obiectului Disciplina sub forma unui string
        """
        return str(self)