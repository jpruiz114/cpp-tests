import itertools

p = itertools.permutations([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0])

def is_66(a):
	result = (a[0] + 13 * a[1] / a[2] + a[3] + 12 * a[4] - a[5] - 11 + a[6] * a[7] / a[8] - 10)
	
	# handle the floats correctly, i.e. result == 66.00 will exclude some solutions
	return (result > 65.99) and (result < 66.01)

solution_counter = 0;

for a in p:
	if(is_66(a)):
		print(a);
		solution_counter += 1;

print("number of solutions %d" % solution_counter);

exit();