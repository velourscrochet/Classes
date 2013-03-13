import math
import random

#Initialize variables
failedit = 0
xN = []
testN=[]
testYn=[]
testPointX = []
testPointY = []
wX=[]
wY=[]
sampleYn = 0
truth = 0
score = 0
it = 0

TOOMANY = 20000
N = 10 #number of points in a sample
POINTS = 10000 #number of points on the plane
iterations = 1000 #number of test cases

#Set a target line, f
f1 = (random.uniform(-1,1),random.uniform(-1,1))
f2 = (random.uniform(-1,1),random.uniform(-1,1))
deltaF = (f1[1]-f2[1])/(f1[0]-f2[0])

#Set random points, xN
for i in range(0,(POINTS*3)-1):
	xN.append(random.uniform(-10,10))

#For [Iterations] times, pick [N] points, (x,y)
f1 = (random.uniform(-1,1),random.uniform(-1,1))
f2 = (random.uniform(-1,1),random.uniform(-1,1))
deltaF = (f1[1]-f2[1])/(f1[0]-f2[0])

for foo in range(0,iterations):
	xN = []
	for i in range(0,(POINTS*3)-1):
	        xN.append(random.uniform(-10,10))


	it +=1
	testYn = []
	runs = 0
	for bar in range(0,N*10):
		testN.append(random.randint(0,(POINTS*2)))
	#Determine their yN
	for baz in range(0,N):
		testPointX.append(xN[testN[baz*2]])
		testPointY.append(xN[testN[baz*2+1]])
	for a in range(0,N):
		if testPointY[a] >= (deltaF * (testPointX[a] - f1[0]) + f1[1]):
			testYn.append(-1)
		else:
			testYn.append(1)
	print testYn
	#set weights to zero
	for b in range(0,N*2):
		wX.append(0)
		wY.append(0)
	truth = 0
	while truth != N:
		dot = 0

		for b in range(0,N-1):
			if (truth < N):

				#find dot product
				dot+=wX[b]*testPointX[b] + wY[b] * testPointY[b]
				print dot			
				if ((dot < 0) and (testYn[b] == -1)):
					print dot, testYn[b]
					truth += 1
                	                print "truth = ",truth, " N = ",N, " runs = ", runs," b = ",b

				elif ((dot > 0) and (testYn[b] == 1)):
					print dot, testYn[b]
					truth +=1
					print "truth = ",truth, " N = ",N, " runs = ", runs," b = ",b
				else:
					print "dot fail", "runs = ",runs
				
					print "runs = ",runs
					wX[b] += testYn[b]*testPointX[b]
					wY[b] += testYn[b]*testPointY[b]
					runs +=1
				
	        	       	        print "WUB WUB WUB WUB WUB WUB WUB truth = ",truth, " N = ",N, " runs = ", runs," b = ",b," it = ",it
					pass
		

		if truth < N-1:
			truth = 0
		if runs == TOOMANY:
			failedit += failedit
	print "truth = ",truth
	score += runs
	runs = 0
	print "score = ", score
	print "it = ",it
	print "failedit = ", failedit

AVG = score / (iterations - failedit)
print "score = ",score," iterations = ",it," failedit ",failedit

print "AVG = ", AVG

