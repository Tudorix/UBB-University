class ValidatorNota:
    
    def validareNota(self, Nota):
        """ 
            Functie de validare pentru Nota
            @param Nota - Nota
        """
        erori = []
        
        if Nota.getValoare() < 0 or Nota.getValoare() > 10:
            erori.append("ValoareError")
        if Nota.getID() < 0:
            erori.append("IdError")
        
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