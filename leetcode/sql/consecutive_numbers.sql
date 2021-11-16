SELECT DISTINCT L1.num as ConsecutiveNums
FROM
Logs L1,
Logs L2,
Logs L3
WHERE 
    L1.id = L2.id -1
AND L2.id = L3.id -1
AND L1.num = L2.num
AND L3.num = L2.num;

# OR

SELECT DISTINCT num as ConsecutiveNums
FROM Logs
WHERE (Id+1, num) in (select * from Logs) and (Id+2, num) in (select * from Logs);

# Not really too much time difference between the two queries
