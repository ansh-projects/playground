# -*- coding: utf-8 -*-
import re
def check(toCheck):
    compiled = re.compile(ur'✔', re.UNICODE)
    m = compiled.search(toCheck)
    if(m):
        return 1
    else:
        return 0

check(u'sdas✔dfff')
s = 'testing✔'
check(s.decode('utf8'))
check('sad')
with open('text.txt') as f:
    lines = f.readlines()
lines = [x.strip() for x in lines]
lines.sort(key = lambda s: s.lower())
lines.sort(key = lambda s: check(s.decode('utf8')))
for x in lines:
    print x
