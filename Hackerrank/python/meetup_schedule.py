def countMeetings(firstDay, lastDay):
    intervals= []
    day_of_meeting = 0
    meetings = 0
    for i,j in zip(firstDay,lastDay):
        intervals.append((i,j))
    intervals = sorted(intervals)
    for start,end in intervals: 
        if end < day_of_meeting:
            continue
        meetings += 1
        day_of_meeting = max(day_of_meeting+1, start)
    return meetings