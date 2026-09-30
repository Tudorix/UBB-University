class ValidatorDiscipline:
    
    def validareDiscilina(self, Disciplina):
        """ 
            Functie de validare pentru Disciplina
            @param Disciplina - Disciplina
        """
        erori = []
        
        if Disciplina.getID() < 0:
            erori.append("IdError")

        if Disciplina.getNume() == "":
            erori.append("NumeError")
        
        if Disciplina.getProfesor() == "":
            erori.append("ProfesorError")
        
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
        
    def validareCuvant(self, Cuvant):
        """ 
            Functie de validare pentru un Cuvant
            @param Cuvant - string
        """
        if Cuvant == "":
            raise Exception