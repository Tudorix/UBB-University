import unittest

class TestDiscipline(unittest.TestCase):
    
    def __init__(self, serviceDiscipline):
        """ 
            Functie de initiere pentru modulul de teste alocat Disciplina
        """
        self.serviceDiscipline = serviceDiscipline
        self.tearDown()
        
    def test_fisier(self):
        """ 
            Functie care verifica daca fisierul se actualizeaza
        """
        self.serviceDiscipline.adauga_disciplina(12 , "Mate", "Stefan")
        lista = self.serviceDiscipline.get_discipline()
        
        self.assertTrue(len(lista) > 0)
        self.tearDown()
        
    def run_tests():
        suite = unittest.defaultTestLoader.loadTestsFromName("testDisciplina")
        unittest.TextTestRunner(verbosity=2).run(suite)
        
    def tearDown(self):
        """  
            Functie de resetare a testelor
        """
        self.serviceDiscipline.reset_list()
        
    def setUp(self):
        self.serviceDiscipline.adauga_disciplina(12 , "Mate", "Stefan")
        self.serviceDiscipline.adauga_disciplina(24 , "Info", "Daniela")
        
    def test_adauga_disciplina(self):
        """ 
            Functie de test pentru adauga_disciplina
        """
        self.setUp()
        self.assertTrue( self.serviceDiscipline.get_discipline()[0].getID() == 12 )
        self.assertTrue( self.serviceDiscipline.get_discipline()[0].getNume() == "Mate")
        self.assertTrue( self.serviceDiscipline.get_discipline()[0].getProfesor() == "Stefan")
        self.assertTrue( self.serviceDiscipline.get_discipline()[1].getID() == 24)
        self.assertTrue( self.serviceDiscipline.get_discipline()[1].getNume() == "Info")
        self.assertTrue( self.serviceDiscipline.get_discipline()[1].getProfesor() == "Daniela")
        self.tearDown()
        
    def test_update_disciplina(self):
        """ 
            Functie de test pentru update_disciplina
        """
        self.setUp()
        self.serviceDiscipline.update_disciplina(24,36, "FP","Gabi")
        self.assertTrue( self.serviceDiscipline.get_discipline()[1].getID() == 36)
        self.assertTrue( self.serviceDiscipline.get_discipline()[1].getNume() == "FP")
        self.assertTrue( self.serviceDiscipline.get_discipline()[1].getProfesor() == "Gabi")
        self.tearDown()
        
    def test_sterge_disciplina(self):
        """ 
            Functie de test pentru stergere_disciplina
        """
        self.setUp()
        self.serviceDiscipline.sterge_disciplina("12")
        self.assertTrue( self.serviceDiscipline.get_discipline()[0].getID() == 24)
        self.assertTrue( self.serviceDiscipline.get_discipline()[0].getNume() == "Info")
        self.assertTrue( self.serviceDiscipline.get_discipline()[0].getProfesor() == "Daniela")
        self.tearDown()
        
    def test_cauta_disciplina(self):
        """ 
            Functie de test pentru cauta_disciplina
        """
        self.setUp()
        argumente = ["ID" , 24]
        disciplina = self.serviceDiscipline.cautare_disciplina(argumente)[0]
        self.assertTrue( disciplina.getID() == 24)
        self.assertTrue( disciplina.getNume() == "Info")
        self.assertTrue( disciplina.getProfesor() == "Daniela")
        self.tearDown()
        
    def test_all(self):
        """ 
            Functie de test pentru toate functiile de test
        """
        self.test_adauga_disciplina()
        self.test_update_disciplina()
        self.test_sterge_disciplina()
        self.test_cauta_disciplina()
        self.test_fisier()
        
TestDiscipline.run_tests()