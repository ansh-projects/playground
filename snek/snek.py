"""
Shooter game
"""
# Import Modules
import sys
import os
import random
import pygame
from pygame.locals import *
import assets
from PodSixNet.Connection import ConnectionListener, connection
from time import sleep
ROPE_HEIGHT = [50, 150, 250]

class ShooterGame(ConnectionListener):

    def Network_startgame(self, data):
        self.running = True
        self.num = data["player"]
        self.gameid = data["gameid"]

#    def Network_oscore(self, data):
#        self.oscore = data['oscore']

    def __init__(self):
        "initallize"
        pygame.init()
        # window size
        address = raw_input("Address of Server: ")

        try:
            if not address:
                host, port = "localhost", 8000

            else:

                host, port = address.split(":")

            self.Connect((host, int(port)))
        except:
            print "Error Connecting to Server"
            sys.exit()
        print "shooter client started"
        self.clock = pygame.time.Clock()
        # clear the screan
        self.size = 1000, 500
        self.screen = pygame.display.set_mode(self.size)
        self.screen.fill(0)
        # title
        pygame.display.set_caption("Shooter")
        # icon
        self.icon = pygame.image.load('data/cur1.png')
        self.icon = pygame.transform.scale(self.icon, (32, 32))
        self.icon.convert()
        pygame.display.set_icon(self.icon)
        self.background = pygame.Surface(self.screen.get_size())
        self.background = self.background.convert()
        self.background.fill((250, 250, 250))
        self.initSound()
        pygame.mouse.set_visible(0)
        self.score = 0
        # scoreboard
        self.hud = pygame.Surface((1000, 100))
        self.hud = self.hud.convert()
        self.hud.fill((150, 150, 110))
        # size 32 font
        self.myfont32 = pygame.font.Font(None, 32)
        # size 20 font
        self.myfont20 = pygame.font.SysFont(None, 20)
        self.scoretextme = self.myfont20.render("You", 1, (10, 10, 10))
        self.scoretextother = self.myfont20.render(
            "Other Player", 1, (10, 10, 10))
        self.hud.blit(self.scoretextme, (10, 50))
        self.hud.blit(self.scoretextother, (900, 50))
        # Put Text On The Background, Centered
        self.font = pygame.font.Font(None, 36)
        self.text = self.font.render("Loading:", 1, (10, 10, 10))
        self.background.blit(self.text, (400, 200))
        # Display The Background
        self.screen.blit(self.background, (0, 0))
        pygame.display.flip()
        # initialize client
        self.oscore = None
        self.netscore = None
        self.gameid = None
        self.num = None
        self.spawn = 0
        self.scorekeeper = [0, 0, 0]
        # wait till game starts
        self.running = False
        ROPE1 = random.choice(ROPE_HEIGHT)
        ROPE2 = random.choice(ROPE_HEIGHT)
        ROPE3 = random.choice(ROPE_HEIGHT)
        while not self.running:
            self.Pump()
            connection.Pump()
            sleep(0.01)
        self.initCur()
        self.red = assets.RedTarget(ROPE1)
        self.green = assets.GreenTarget(ROPE2)
        self.purple = assets.PurpleTarget(ROPE3)
        self.blue = assets.BlueTarget(ROPE1)
        self.smiley = assets.Smiley(ROPE2)
        self.aim_one = assets.PlayerOne(self.cur2)
        self.aim_two = assets.PlayerTwo(self.cur2)
        self.alive_targets = pygame.sprite.Group()
        self.dead_targets = pygame.sprite.Group()
        self.cursors = pygame.sprite.Group()
        self.cursors.add(self.aim_one, self.aim_two)
        self.target_list = [self.red, self.blue, self.green, self.purple, self.smiley]
        self.alive_targets.add(self.red, self.blue,
                               self.green, self.purple, self.smiley)
        self.background.blit(assets.BackGround().image,
                             assets.BackGround().rect)

    def initCur(self):
        #determine attributes from player #
        if self.num == 0:
            self.turn = True
            self.cur1 = pygame.image.load('data/cur1.png')
            self.cur2 = pygame.image.load('data/cur2.png')
        else:
            self.cur1 = pygame.image.load('data/cur2.png')
            self.cur2 = pygame.image.load('data/cur1.png')

    def initSound(self):
        pygame.mixer.music.load("data/music.wav")
        #self.winSound = pygame.mixer.Sound('win.wav')
        #self.loseSound = pygame.mixer.Sound('lose.wav')
        self.hit_sound = pygame.mixer.Sound('data/hit.wav')
        self.shot_sound = pygame.mixer.Sound('data/shot.wav')
        pygame.mixer.music.play(-1)

    def update(self):
        #"pumps" information, listens for new events/messages
        connection.Pump()
        self.Pump()
        # runs every frame to update game
        # set to 60fps
        self.clock.tick(60)
        self.oldscore = self.score
        # Handle Input events
        for event in pygame.event.get():
            if event.type == QUIT:
                print "Game Over"
                sys.exit(0)
            elif event.type == KEYDOWN and event.key == K_ESCAPE:
                print "Game Over"
                sys.exit(0)
            elif event.type == MOUSEBUTTONDOWN:
                self.shot_sound.play()
                self.Send({"action": "click", "point": event.pos, "num": self.num, "gameid": self.gameid})
                if self.aim_one.rect.colliderect(self.red.rect):
                    self.red.shot()
                    pygame.time.wait(25)
                    self.alive_targets.remove(self.red)
                    if self.red not in self.alive_targets:
                        self.hit_sound.play()
                        self.score += 1
                        if self.num == 0:
                            self.scorekeeper = [self.oscore, self.score, self.num]
                        else:
                            self.scorekeeper = [self.score, self.oscore, self.num]
                        self.Send({"action": "scorekeeper", "scorekeeper": self.scorekeeper})
                if self.aim_one.rect.colliderect(self.blue.rect):
                    self.blue.shot()
                    pygame.time.wait(25)
                    self.alive_targets.remove(self.blue)
                    if self.blue not in self.alive_targets:
                        self.hit_sound.play()
                        self.score += 2
                        if self.num == 0:
                            self.scorekeeper = [self.oscore, self.score, self.num]
                        else:
                            self.scorekeeper = [self.score, self.oscore, self.num]
                        self.Send({"action": "scorekeeper", "scorekeeper": self.scorekeeper})
                if self.aim_one.rect.colliderect(self.green.rect):
                    self.green.shot()
                    pygame.time.wait(25)
                    self.alive_targets.remove(self.green)
                    if self.red not in self.alive_targets:
                        self.hit_sound.play()
                        self.score += 3
                        if self.num == 0:
                            self.scorekeeper = [self.oscore, self.score, self.num]
                        else:
                            self.scorekeeper = [self.score, self.oscore, self.num]
                        self.Send({"action": "scorekeeper", "scorekeeper": self.scorekeeper})
                if self.aim_one.rect.colliderect(self.purple.rect):
                    self.purple.shot()
                    pygame.time.wait(25)
                    self.alive_targets.remove(self.purple)
                    if self.purple not in self.alive_targets:
                        self.hit_sound.play()
                        self.score += 5
                        if self.num == 0:
                            self.scorekeeper = [self.oscore, self.score, self.num]
                        else:
                            self.scorekeeper = [self.score, self.oscore, self.num]
                        self.Send({"action": "scorekeeper", "scorekeeper": self.scorekeeper})
                if self.aim_one.rect.colliderect(self.smiley.collideRect):
                    self.smiley.shot()
                    pygame.time.wait(25)
                    self.alive_targets.remove(self.smiley)
                    if self.smiley not in self.alive_targets:
                        self.hit_sound.play()
                        self.score -= 10
                        if self.num == 0:
                            self.scorekeeper = [self.oscore, self.score, self.num]
                        else:
                            self.scorekeeper = [self.score, self.oscore, self.num]
                        self.Send({"action": "scorekeeper", "scorekeeper": self.scorekeeper})
            elif event.type is MOUSEBUTTONUP:
                self.aim_one.unshoot()
        if self.score != self.oldscore:
            print self.score

        self.cursors.update()
        self.alive_targets.update()
        self.dead_targets.update()
        # Draw Everything
        # clear screen
        self.screen.blit(self.background, (0, 0))
        self.screen.blit(self.hud, (0, 400))
        self.cursors.draw(self.screen)
        self.alive_targets.draw(self.screen)

        if len(self.alive_targets) == 0 or len(self.alive_targets) == 1 and self.alive_targets.has(self.smiley):
            if self.spawn != 3:
                if not self.alive_targets.has(self.smiley):
                    self.alive_targets.add(self.smiley)
                self.alive_targets.add(random.choice(self.target_list), random.choice(self.target_list), random.choice(self.target_list), random.choice(self.target_list), random.choice(self.target_list), random.choice(self.target_list))
                self.spawn += 1
                print "spawn: ", self.spawn
            else:
                print "Game Over"
                print "score: ", self.score
                sys.exit(0)
        # update the screen
        self.screen.blit(self.font.render(str(self.score), True, (0, 255, 0)), (50, 450))
        self.screen.blit(self.font.render(str(self.oscore), True, (255, 0, 0)), (850, 450))
        pygame.display.flip()

SG = ShooterGame()
while(1):
    SG.update()
