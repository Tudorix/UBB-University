### PROSTIA OMENEASCA

context variable for parameters

main.py

`from test import rulare_test`
`from ui import run`

`def main():`
	`rulare_test()`
	 `run()`

`main()`




test.py

`def rulare_test():`
	`pass`




ui.py

comenzi = {"nume_functie" : functie}

def functie(context):
	pass

`def run():`
	campionat = []
	 while true:
		 text_cmd = input(">>>")
		 text_cmd = text_cmd.strip()
		 if text_cmd == "":
			 continue
			
		 if text_cmd == "exit":
			 return
			
		parti_cmd = text_cmd.split()


