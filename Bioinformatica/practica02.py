#function to read fasta format  
def read_fasta(filename):
    sequence = ''
    with open(filename) as file:
        for line in file:
            if line.startswith('>'):
                continue
            sequence += line.strip()
    return sequence


#compute guanine and cytosine content in a sequence percentage
def guanine_cytosine_content(sequence):
    guanine_count = 0
    cytosine_count = 0
    for i in sequence:
        if i == 'G':
            guanine_count += 1
        elif i == 'C':
            cytosine_count += 1
    guanine_content = guanine_count/len(sequence)
    cytosine_content = cytosine_count/len(sequence)
    return (guanine_content+cytosine_content) * 100 


#compute the percentage of each nucleotide in a sequence
print(guanine_cytosine_content(read_fasta(r'Bioinformatica\sequence.fasta')))
