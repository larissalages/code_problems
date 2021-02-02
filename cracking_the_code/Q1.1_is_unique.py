ALPHLEN = 128


def is_unique(string):
    if len(string) > ALPHLEN:
        return False
    else:
        alph = [0 for x in range(ALPHLEN)]
        for c in string:
            if alph[ord(c)] == 1:
                return False
            else:
                alph[ord(c)] = 1
        return True


if __name__ == '__main__':
    res1 = is_unique('Larissa')
    res2 = is_unique('train')
    res3 = is_unique('Bolsonaro is the worst brazilian president')
    res4 = is_unique('phone')
    
    print(res4)


