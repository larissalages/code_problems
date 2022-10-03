# Hackerrank Utopian Tree with Python
def utopian_tree(period):
    # Initialize from zero
    tree_height = 0
    
    # Loop period + 1 times
    # If number is odd, it's summer then 2x times grow
    # If number is even, it's spring then 1+ grow
    for i in range(period + 1):
        if i % 2 == 0:
            tree_height = tree_height + 1
        else:
            tree_height = tree_height * 2
            
    return tree_height


# Based on test case
# Tested 100% accepted on Hackerrank
test_case = int(input().strip())
for i in range(test_case):
    n = int(input().strip())
    print(utopian_tree(n))
