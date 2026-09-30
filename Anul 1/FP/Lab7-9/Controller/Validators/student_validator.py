class ValidatorStudent:
    
    def validareStudent(self, Student):
        """ 
            Functie de validare pentru Student
            @param Student - Student
        """
        erori = []
        
        if Student.getID() < 0:
            erori.append("IdError")
            
        if Student.getVarsta() < 0:
            erori.append("AgeError")

        if Student.getNume() == "":
            erori.append("NumeError")

        if len(erori) > 0:
            raise erori
        
    def validareID(self, ID):
        """ 
            Functie de validare pentru ID
            @param ID - int
        """
        try:
            ID = int(ID)
        except:
            raise Exception
            
        if ID < 0:
            raise Exception
        
    def validareVarsta(self, Varsta):
        """ 
            Functie de validare pentru Varsta
            @param Varsta - int
        """
        try:
            Varsta = int(Varsta)
        except:
            raise Exception
            
        if Varsta < 0:
            raise Exception
        
    def validareCuvant(self, Cuvant):
        """ 
            Functie de validare pentru un Cuvant
            @param Cuvant - string
        """
        if Cuvant == "":
            raise Exception