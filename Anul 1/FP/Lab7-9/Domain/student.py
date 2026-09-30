class Student:
    def __init__(self, ID, Nume, Varsta):
        """
            Constructorul clasei Student
            @param ID - int
            @param Nume - string
        """
        self.__ID = ID
        self.__Nume = Nume
        self.__Varsta = Varsta
        
    def __str__(self):
        """
            Functie care schimba obiectul Student sub forma unui string
        """
        return f"({self.__ID} , {self.__Nume} , {self.__Varsta})"
    
    def __repr__(self):
        """
            Functie care schimba reprezentarea obiectului Student sub forma unui string
        """
        return str(self)
    
    def getNume(self):
        """
            Getter pentru Nume Studnet
        """
        return self.__Nume
    
    def getID(self):
        """
            Getter pentru ID Studnet
        """
        return self.__ID
    
    def getVarsta(self):
        """
            Getter pentru Varsta Studnet
        """
        return self.__Varsta
    
    def setNume(self, name):
        """
            Setter pentru Nume Studnet
            @param name - string
        """
        self.__Nume = name
    
    def setID(self, id):
        """
            Setter pentru ID Studnet
            @param id - int
        """
        self.__ID = id
        
    def setVarsta(self, Varsta):
        """
            Setter pentru Varsta Studnet
            @param Varsta - int
        """
        self.__Varsta = Varsta