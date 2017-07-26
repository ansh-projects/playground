f = "C:\Program Files\EqualizerAPO\config\config.txt"
r = open(f, 'r')
lines = r.readlines()
r.close()
w = open(f, 'w')
if(len(lines) != 0):
    if lines[len(lines) - 1] == "Copy: L=R R=L":
        w.writelines([item for item in lines[:-1]])
        w.close()
        a = open(f, 'a')
        a.write("# Copy: L=R R=L")
    elif lines[len(lines) - 1] == "# Copy: L=R R=L":
        w.writelines([item for item in lines[:-1]])
        w.close()
        a = open(f, 'a')
        a.write("Copy: L=R R=L")
a.close()
