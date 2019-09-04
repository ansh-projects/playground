import pygame
from pygame.locals import *

pygame.init()

pygame.init()
screen = pygame.display.set_mode((468, 60))
pygame.display.set_caption('Monkey Fever')
pygame.mouse.set_visible(True)

if not pygame.font: print('Warning, fonts disabled')
if not pygame.mixer: print('Warning, sound disabled')

i = 0
while(True):
    print(i)
    i = i+1
