import sys
import sqlite3

db_name = 'produce.db'
if len(sys.argv) > 1 :
    db_name = sys.argv[1]

conn = sqlite3.connect(db_name)
c=conn.cursor()

c.execute("SELECT regionid FROM regions WHERE regions.name = 'California'")
cali_id = c.fetchone()[0]
print("CALI:",cali_id)
c.execute("SELECT produceid FROM data WHERE data.regionid = ?", (cali_id, ))
cali_produce = c.fetchall()
print(len(cali_produce),cali_produce)

c.execute("SELECT produceid FROM produces WHERE produces.name = 'Asparagus'")
asparagus_id = c.fetchone()[0]
print("Asparagus: ", asparagus_id)
#x.execute("SELECT 

conn.close
