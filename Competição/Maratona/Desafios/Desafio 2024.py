import hashlib
import string

alfabeto_minusculo = list('0123456789' + string.ascii_lowercase)
per = [0, 0, 0, 0]
pos = [46, 56, 68, 72]
site = 'https://forms.layers.education/maratona-pos-c7*bfe8a4887*692?answ=f8*74a*'
hash_key = 'eaecfda1fe250291976b9350a27abd19'

def permutate_list(my_list, size):
    for i in range(len(my_list)):
        my_list[i] += 1
        if my_list[i] == size and i < len(my_list) - 1:
            my_list[i] = 0
        else:
            break
    return my_list

def compute_hash(my_string):
    m = hashlib.md5()
    m.update(my_string.encode('utf-8'))
    return m.hexdigest()

while (per[3] < len(alfabeto_minusculo)):
    per = permutate_list(per, len(alfabeto_minusculo))
    if (per[3] == len(alfabeto_minusculo)):
        break
    list_site = list(site)
    for i in range (len(pos)):
        list_site[pos[i]] = alfabeto_minusculo[per[i]]
    tmp_site = ''.join(list_site)
    if (compute_hash(tmp_site) == hash_key):
        print(tmp_site)
