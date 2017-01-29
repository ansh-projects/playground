import random
import time

number = random.randint(0, 50)
guess = -1
trycount = 8
isNum = False
win = False
input = " "

def is_Number(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

print "Guess a Number! Any Number! \n"
print "(from 0 to 50)"
while(guess != number and trycount > 0):
    input = raw_input("guess: ")
    while(isNum == False):
        if(not is_Number(input)):
            print "enter a number pls"
            input = raw_input("guess: ")
            if (is_Number(input)):
                break
        else:
            isNum = True

    guess = int(input)

    if(guess < number):
        print "Too low" 

    if (guess > number):
        print "Too high"

    trycount = trycount - 1

    if(trycount > 1):
        print "You have ", trycount, " guesses left!!" 
    elif(trycount == 1):
        print "You have ", trycount, " guess left!!"

if(guess==number):
    print "You guessed the number" 
    win = True
if (trycount == 0):
    print "You ran out of guesses :( "  

if(not win):
    print "The number was ", number, "! " 
    print "game over"  
else:
    print "gg"  
    
key = raw_input("press Q to quit \n")  

while(key != "q" and key != "Q"):
    key = raw_input()
