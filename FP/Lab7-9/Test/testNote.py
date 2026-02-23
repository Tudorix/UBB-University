import unittest

class TestNote(unittest.TestCase):
    
    def __init__(self, serviceNote, serviceStudent, serviceDiscipline):
        """ 
            Functie de initiere pentru modulul de teste Note
        """
        self.serviceNote = serviceNote
        self.serviceStudenti = serviceStudent
        self.serviceDiscipline = serviceDiscipline
        self.tearDown()
        
    def run_tests():
        suite = unittest.defaultTestLoader.loadTestsFromName("testNote")
        unittest.TextTestRunner(verbosity=2).run(suite)
        
    def tearDown(self):
        """  
            Functie de resetare a testelor
        """
        self.serviceStudenti.reset_list()
        self.serviceNote.reset_list()
        self.serviceDiscipline.reset_list()
        
    def setUp(self):
        self.serviceStudenti.adauga_student(48 , "Tudor", 19)
        self.serviceStudenti.adauga_student(56 , "Dragos", 19)
        self.serviceStudenti.adauga_student(13 , "Adi", 19)
        
        self.serviceDiscipline.adauga_disciplina(12 , "Mate", "Stefan")
        
        self.serviceNote.adauga_nota(23 , 10, 48 , 12)
        self.serviceNote.adauga_nota(3 , 9, 56 , 12)
        self.serviceNote.adauga_nota(5 , 8, 13 , 12)
        self.serviceNote.adauga_nota(45 , 7, 48 , 12)
        
        self.serviceStudenti.adauga_student(1 , "Tudor", 19)
        self.serviceStudenti.adauga_student(2 , "Dragos", 19)
        self.serviceStudenti.adauga_student(3 , "Adi", 19)
        self.serviceStudenti.adauga_student(4 , "Guta", 19)
        self.serviceStudenti.adauga_student(5 , "Gaboru", 19)
        
        self.serviceDiscipline.adauga_disciplina(1 , "Mate", "Stefan")
        self.serviceDiscipline.adauga_disciplina(2 , "Info", "Daniela")

        self.serviceNote.adauga_nota(1 , 10, 1 , 1)
        self.serviceNote.adauga_nota(2 , 9 , 1 , 2)
        self.serviceNote.adauga_nota(3 , 10 , 1 , 2)
        
        self.serviceNote.adauga_nota(4 , 9, 2 , 1)
        self.serviceNote.adauga_nota(5 , 9, 2 , 2)
        self.serviceNote.adauga_nota(6 , 7, 2 , 2)
        
        self.serviceNote.adauga_nota(7 , 8, 3 , 1)
        self.serviceNote.adauga_nota(8 , 9, 3 , 2)
        self.serviceNote.adauga_nota(9 , 6, 3 , 2)
        
        self.serviceNote.adauga_nota(10 , 8, 4 , 2)
        self.serviceNote.adauga_nota(11, 10, 4 , 2)
        self.serviceNote.adauga_nota(12 , 10, 4 , 2)
        
        self.serviceNote.adauga_nota(20 , 6, 5 , 2)
        self.serviceNote.adauga_nota(14, 8, 5 , 2)
        self.serviceNote.adauga_nota(15, 7, 5 , 2)
        
    def test_fisier(self):
        """ 
            Functie care verifica daca fisierul se actualizeaza
        """
        self.setUp()
        lista = self.serviceNote.get_note()
        
        self.assertTrue(len(lista) > 0)
        self.tearDown()
        
    def test_adauga_nota(self):
        """ 
            Functie care verifica daca se adauga nota
        """
        self.setUp()

        self.assertTrue( self.serviceNote.get_note()[0].getStudent().getNume() == "Tudor")
        self.assertTrue( self.serviceNote.get_note()[0].getDisciplina().getNume() == "Mate")
        self.assertTrue( self.serviceNote.get_note()[0].getValoare() == 10)
        self.assertTrue( self.serviceNote.get_note()[0].getID() == 23)
        self.tearDown()
        
    def test_sterge_nota(self):
        """ 
            Functie care verifica daca se sterge nota
        """
        self.setUp()
        
        self.serviceNote.sterge_nota(23)
        
        self.assertTrue( self.serviceNote.get_note()[0].getStudent().getNume() == "Dragos")
        self.assertTrue( self.serviceNote.get_note()[0].getDisciplina().getNume() == "Mate")
        self.assertTrue( self.serviceNote.get_note()[0].getValoare() == 9)
        self.assertTrue( self.serviceNote.get_note()[0].getID() == 3)
        self.tearDown()
        
    def test_filt_nume_nota(self):
        """
            Test filt_nume_nota
        """
        self.setUp()
        
        lista = self.serviceNote.filtrare_nume_nota("Mate")
        
        for e in lista: print(e)
        
        self.assertTrue( lista[0].getStudent().getNume() == "Adi")
        self.assertTrue( lista[2].getStudent().getNume() == "Dragos")
        self.assertTrue( lista[4].getStudent().getNume() == "Tudor")
        self.tearDown()
        
    def test_filt_nota_nume(self):
        """
            Test filt_nota_nume
        """
        self.setUp()
    
        lista = self.serviceNote.filtrare_nota_nume("Mate")
        
        for e in lista: print(e)
        
        self.assertTrue( lista[4].getStudent().getNume() == "Adi")
        self.assertTrue( lista[3].getStudent().getNume() == "Dragos")
        self.assertTrue( lista[0].getStudent().getNume() == "Tudor")
        
        self.tearDown()
        
    def test_filt_20(self):
        """
            Test filt_20
        """
        self.setUp()
        
        lista = self.serviceNote.filtrare_20()
        
        self.assertTrue( lista[0].getNume() == "Tudor")
        self.assertTrue( not len(lista) == 2)
        self.tearDown()
            
    
    def test_all(self):
        """ 
            Functie de test pentru toate functiile de test
        """
        self.test_adauga_nota()
        self.test_sterge_nota()
        self.test_filt_nume_nota()
        self.test_filt_20()
        self.test_filt_nota_nume()
        self.test_fisier()

TestNote.run_tests()