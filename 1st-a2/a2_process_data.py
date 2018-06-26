#######################################################
### Please ignore the lines of code in this section.
### It loads the contents of a CSV file for you.
### The file's name should be a2_input.csv.
### You do not need to know how it works.
#######################################################

import csv

contents = []
with open("a2_input.csv") as input_file:
    for row in csv.reader(input_file):
        contents = contents + [row]

#######################################################
### Do your data processing below.
### The below code gives some examples
### of how to access the data.
### Print your results using the print function.
#######################################################
 
def firstPLACE():
    global firstSums
    firstSum = 0
    for i in range (1,17):
        if contents[i][8] == '1.':
            firstSum += 1
    firstSums = str(firstSum)
firstPLACE()

def polAVERAGE():
    global polSums
    polSum = 0
    for i in range (1,17):
        polSum += int(contents[i][5])
    polSums = str(polSum)
polAVERAGE()

def pointAVERAGE():
    global pointAVRs
    pointSum = 0
    for i in range (1,17):
        pointSum += int(contents[i][7])
    pointAVR = int(pointSum) / (len(contents) - 1)
    pointAVRs = str(pointAVR)
pointAVERAGE()

def sumRACES():
    global raceSums
    raceSum = 0
    for i in range (1,17):
        raceSum += int(contents[i][4])
    raceSums = str(raceSum)
sumRACES()    

def asideWRITE(x,y,z,t,k):
    paragraph = """ <aside> %s <br> <cont>%s <br> %s <br> %s <br> %s</cont> </aside> """%(x,y,z,t,k)
    print(paragraph)
    
def pWRITE(x):
    paragraph = """ <p> %s </p> """%(x)
    print(paragraph)
def h3WRITE(x):
    h3 = """ <h3> %s </h3> """%(x)
    print(h3)

def tableCREATOR():
    print("""<table>""")
    print("<tr>")
    for i in range(0,9):
        th = str(contents[0][i])
        print("<th>" + th + "</th>")
        i += 1
    print("</tr>")

    for i in range(1,19):
        print('<tr>');
        for y in range (0,9):
            tr = "<td>" + str(contents[i][y]) + "</td>"
            print(tr)
            y += 1
        print('</tr>');
        i += 1
    print("""</table>""")

longP = """Looking at the statistics, it is not wrong to say that Lewis Hamilton 
is the most successful Formula 1 pilot in the last 10 years."""
longP2 = """He has competed """ + str(contents[17][4]) + """ and he has earned avarege
of """ + str(contents[18][7]) +""".He has got the title of first place """+firstSums+""" times."""
sentences = ['The sum of race Lewis Hamilton won first place: ',
             'The sum of sort tour Lewis Hamilton won first place: ',
             'The average of point Lewis Hamilton earned by year: ',
             'The sum of race Lewis Hamilton competed: ',
             longP,
             '<img src="hamilton.jpg" alt="hamilton" height="296" width="382">',
             longP2,
             ]       

def htmlMaker(x,y):
    htmlUP = """
    <!DOCTYPE html>
    <html>
        <head>
            <title>%s</title>
            <style>
                cont{
                display: block;
                margin-top: 5px;
                border-radius: 10px;
                background:#00cc99;
                }
                table{
                border-collapse: collapse;
                text-align:center;
                }
                td{
                border: 1px solid #80bfff;
                background: #3399ff;
                }
                th{
                border: 1px solid #ffb366;
                background: #ff9933;
                }
                section{
                float: right;
                text-align: center;
                }
                p{
                text-align: left;
                text-indent: 20px;
                }
                aside {
                background: #2db34a;
                border-radius: 15px;
                padding: 10px;
                margin-left: 15px;
                margin-top: 60px;
                float: left;
                text-align: left;
                }
                h1{
                text-align: center;
                }
                article{
                float:left;
                }
                h3{
                text-indent:20px;
                }
            </style>
        </head>
        <body>
            <h1>%s</h1>"""%(x,y)
            
    htmlDOWN = """     
            </body>
    </html>"""
    print(htmlUP)
    print('<section>')
    h3WRITE('Race Results According To Seasons')
    tableCREATOR()
    print('</section>')
    asideWRITE(sentences[5],sentences[0] + firstSums,sentences[1] + polSums,sentences[2] + pointAVRs,sentences[3] + raceSums)
    print('<article>')
    h3WRITE('The Great Lewis')
    pWRITE(sentences[6])
    pWRITE(sentences[4])
    print('</article>')
    print(htmlDOWN)
    

htmlMaker('Year By Year Lewis Hamilton',"Lewis Hamilton's Statistics")




