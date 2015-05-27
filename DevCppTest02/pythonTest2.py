import itertools

p = itertools.permutations([1, 2, 3, 4, 5, 6, 7, 8, 9])

def is_66(a):
	result = (a[0] + 13 * a[1] / a[2] + a[3] + 12 * a[4] - a[5] - 11 + a[6] * a[7] / a[8] - 10)
	return (result == 66)

solution_counter = 0;

for a in p:
	if(is_66(a)):
		print(a);
		solution_counter += 1;

print("number of solutions %d" % solution_counter);

exit();