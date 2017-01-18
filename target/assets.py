import pygame
import random
# print height

class BackGround(pygame.sprite.Sprite):
    """ background image """

    def __init__(self):
        self.image = pygame.image.load('data/bg.png')
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = [0, 0]

class PlayerOne(pygame.sprite.Sprite):
    """moves a cursos on the screen, following the mouse"""

    def __init__(self, cur):
        pygame.sprite.Sprite.__init__(self)  # call Sprite initializer
        self.image = cur
        self.image = pygame.transform.scale(self.image, (50, 50))
        self.rect = self.image.get_rect()
        self.shooting = 0

    def update(self):
        "move based on mouse position"
        pos = pygame.mouse.get_pos()
        self.rect.midtop = pos
        if self.shooting:
            self.rect.move_ip(10, 25)

    def shoot(self, target):
        "returns true if the cursor collides with the target"
        if not self.shooting:
            self.shooting = 2
            hitbox = self.rect.inflate(-5, -5)
            return hitbox.colliderect(target.rect)

    def unshoot(self):
        "recoil down"
        self.shooting = 0

class PlayerTwo(pygame.sprite.Sprite):
    """moves player two cursor on the screen, following the mouse"""

    def __init__(self, cur):
        pygame.sprite.Sprite.__init__(self)  # call Sprite initializer
        self.image = cur
        self.image = pygame.transform.scale(self.image, (50, 50))
        self.rect = self.image.get_rect()
        self.shooting = 0

    def update(self):
        "move based on mouse position"
        pos = pygame.mouse.get_pos()
        self.rect.midtop = pos
        if self.shooting:
            self.rect.move_ip(10, 25)

    def shoot(self, target):
        "returns true if the cursor collides with the target"
        if not self.shooting:
            self.shooting = 2
            hitbox = self.rect.inflate(-5, -5)
            return hitbox.colliderect(target.rect)

    def unshoot(self):
        "recoil down"
        self.shooting = 0

class RedTarget(pygame.sprite.Sprite):
    """target moves across the screen. """

    def __init__(self, height):
        pygame.sprite.Sprite.__init__(self)  # call Sprite intializer
        self.image = pygame.image.load('data/redtarget.png')
        self.image = pygame.transform.scale(self.image, (100, 100))
        self.rect = self.image.get_rect()
        screen = pygame.display.get_surface()
        self.area = screen.get_rect()
        self.rect.topleft = 10, height
        self.move = 3
        self.rotate = 0

    def update(self):
        "walk or spin, depending on the targets state"
        if self.rotate:
            self._spin()
        else:
            self._walk()

    def _walk(self):
        "move the target across the screen, and turn at the ends"
        newpos = self.rect.move((self.move, 0))
        if self.alive():
            if self.rect.left < self.area.left or self.rect.right > self.area.right:
                self.move = -self.move
                newpos = self.rect.move((self.move, 0))
                self.image = pygame.transform.flip(self.image, 1, 0)
            self.rect = newpos

    def _spin(self):
        "spin the target"
        center = self.rect.center
        self.rotate = self.rotate + 12
        if self.rotate >= 360:
            self.rotate = 0
            self.image = self.original
        else:
            rotate = pygame.transform.rotate
            self.image = rotate(self.original, self.rotate)
        self.rect = self.image.get_rect(center=center)

    def shot(self):
        "this will cause the target to start spinning"
        if not self.rotate:
            self.rotate = 1
            self.original = self.image

class BlueTarget(pygame.sprite.Sprite):
    """target moves across the screen. """

    def __init__(self, height):
        pygame.sprite.Sprite.__init__(self)  # call Sprite intializer
        self.image = pygame.image.load('data/bluetarget.png')
        self.image = pygame.transform.scale(self.image, (100, 100))
        self.rect = self.image.get_rect()
        screen = pygame.display.get_surface()
        self.area = screen.get_rect()
        self.rect.topleft = 10, height
        self.move = 5
        self.rotate = 0

    def update(self):
        "walk or spin, depending on the targets state"
        if self.rotate:
            self._spin()
        else:
            self._walk()

    def _walk(self):
        "move the target across the screen, and turn at the ends"
        newpos = self.rect.move((self.move, 0))
        if self.rect.left < self.area.left or self.rect.right > self.area.right:
            self.move = -self.move
            newpos = self.rect.move((self.move, 0))
            self.image = pygame.transform.flip(self.image, 1, 0)
        self.rect = newpos

    def _spin(self):
        "spin the target"
        center = self.rect.center
        self.rotate = self.rotate + 12
        if self.rotate >= 360:
            self.rotate = 0
            self.image = self.original
        else:
            rotate = pygame.transform.rotate
            self.image = rotate(self.original, self.rotate)
        self.rect = self.image.get_rect(center=center)

    def shot(self):
        "this will cause the target to start spinning"
        if not self.rotate:
            self.rotate = 1
            self.original = self.image

class GreenTarget(pygame.sprite.Sprite):
    """target moves across the screen. """

    def __init__(self, height):
        pygame.sprite.Sprite.__init__(self)  # call Sprite intializer
        self.image = pygame.image.load('data/greentarget.png')
        self.image = pygame.transform.scale(self.image, (100, 100))
        self.rect = self.image.get_rect()
        screen = pygame.display.get_surface()
        self.area = screen.get_rect()
        self.rect.topleft = 10, height
        self.move = 10
        self.rotate = 0

    def update(self):
        "walk or spin, depending on the targets state"
        if self.rotate:
            self._spin()
        else:
            self._walk()

    def _walk(self):
        "move the target across the screen, and turn at the ends"
        newpos = self.rect.move((self.move, 0))
        if self.rect.left < self.area.left or self.rect.right > self.area.right:
            self.move = -self.move
            newpos = self.rect.move((self.move, 0))
            self.image = pygame.transform.flip(self.image, 1, 0)
        self.rect = newpos

    def _spin(self):
        "spin the target"
        center = self.rect.center
        self.rotate = self.rotate + 12
        if self.rotate >= 360:
            self.rotate = 0
            self.image = self.original
        else:
            rotate = pygame.transform.rotate
            self.image = rotate(self.original, self.rotate)
        self.rect = self.image.get_rect(center=center)

    def shot(self):
        "this will cause the target to start spinning"
        if not self.rotate:
            self.rotate = 1
            self.original = self.image

class PurpleTarget(pygame.sprite.Sprite):
    """target moves across the screen. """

    def __init__(self, height):
        pygame.sprite.Sprite.__init__(self)  # call Sprite intializer
        self.image = pygame.image.load('data/purpletarget.png')
        self.image = pygame.transform.scale(self.image, (100, 100))
        self.rect = self.image.get_rect()
        screen = pygame.display.get_surface()
        self.area = screen.get_rect()
        self.rect.topleft = 10, height
        self.move = 15
        self.rotate = 0

    def update(self):
        "walk or spin, depending on the targets state"
        if self.rotate:
            self._spin()
        else:
            self._walk()

    def _walk(self):
        "move the target across the screen, and turn at the ends"
        newpos = self.rect.move((self.move, 0))
        if self.rect.left < self.area.left or self.rect.right > self.area.right:
            self.move = -self.move
            newpos = self.rect.move((self.move, 0))
            self.image = pygame.transform.flip(self.image, 1, 0)
        self.rect = newpos

    def _spin(self):
        "spin the target"
        center = self.rect.center
        self.rotate = self.rotate + 12
        if self.rotate >= 360:
            self.rotate = 0
            self.image = self.original
        else:
            rotate = pygame.transform.rotate
            self.image = rotate(self.original, self.rotate)
        self.rect = self.image.get_rect(center=center)

    def shot(self):
        "this will cause the target to start spinning"
        if not self.rotate:
            self.rotate = 1
            self.original = self.image

class Smiley(pygame.sprite.Sprite):
    """target moves across the screen. """

    def __init__(self, height):
        pygame.sprite.Sprite.__init__(self)  # call Sprite intializer
        self.image = pygame.image.load('data/smiley.png')
        self.image = pygame.transform.scale(self.image, (100, 100))
        self.rect = self.image.get_rect()
        screen = pygame.display.get_surface()
        self.area = screen.get_rect()
        self.rect.topleft = 10, height
        self.collideRect = pygame.rect.Rect((0, 0), (50, 50))
        self.move = 2
        self.rotate = 0

    def update(self):
        "walk or spin, depending on the targets state"
        if self.rotate:
            self._spin()
        else:
            self._walk()
            self.collideRect.midbottom = self.rect.midbottom

    def _walk(self):
        "move the target across the screen, and turn at the ends"
        newpos = self.rect.move((self.move, 0))
        if self.rect.left < self.area.left or self.rect.right > self.area.right:
            self.move = -self.move
            newpos = self.rect.move((self.move, 0))
            self.image = pygame.transform.flip(self.image, 1, 0)
        self.rect = newpos

    def _spin(self):
        "spin the target"
        center = self.rect.center
        self.rotate = self.rotate + 12
        if self.rotate >= 360:
            self.rotate = 0
            self.image = self.original
        else:
            rotate = pygame.transform.rotate
            self.image = rotate(self.original, self.rotate)
        self.rect = self.image.get_rect(center=center)

    def shot(self):
        "this will cause the target to start spinning"
        if not self.rotate:
            self.rotate = 1
            self.original = self.image
