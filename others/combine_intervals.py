"""
4. [15 mins]  Given two lists of integer intervals, write a function that merges them into a single list of sorted intervals. Any overlapping intervals should be merged into a single interval.

You can assume the first element of an interval is always <= the second element of the 
interval.

For example, the two following lists of intervals:

[ [15, 25], [40, 60] ]
[ [10, 20], [50, 70], [80, 90] ]

Should combine to:

[ [10, 25], [40, 70], [80, 90] ]
"""

def combine_lists(big_list, small_list):
    list_intvls = []
    for i in range(len(small_list)):
        tmp_list = []
        if small_list[i][0] < big_list[i][0]:
            tmp_list.append(small_list[i][0])
        else:
            tmp_list.append(big_list[i][0])
        if small_list[i][1] > big_list[i][1]:
            tmp_list.append(small_list[i][1])
        else:
            tmp_list.append(big_list[i][1])
        list_intvls.append(tmp_list)
    
    if len(big_list) != len(small_list): 
        list_intvls += big_list[i+1:]

    return list_intvls

        
def combine_intervals(x, y):
    if len(x) > len(y):
        return combine_lists(x, y)
    else:
        return combine_lists(y, x)

def merge_intervals(intervals1, intervals2):
    print("merge_intervals")
    # combine the two lists of intervals
    intervals = intervals1 + intervals2

    # sort the intervals by their start values
    intervals.sort(key=lambda x: x[0])
    print(intervals)

    # merge any overlapping intervals
    merged = []
    for interval in intervals:
        if not merged or interval[0] > merged[-1][1]:
            if merged:
                print('it')
                print(interval[0])
                print(merged[-1][1])
            merged.append(interval)
        else:
            merged[-1] = [merged[-1][0], max(merged[-1][1], interval[1])]
        print("merged: "+str(merged)+"\n")

    return merged
######################################################
####################### main ######################
x = [[15,25],[40,60]]
y = [[10,20],[50,70],[80,90]]

print(combine_intervals(x, y))

a = [[1,2]]
b = [[4,5]]
print(combine_intervals(a, b))

print(merge_intervals(x,y))
