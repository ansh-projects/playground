
# import re
# s = raw_input("insert team name: ")
# if (re.search("^([A-za-z_]{1,8})$", s)):
#     print "team name \"", s, "\" works"
# else:
#     print "\"", s, "\"", " is an invalid team name"

import re

def parse_date(s):
	m = re.search('([a-zA-Z]+) ([0-9]+), ([0-9]+)', s)

	if m:
		if m.group(1) in month_number:
			return [
				int(m.group(2)),
				month_number[m.group(1)],

				int(m.group(3))
			]
		else:
			return [0,0,0]

	m = re.search('([0-9]+) ([a-zA-Z]+) ([0-9]+)', s)
	if m:
		if m.group(2) in month_number:
			return [
				int(m.group(1)),
				month_number[m.group(2)],
				int(m.group(3))
			]
		else:
			return [0,0,0]

	m = re.search('([0-9]+)/([0-9]+)/([0-9]+)', s)
	if m:
		return [
			int(m.group(1)),
			int(m.group(2)),
			int(m.group(3))
		]

	return [0,0,0]

month_number = {
	'January':1, 'February':2, 'March':3,
	'April':4, 'May':5, 'June':6,
	'July':7, 'August':8, 'September':9,
	'October':10, 'November':11, 'December':12
}

x = parse_date('5 july 2011')
print x[0]
print x[1]
print x[2]
