class SefPromotieDTO:
    
    def __init__(self , medie , nume):
        """
            Constructorul clasei SefPromotieDTO
            @param medie - float
            @param nume - string
        """
        self.__medie = medie
        self.__nume = nume
        
    def getNume(self):
        """
            Getter pentru Nume 
        """
        return self.__nume
    
    def getMedie(self):
        """
            Getter pentru Medie
        """
        return self.__medie
    
    def __str__(self):
        """
            Functie care schimba obiectul SefPromotieDTO sub forma unui string
        """
        return f"{self.__nume} : {self.__medie : .2f}"