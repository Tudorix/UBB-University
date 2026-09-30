from ui.ui import *
from ui.ui_batch import *

def main():
    x = input("1 -> Menu Mode \n2 -> Batch Mode\n>>> ")
    
    if(x == "1"):
        run()
    else:
        run_batch()
    
main()