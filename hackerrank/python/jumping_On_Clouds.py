def main():
    #test case, the answer must be 4
    c = [ 0, 0, 1, 0, 0, 1, 0 ]

    print(jumpingOnClouds(c))

    return 

def jumpingOnClouds(c):

    # Counting the jumps
    jumps = 0
    i = 0

    while (i < len(c) - 1):
        if i == len(c) - 1:
            break
        elif c[i+2] == 0: # if there is a zero two indix away, you can jump
            jumps += 1
            i += 1        # You are skipping one index 
        else:
            jumps += 1
        
        i += 1            # Each turn you go to the next index
    
    return jumps
    
main()