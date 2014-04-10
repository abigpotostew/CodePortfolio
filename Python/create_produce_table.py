import sys
import sqlite3

db_name = 'produce.db'
if len(sys.argv) > 1 :
    db_name = sys.argv[1]
    
conn = sqlite3.connect(db_name)
c=conn.cursor()

c.execute('''CREATE TABLE regions (regionid INTEGER PRIMARY KEY, name text UNIQUE)''')
c.execute('''CREATE TABLE produces (produceid INTEGER PRIMARY KEY, name text UNIQUE)''')
c.execute('''CREATE TABLE data (produceid INTEGER, regionid integer, start integer, end integer)''')

conn.commit()
print("finished creating database with 3 tables", db_name)
