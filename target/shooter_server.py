import PodSixNet.Channel
import PodSixNet.Server
from time import sleep
import pygame
import random

class ClientChannel(PodSixNet.Channel.Channel):
    "client channel"
    def __init__(self, *args, **kwargs):
        PodSixNet.Channel.Channel.__init__(self, *args, **kwargs)
        # points of the player
        self.points = 0

    def Network(self, data):
        print data, self.gameid

    def Close(self):
        self._server.close()
        print self, self.gameid, 'client disconnected'
		# send to all other clients the information about score
        
class GameServer(PodSixNet.Server.Server):
    "game server"
    channelClass = ClientChannel
    def SendToAll(self, data):
        [p.Send(data) for p in self.players]

    def __init__(self, *args, **kwargs):
        PodSixNet.Server.Server.__init__(self, *args, **kwargs)
        self.games = []
        self.queue = None
        self.currentindex = 0
        # rects of the players' bars
        self.rects = (pygame.Rect(10, 260, 8, 80), pygame.Rect(985, 260, 8, 80))
		# players
        self.players = []

		# adresse and port at which server is started
        adresse, port = kwargs['localaddr']
        print 'Server started at', adresse, 'at port', str(port)
        print 'Now you can start the clients'

    def Connected(self, channel, addr):
        print 'player joined on:', channel
        # server checks if there is a game in the queue
        if self.queue == None:
            self.currentindex += 1
            channel.gameid = self.currentindex
            self.queue = Game(channel, self.currentindex)
        # else, create new game and add to queue
        else:
            channel.gameid = self.currentindex
            self.queue.player1 = channel
            self.queue.player0.Send({"action": "startgame", "player": 0, "gameid": self.queue.gameid})
            self.queue.player1.Send({"action": "startgame", "player": 1, "gameid": self.queue.gameid})
            self.games.append(self.queue)
            self.queue = None

class Game:
    def __init__(self, player0, currentindex):
        #inits the players
        self.player0 = player0
        self.player1 = None
        self.gameid = currentindex

address = raw_input("Host:Port (localhost:8000): ")

if not address:
    host, port = "localhost", 8000

else:
    host, port = address.split(":")

server = GameServer(localaddr=(host, int(port)))
while True:
    server.Pump()
    sleep(0.01)
