
#####################################################################
### Assignment skeleton
### You can alter the below code to make your own dynamic website.
### The landing page for assignment 3 should be at /
#####################################################################
import csv

items = []
with open("minecraftitemlist.csv") as input_file:
    for row in csv.reader(input_file):
        items = items + [row]


from bottle import route, run, default_app, debug, request, static_file


def imgW():
    return static_file('wood.png',root='./')

def imgC():
    return static_file('creeper.jpg',root='./')

def imgH():
    return static_file('hearth.png',root='./')

def imgD():
    return static_file('dirt.png',root='./')

def imgB():
    return static_file('bg.png',root='./')

def css():
    return static_file('stylesheetN.css',root='./')

def kickout(text):
    page = """
        <!doctype html>
        <html lang="en">
            <head>
                <meta charset="utf-8" />
                <title>YOU ARE KICKED</title>
                <style>
                body {background-color:black;}
                h1 {color:white;text-align:center;padding-top:100px;}
                </style>
            </head>
            <body>
            <h1>%s</h1>
            </body>
        </html>
    """%(text)
    return page

def htmlify(title,text,text2):
    page = """
        <!doctype html>
        <html lang="en">
            <head>
                <meta charset="utf-8" />
                <title>%s</title>
                <link rel="stylesheet" type="text/css" href="/css">
            </head>
            <body>
            		<div class="header">
			<h1>Minecraft Item List</h1>
		</div>
    
    <div class="row">
       	
		<div class="column">
			<p>Search by:</p>
			<form action="/search" method="get">
				<input type="text" name="search" />
				<input type="submit" value="Search" />
        </form>
        <form action="/sort" method="get">
            <select name="sort">
                <option value="default">All</option>
                <option value="wood">Woods</option>
                <option value="wool">Wools</option>
                <option value="potion">Potions</option>
                <option value="flower">Flowers</option>
                <input type="submit" value="Apply" />
            </select>
        </form>
		</div>
    <div class="column">
        %s
    </div>
    <div class="column">
    <p style="background-color:black;text-align:center;"> Do you love minecraft ? </p>
    <form action="/survey" method="post" style="color:white;">
        <input type="radio" name="selected" value="yes">I love MINECRAFT!<br>
        <input type="radio" name="selected" value="no">It is a kind of child game..<br>
        <input type="radio" name="selected" value="gray">Who cares minecraft?
        <input type="submit" value="Apply" />
    </form>
    %s
    </div>
</div>
</body>
</html>""" % (title,text,text2)
    return page

def surveyFunc():
    page= """<div id="table-wrapper"><div id="table-scroll"><table><thead>"""
    for i in range(0,3):
        th = str(items[0][i])
        page += """<th><span class="forth">%s</span></th>"""%(th)
        i += 1
    page += """</thead>"""
    for i in range(1,len(items)):
        page += """<tbody>"""
        for y in range (0,3):
            tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
            page += """%s"""%(tr)
            y += 1
        page += """</tbody>"""
        i += 1
    page += """</table></div></div>"""
    
    if 'selected' in request.POST:
        selected = request.POST['selected']
        if selected == 'yes':
            img ="""<img src="/hg" alt="hearth" height="400" width="400">"""
            return htmlify("ITS GOOD",page,img)  
        elif selected == 'no':
            img ="""<img src="/cg" alt="creeper" height="400" width="400">"""
            return htmlify("ITS BAD",page,img)  
        elif selected == 'gray':
            return kickout("HERE WE DONT LOVE COOL GUYS")
            
  
    
def tableCREATOR():
    page= """<div id="table-wrapper"><div id="table-scroll"><table><thead>"""
    for i in range(0,3):
        th = str(items[0][i])
        page += """<th><span class="forth">%s</span></th>"""%(th)
        i += 1
    page += """</thead>"""
    for i in range(1,len(items)):
        page += """<tbody>"""
        for y in range (0,3):
            tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
            page += """%s"""%(tr)
            y += 1
        page += """</tbody>"""
        i += 1
    page += """</table></div></div>"""
    return htmlify("Homepage",page,"")
 
def sortFunc():
    html = """
   <div id="table-wrapper"><div id="table-scroll"><table><thead>
    """
    for i in range(0,3):
        th = str(items[0][i])
        html += """<th><span class="forth">%s</span></th>"""%(th)
        i += 1
    html += """</thead>"""
    
    if 'sort' in request.GET:
        sort = request.GET['sort']
        if sort == 'wood':
            for i in range(36,52):
                html += """<tbody>"""
                for y in range (0,3):
                    tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
                    html += """%s"""%(tr)
                    y += 1  
                html += """</tbody>"""
            i += 1
        elif sort == 'default':
            for i in range(1,len(items)):
                html += """<tbody>"""
                for y in range (0,3):
                    tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
                    html += """%s"""%(tr)
                    y += 1   
                html += """</tbody>"""
                i += 1
        elif sort == 'wool':
            for i in range(76,92):
                html += """<tbody>"""
                for y in range (0,3):
                    tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
                    html += """%s"""%(tr)
                    y += 1  
                html += """</tbody>"""
            i += 1
        elif sort == 'flower':
            for i in range(94,105):
                html += """<tbody>"""
                for y in range (0,3):
                    tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
                    html += """%s"""%(tr)
                    y += 1  
                html += """</tbody>"""
            i += 1
        elif sort == 'potion':
            for i in range(491,517):
                html += """<tbody>"""
                for y in range (0,3):
                    tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
                    html += """%s"""%(tr)
                    y += 1  
                html += """</tbody>"""
            i += 1     
    html += """</div></div></table>""" 
    html += """</tbody></div></div></table>"""
    
    return htmlify("Sorted List",html,"")

def searchFunc():
    html = """
   <div id="table-wrapper"><div id="table-scroll"><table><thead>
    """

    if 'search' in request.GET:
        search = request.GET['search']
    else:
        search = '' 
    
    for i in range(0,3):
        th = str(items[0][i])
        html += """<th><span class="forth">%s</span></th>"""%(th)
        i += 1
    html += """</thead>"""
    
    for i in range(1,len(items)):
        html += """<tbody>"""
        if search == '':
            for y in range (0,3):
                tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
                html += """%s"""%(tr)
                y += 1
        elif search in str(items[i]):
            for y in range (0,3):
                tr = """<td class="fortd">%s</td>"""%(str(items[i][y]))
                html += """%s"""%(tr)
                y += 1       
        html += """</tbody>"""
        i += 1
    html += """</div></div></table>"""
    
    
    html += """</tbody></div></div></table>"""
    
    return htmlify("Item List",html,"")

route('/search','GET',searchFunc)
route('/sort','GET',sortFunc)
route('/survey','POST',surveyFunc)
route('/dg','GET',imgD)
route('/cg','GET',imgC)
route('/wg','GET',imgW)
route('/hg','GET',imgH)
route('/bg','GET',imgB)
route('/css','GET',css)
route('/','GET',tableCREATOR)

#####################################################################
### Don't alter the below code.
### It allows this website to be hosted on Heroku
### OR run on your computer.
#####################################################################

# This line makes bottle give nicer error messages
debug(True)
# This line is necessary for running on Heroku
app = default_app()
# The below code is necessary for running this bottle app standalone on your computer.
if __name__ == "__main__":
  run()

