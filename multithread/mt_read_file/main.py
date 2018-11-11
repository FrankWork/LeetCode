def count_lines(fin_name):
	n_words=0
	n_lines=0
	
	with open(fin_name) as f:
		for line in f:
			n_lines+=1
			for w in line.split():
				n_words+=1
	print("nLines %d nWords %d" %(n_lines, n_words))

def copy_lines(fin_name, fout_name):
	n_lines=0
	
	fout = open(fout_name, 'w')
	with open(fin_name) as fin:
		for line in fin:
			n_lines += 1
			fout.write(line)
	fout.close()
	print('nLines %d'%n_lines)

#fin_name = 'wiki2.txt'
fin_name = 'wiki103.txt'
fout_name = 'wiki.copy'

#count_lines(fin_name)
copy_lines(fin_name, fout_name)
