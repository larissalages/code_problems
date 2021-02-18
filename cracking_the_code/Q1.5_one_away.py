# O(n) time

def one_edit_away(str1, str2):
    if abs(len(str1) - len(str2)) > 1:
        return False
    else:  # make str1 be always the longest
        if str2 > str1:
            tmp = str2
            str2 = str1
            str1 = str2
        i = j = 0
        diff = False
        while i < len(str1) and j < len(str2):
            c1 = str1[i]
            c2 = str2[j]
            if c1 == c2:
                i += 1
                j += 1
            else:
                if diff is True:
                    return False
                diff = True
                if len(str1) == len(str2):
                    i += 1
                    j += 1
                else:
                    i += 1
        return True


if __name__ == '__main__':
    print(one_edit_away('pale', 'ple'))
    print(one_edit_away('pale', 'bae'))
