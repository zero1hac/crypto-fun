from collections import Counter
import operator

alphamap = {'a': 0, 'c': 2, 'b': 1, 'e': 4, 'd': 3, 'g': 6, 'f': 5, 'i': 8, 'h': 7, 'k': 10, 'j': 9, 'm': 12, 'l': 11, 'o': 14, 'n': 13, 'q': 16, 'p': 15, 's': 18, 'r': 17, 'u': 20, 't': 19, 'w': 22, 'v': 21, 'y': 24, 'x': 23, 'z': 25}
reversemap = {0: 'a', 1: 'b', 2: 'c', 3: 'd', 4: 'e', 5: 'f', 6: 'g', 7: 'h', 8: 'i', 9: 'j', 10: 'k', 11: 'l', 12: 'm', 13: 'n', 14: 'o', 15: 'p', 16: 'q', 17: 'r', 18: 's', 19: 't', 20: 'u', 21: 'v', 22: 'w', 23: 'x', 24: 'y', 25: 'z'}


def count_freq(string):
	return dict(Counter(string))


def max_freq_key(dict_key):
	return max(dict_key.iteritems(), key=operator.itemgetter(1))[0]


def determine_key(c, m):
	return (alphamap[c] - alphamap[m] + 26)%26


def return_message(c, k):
	return ''.join([reversemap[(alphamap[i] - k+26)%26] for i in c])



if __name__=="__main__":
	print "Enter encrypted text"
	raw_cipher = raw_input().strip()
	freq_letter = count_freq(raw_cipher)
	max_freq_letter_order = ['e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'd', 'l', 'u', 'c', 'm', 'f', 'y', 'w', 'g']
	len_max_freq_list = len(max_freq_letter_order)
	i = 0
	cl = max_freq_key(freq_letter)
	while i<len_max_freq_list:
		ml = max_freq_letter_order[i]
		possible_key = determine_key(cl, ml)
		print "possible key", possible_key
		print "message decrypted", return_message(raw_cipher, possible_key)
		i+=1

