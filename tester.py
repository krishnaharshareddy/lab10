import sys
import os

fx=open('output.csv','w')
fx.close()
for i in range(1,20):
	m=2**i;
	for j in range(1,10):
		os.system("sh -c 'echo 1 >/proc/sys/vm/drop_caches'")
		print ("Dropped Cache")
		os.system("./a.out "+str(m)+" "+str(i)+" >output")
		print ("Running Prog")
		f=open('output','r')
		x=f.read()
		f.close()
		f1=open('output.csv','a')
		f1.write(x+"\n")
		f1.close()


mintimes=[1000.0]*21
totaltime=[0.0]*21

import csv
with open('output.csv','r') as csvfile:
	f = csv.reader(csvfile,delimiter=",")
	for row in f:
		if(len(row)>1):
			totaltime[int(row[0])]+=float(row[1])
			if (float(row[1]) < mintimes[int(row[0])] and float(row[1])>1):
				mintimes[int(row[0])]=float(row[1])


ff=open('totaltime.csv','w')			
for i in range(1,21):
	ff.write(str(i) + "," + str(totaltime[i])+"\n")
	print str(i) + " " + str(totaltime[i])
ff.close()


ff=open('mintime.csv','w')	
for i in range(1,21):
	ff.write(str(i) + "," + str(mintimes[i])+"\n")
	print str(i) + " " + str(mintimes[i])
ff.close()
