fin = open("IntegerArray.txt")
integers = [ ]
for line in fin:
    text = line.rstrip('\r\n')
    number = int(text)
    integers.append(number)


#for line in open( "TestIntegers.txt", "r" ).readlines():
#    for value in line.split( ' ' ):
#        integers.append( value )

#integers = [i.strip().split() for i in open("TestIntegers.txt").readlines()]

length = len(integers)
print length
j = 0
inversions = 0
print integers

while j<length:
	if integers[j] > (j+1):
		inversions += (integers[j] - (j+1))
#	if integers[j] == (j+1):
#		inversions += 1
	j+=1
	
print inversions
