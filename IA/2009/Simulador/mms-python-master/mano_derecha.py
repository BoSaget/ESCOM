from turtle import Turtle
import API

while True:
    
    if API.wallRight() == False:
        API.turnRight()
        
    while API.wallFront() == True:
        API.turnLeft()
        
    API.moveForward()
            
    